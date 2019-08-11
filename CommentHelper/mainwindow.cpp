#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(WIN_TITLE);

    fileOpenDialog = nullptr;
    confQueue = nullptr;

    setFlagTable();
    setDescTable();
    setIssueTable();
    setReferenceTable();

}

void MainWindow::setDescTable(){
    ui->descTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->descTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setIssueTable(){
    ui->issueTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->issueTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setReferenceTable(){
    ui->referenceTbl->horizontalHeader()->setStretchLastSection(true);
    ui->referenceTbl->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setFlagTable(){

    ui->flagTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->flagTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // FlagTableWidget Setting
    insertItem(ui->flagTblWidget, false, "Author", "0");
    insertItem(ui->flagTblWidget, false, "Last_Edited", "0");
    insertItem(ui->flagTblWidget, false, "Desc", "0");
    insertItem(ui->flagTblWidget, false, "Issue", "0");
    insertItem(ui->flagTblWidget, false, "Sup_Div_Line", "0");
    insertItem(ui->flagTblWidget, false, "Sub_Div_Line", "0");
    insertItem(ui->flagTblWidget, false, "Email", "0");
    insertItem(ui->flagTblWidget, false, "Telephone", "0");
    insertItem(ui->flagTblWidget, false, "Github_Account", "0");
    insertItem(ui->flagTblWidget, false, "Ref_URLs", "0");

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
    return ui->pathEdit->text();
}

QString MainWindow::GetSeparator(){
    return ui->separatorEdit->text();
}

QString MainWindow::GetAuthor(){
    return ui->authorEdit->text();
}

QString MainWindow::GetTargetExtens(){
    return ui->extensionEdit->text();
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

void MainWindow::on_addReferenceBtn_clicked()
{
    insertItem(ui->referenceTbl, true, "fileName", "url");
}

void MainWindow::on_rmReferenceBtn_clicked()
{
    ui->referenceTbl->removeRow(ui->descTblWidget->currentRow());
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    if(index == TAB_PREVIEW){
        QString text;

        processFlag(text, ui->subDivEdit->toPlainText(), nullptr, FLAGPOS_SUPDIV);

        processFlag(text, "@ Author", ui->authorEdit->text(), FLAGPOS_AUTHOR);

        processFlag(text, "@ Last Edited", "<Date>", FLAGPOS_LASTEDITED);

        processFlag(text, "@ Desc", "<Desc>", FLAGPOS_DESC);

        processFlag(text, "@ Issue", "<Issue>", FLAGPOS_ISSUE);

        processFlag(text, "@ Email", ui->emailEdit->text(), FLAGPOS_EMAIL);

        processFlag(text, "@ Contact", ui->telepEdit->text(), FLAGPOS_TELEP);

        processFlag(text, "@ Github Account", ui->githubEdit->text(), FLAGPOS_GITHUBACC);

        processFlag(text, "@ Ref URLs", "<URLs>", FLAGPOS_REFURLS);

        processFlag(text, ui->subDivEdit->toPlainText(), nullptr, FLAGPOS_SUBDIV);

        ui->previewTextEdit->setPlainText(text);
    }
}

void MainWindow::processFlag(QString& str, const QString& key, const QString& value, int row, int col){

    if(key.trimmed() == "" || key == nullptr){
        return;
    }

    if(ui->flagTblWidget->item(row, col)->text() == "1"){

        if(value == nullptr){

            str += ui->separatorEdit->text() + key + "\n";
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
    system("start chrome /new-window https://github.com/jopemachine/CommentHelper");
}

void MainWindow::ShowMessageBox(const QString& message, const QString& title){
    QMessageBox a(this);
    a.setText(message);
    a.setFixedSize(400, 150);
    a.setWindowTitle(title);
    a.exec();
}

void MainWindow::on_actionSave_triggered()
{
    // 파일이 열려 있지 않을 땐 파일 저장 Dialog를 띄워 먼저 저장할 파일의 경로를 받아온다
    if(selectedFile == "") {

        selectedFile = QFileDialog::getSaveFileName(this,
                tr("Save setting file"), "",
                tr("Comment helper setting (*.chs);;All Files (*)"));

        setWindowTitle(selectedFile);
    }

    saveCHSFile(selectedFile);

}

void MainWindow::saveCHSFile(const QString& path){

    QFile selectFile(path);

    // 파일이 존재하지 않을 땐 경로에 파일을 생성한다.
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
            ts << "flag." << key << "   =   " << selectedCells[i]->text() << "\n";
        }
    }

    ts << "\n# Globals\n";

    ts << "global.Extension        =  " <<   ui->extensionEdit->text() << "\n";
    ts << "global.Project_Path     =  " <<   ui->pathEdit->text() << "\n";
    ts << "global.Author           =  " <<   ui->authorEdit->text() << "\n";
    ts << "global.Separator        =  " <<   ui->separatorEdit->text() << "\n";
    ts << "global.Sub_Div_Line     =  " <<   ui->subDivEdit->toPlainText() << "\n";
    ts << "global.Sup_Div_Line     =  " <<   ui->supDivEdit->toPlainText() << "\n";
    ts << "global.Email            =  " <<   ui->emailEdit->text() << "\n";
    ts << "global.Telephone        =  " <<   ui->telepEdit->text() << "\n";
    ts << "global.Github_Account   =  " <<   ui->githubEdit->text() << "\n";

    ts << "\n# Desc\n";


    bool existDuplicateKeys = false;

    for(int i = 0; i < ui->descTblWidget->rowCount(); i++){

        // 중복 키 값이 들어갈 수 없게 한다.
        auto dup = ui->descTblWidget->findItems(ui->descTblWidget->item(i, 0)->text(), Qt::MatchExactly);

        if(dup.length() != 1){
            existDuplicateKeys = true;
            continue;
        }

        ts << "desc." + ui->descTblWidget->item(i, 0)->text()
              + "  =  " + ui->descTblWidget->item(i, 1)->text() << "\n";
    }

    ts << "\n# Issue\n";

    for(int i = 0; i < ui->issueTblWidget->rowCount(); i++){

        auto dup = ui->issueTblWidget->findItems(ui->issueTblWidget->item(i, 0)->text(), Qt::MatchExactly);

        if(dup.length() != 1){
            existDuplicateKeys = true;
            continue;
        }

        ts << "issue." + ui->issueTblWidget->item(i, 0)->text()
              + "  =  " + ui->issueTblWidget->item(i, 1)->text() << "\n";
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < ui->referenceTbl->rowCount(); i++){

        // 중복 값 허용
        ts << "refURLs." + ui->referenceTbl->item(i, 0)->text()
              + "  =  " + ui->referenceTbl->item(i, 1)->text() << "\n";
    }

    selectedFile = path;

    selectFile.close();

    if(existDuplicateKeys){
        ShowMessageBox("There is duplicate keys in some tables. "
                       "\nGenerated setting file does not contained these records",
            "duplicate key error");
    }
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
    setWindowTitle(selectedFile);
}

void MainWindow::setCHSFile(std::queue<QString>& confToken){

    bool errFlag = false;

    while(!confToken.empty()){

        // 주석 및 빈줄은 생략
        if(confToken.front().trimmed() == "" || confToken.front().at(0) == "#"){
            confToken.pop();
            continue;
        }

        // Flag Setting

        QRegularExpression flagRe("flag[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto flagMatch = flagRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(flagMatch.hasMatch()){
            auto item = searchTable(ui->flagTblWidget, flagMatch.captured("attKey"));
            item->setText(flagMatch.captured("attValue"));
            confToken.pop();
            continue;
        }

        // Global Setting

        QRegularExpression globalRe("global[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto globalMatch = globalRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(globalMatch.hasMatch()){
            addGlobalVars(globalMatch.captured("attKey"), globalMatch.captured("attValue"));
            confToken.pop();
            continue;
        }

        // Desc Setting

        QRegularExpression descRe("desc[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto descMatch = descRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(descMatch.hasMatch()){
            insertItem(ui->descTblWidget, true, descMatch.captured("attKey"), descMatch.captured("attValue"));
            confToken.pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("issue[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto issueMatch = issueRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){
            insertItem(ui->issueTblWidget, true, issueMatch.captured("attKey"), issueMatch.captured("attValue"));
            confToken.pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("refURLs[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto refURLsMatch = refURLRe.match(confToken.front(), 0, QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){
            insertItem(ui->referenceTbl, true, refURLsMatch.captured("attKey"), refURLsMatch.captured("attValue"));
            confToken.pop();
            continue;
        }

        confToken.pop();

        errFlag = true;
    }

    if(errFlag){
        ShowMessageBox("Setting file could contain syntax error", "Caution");
    }

}

void MainWindow::addGlobalVars(const QString& key, const QString& value){

    if(key == "Extension"){
        ui->extensionEdit->setText(value);
        return;
    }
    if(key == "Project_Path"){
        ui->pathEdit     ->setText(value);
        return;
    }
    if(key == "Author"){
        ui->authorEdit   ->setText(value);
        return;
    }
    if(key == "Separator"){
        ui->separatorEdit->setText(value);
        return;
    }
    if(key == "Sub_Div_Line"){
        ui->subDivEdit  ->setText(value);
        return;
    }
    if(key == "Sup_Div_Line"){
        ui->supDivEdit  ->setText(value);
        return;
    }
    if(key == "Email"){
        ui->emailEdit   ->setText(value);
        return;
    }
    if(key == "Telephone"){
        ui->telepEdit   ->setText(value);
        return;
    }
    if(key == "Github_Account"){
        ui->githubEdit  ->setText(value);
        return;
    }

    qDebug() << "wrong Info included in addGlobalVars";
}

// key를 String input으로 받고 해당하는 row의 value item을 반환한다
QTableWidgetItem* MainWindow::searchTable(QTableWidget* table, const QString& key){
    for(int i = 0;  i < table->rowCount(); i++){
        if(table->item(i, 0)->text() == key){
            // qDebug() << table->item(i, 0)->text();
            return table->item(i, 1);
        }
    }
    return nullptr;
}

void MainWindow::on_actionExecute_triggered()
{
    if(ui->pathEdit->text().trimmed() == ""){
        ShowMessageBox("No directory include!", "No directory");
        return;
    }




}

void MainWindow::on_actionSave_as_triggered()
{
    selectedFile = QFileDialog::getSaveFileName(this,
            tr("save setting file"), "",
            tr("comment helper setting (*.chs);;All Files (*)"));

    setWindowTitle(selectedFile);

    saveCHSFile(selectedFile);
}

void MainWindow::on_copyBtn_clicked()
{

}

void MainWindow::on_executeBtn_clicked()
{

}
