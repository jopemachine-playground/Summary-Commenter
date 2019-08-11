#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"

#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(WIN_TITLE);

    projPathEdit = ui->pathEdit;
    targetExtensEdit = ui->extensionEdit;
    authorEdit = ui->authorEdit;
    separatorEdit = ui->separatorEdit;

    projPathEdit->setText("C:\\");
    targetExtensEdit->setText("cpp, h");
    authorEdit->setText("jopemachine");
    separatorEdit->setText("//");
    ui->subDivEdit->setText("----------------------------------------------------------------------------------------------");
    ui->supDivEdit->setText("----------------------------------------------------------------------------------------------");

    setFlagTable();
    setDescTable();
    setIssueTable();

}

void MainWindow::setDescTable(){
    ui->descTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->descTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setIssueTable(){
    ui->issueTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->issueTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setFlagTable(){

    ui->flagTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->flagTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // FlagTableWidget Setting
    insertItem(ui->flagTblWidget, false, "Author", "1");
    insertItem(ui->flagTblWidget, false, "Last_Edited", "1");
    insertItem(ui->flagTblWidget, false, "Desc", "1");
    insertItem(ui->flagTblWidget, false, "Issue", "1");
    insertItem(ui->flagTblWidget, false, "Sup_Div_Line", "1");
    insertItem(ui->flagTblWidget, false, "Sub_Div_Line", "1");
    insertItem(ui->flagTblWidget, false, "Email", "1");
    insertItem(ui->flagTblWidget, false, "Telephone", "1");


}

void MainWindow::insertItem(QTableWidget* tbl, bool keyEditable, const QString& key, const QString& value){

    int row = tbl->rowCount();
    tbl->insertRow(row);

    auto keyColumn = new QTableWidgetItem(key);
    auto valueColumn = new QTableWidgetItem(value);

    if(!keyEditable){
        keyColumn->setFlags(keyColumn->flags() & ~Qt::ItemIsEditable);
    }

    tbl->setItem(row, 0, keyColumn);
    tbl->setItem(row, 1, valueColumn);

}

QString MainWindow::GetProjPath(){
    return projPathEdit->text();
}

QString MainWindow::GetSeparator(){
    return separatorEdit->text();
}

QString MainWindow::GetAuthor(){
    return authorEdit->text();
}

QString MainWindow::GetTargetExtens(){
    return targetExtensEdit->text();
}

MainWindow::~MainWindow()
{
    delete ui;
    if(fileOpenDialog != nullptr){
        delete fileOpenDialog;
    }
    if(confQueue != nullptr){
        delete confQueue;
    }
}

void MainWindow::on_descAddBtn_clicked()
{
    insertItem(ui->descTblWidget, true, "fileName", "content");
}

void MainWindow::on_descRemoveBtn_clicked()
{
    ui->descTblWidget->removeRow(ui->descTblWidget->currentRow());
}

void MainWindow::on_issueAddBtn_clicked()
{
    insertItem(ui->issueTblWidget, true, "fileName", "content");
}

void MainWindow::on_issueRemoveBtn_clicked()
{
    ui->issueTblWidget->removeRow(ui->issueTblWidget->currentRow());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    if(index == TAB_PREVIEW){
        QString text;

        processFlag(text, ui->supDivEdit->text(), nullptr, FLAGPOS_SUPDIV);

        processFlag(text, "@ Author", ui->authorEdit->text(), FLAGPOS_AUTHOR);

        processFlag(text, "@ Last Edited", "<Date>", FLAGPOS_LASTEDITED);

        processFlag(text, "@ Desc", "<Desc>", FLAGPOS_DESC);

        processFlag(text, "@ Issue", "<Issue>", FLAGPOS_ISSUE);

        processFlag(text, "@ Email", ui->emailEdit->text(), FLAGPOS_EMAIL);

        processFlag(text, "@ Contact", ui->telepEdit->text(), FLAGPOS_TELEP);

        processFlag(text, ui->subDivEdit->text(), nullptr, FLAGPOS_SUBDIV);

        ui->previewTextEdit->setPlainText(text);
    }
}

void MainWindow::processFlag(QString& str, const QString& key, const QString& value, int row, int col){

    if(ui->flagTblWidget->item(row, col)->text() == "1"){

        if(value == nullptr){

            str += ui->separatorEdit->text() + " " + key + "\n";
            return;
        }

        str += ui->separatorEdit->text() + " " + key + " : " + value + "\n";
    }
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionGithub_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{
    // 파일이 열려 있지 않을 땐 행동하지 않음
    if(selectedFile == "") return;

    QFile selectFile(selectedFile);

    // 파일이 존재하지 않을 때
    if(!selectFile.exists()) return;

    selectFile.open(QFile::WriteOnly|QFile::Text);

    QTextStream ts(&selectFile);

    ts << CSH_START_COMMENT << "\n";

    ts << "\n# Flags\n";

    ui->flagTblWidget->selectAll();
    QList<QTableWidgetItem *> selectedCells = ui->flagTblWidget->selectedItems();

    QString key;
    for(int i = 0; i < selectedCells.length(); i++){
        // Key
        if(i % 2 == 0){
            key = selectedCells[i]->text();
        }
        // Value
        else {
            if(selectedCells[i]->text() == "1"){
                ts << "flag     +=      " << key << "\n";
            }
        }
    }

    ts << "\n# Globals\n";

    ts << "global.Extension        =  " <<   ui->extensionEdit->text() << "\n";
    ts << "global.Project Path     =  " <<   ui->pathEdit->text() << "\n";
    ts << "global.Author           =  " <<   ui->authorEdit->text() << "\n";
    ts << "global.Separator        =  " <<   ui->separatorEdit->text() << "\n";
    ts << "global.Sub_Div_Line     =  " <<   ui->subDivEdit->text() << "\n";
    ts << "global.Sup_Div_Line     =  " <<   ui->supDivEdit->text() << "\n";
    ts << "global.Email            =  " <<   ui->emailEdit->text() << "\n";
    ts << "global.Telephone        =  " <<   ui->telepEdit->text() << "\n";

    ts << "\n# Desc\n";

    ts << "\n# Issue\n";

    selectFile.close();
}

void MainWindow::on_actionOpen_triggered()
{
    // FileDialog를 생성하고 연다.

    confQueue = new std::queue<QString>;

    fileOpenDialog = new QFileDialog();
    fileOpenDialog->setFileMode(QFileDialog::AnyFile);
    fileOpenDialog->setNameFilter(tr("Open a Setting file (*.chs)"));
    fileOpenDialog->setViewMode(QFileDialog::Detail);
    fileOpenDialog->open(this, "Open a Setting file");

    // 파일을 선택했을 때
    if(fileOpenDialog->exec()){

        selectedFile = fileOpenDialog->selectedFiles()[0];

        QFile selectFile(selectedFile);

        if(selectFile.exists())
        {
            selectFile.open(QFile::ReadOnly|QFile::Text);

            QTextStream ts(&selectFile);

            while(!ts.atEnd())
            {
                confQueue->push(ts.readLine());
            }
        }

        selectFile.close();
    }

    setCHSFile(*confQueue);
}

void MainWindow::setCHSFile(std::queue<QString>& confToken){

    while(!confToken.empty()){

        // 주석 및 빈줄은 생략
        if(confToken.front() == "" || confToken.front().at(0) == "#"){
            confToken.pop();
            continue;
        }

        // qDebug() << confToken.front();

        // Flag Setting
        QRegularExpression flagRe("flag\\s+[+][=]\\s+(?<activateFlag>\\w+)");

        auto flagMatch = flagRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(flagMatch.hasMatch()){

            qDebug() << flagMatch.captured("activateFlag");
        }

        // Global Setting

        QRegularExpression globalRe("global[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto globalMatch = globalRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(globalMatch.hasMatch()){

            qDebug() << globalMatch.captured("attKey");
            qDebug() << globalMatch.captured("attValue");
        }

        confToken.pop();
    }

}

void MainWindow::on_actionExecute_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{

}
