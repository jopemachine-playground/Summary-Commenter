#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"

#include <QFile>
#include <QDebug>
#include <QFileDialog>

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
    insertItem(ui->flagTblWidget, false, "Last Edited", "1");
    insertItem(ui->flagTblWidget, false, "Desc", "1");
    insertItem(ui->flagTblWidget, false, "Issue", "1");
    insertItem(ui->flagTblWidget, false, "Sup Div Line", "1");
    insertItem(ui->flagTblWidget, false, "Sub Div Line", "1");
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

}

void MainWindow::on_actionOpen_triggered()
{
    // FileDialog를 생성하고 연다.
    fileOpenDialog = new QFileDialog();
    fileOpenDialog->setFileMode(QFileDialog::AnyFile);
    fileOpenDialog->setNameFilter(tr("Open a Setting file (*.chs)"));
    fileOpenDialog->setViewMode(QFileDialog::Detail);
    fileOpenDialog->open(this, "Open a Setting file");

    QString config;

    // 파일을 선택했을 때
    if(fileOpenDialog->exec()){

        QFile selectFile(fileOpenDialog->selectedFiles()[0]);

        if(selectFile.exists())
        {
            selectFile.open(QFile::ReadOnly|QFile::Text);

            QTextStream ts(&selectFile);

            while(!ts.atEnd())
            {
                config = ts.readLine();
            }
        }

        selectFile.close();
    }

    qDebug() << config;
}

void MainWindow::on_actionExecute_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{

}
