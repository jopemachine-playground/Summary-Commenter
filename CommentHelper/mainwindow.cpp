// ==============================+===============================================================
// Import

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDirIterator>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"


// ==============================+===============================================================
// Public Method

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(WIN_TITLE);

    chLately = new QFile(QDir::currentPath() + "\\" + "chlately");

    pathQue = new std::deque<QString>();

    QString latest = nullptr;

    setFlagTable();

    ui->descTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->descTblWidget->setSelectionBehavior (   QAbstractItemView::SelectRows   );
    ui->issueTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->issueTblWidget->setSelectionBehavior(   QAbstractItemView::SelectRows   );
    ui->referenceTbl->horizontalHeader()->setStretchLastSection(true);
    ui->referenceTbl->setSelectionBehavior  (   QAbstractItemView::SelectRows   );

    if(chLately->exists()){

        chLately->open( QFile::ReadWrite | QFile::Text  );

        QString o = chLately->readLine();

        auto list = o.split(",");
        latest = list[0];

        for(auto& path : list){
            pathQue->push_back(path);
        }

        latest.replace("\n", "");
        qDebug() << latest;
        setCHSFile(latest);
    }
    else{
        chLately->open( QFile::ReadWrite | QFile::Text  );
    }
}


MainWindow::~MainWindow()
{
    delete ui;

    if(chLately != nullptr){
        if(chLately->isOpen()){

            chLately->resize(0);
            QTextStream ts(&(*chLately));
            ts.setCodec("UTF-8");

            int hits = 0;
            while(!pathQue->empty()){

                if(++hits > SAVE_RECENT_PATH){
                    break;
                }

                ts << pathQue->front() + ",";
                pathQue->pop_front();
            }

            chLately->close();
        }
        delete chLately;
        delete pathQue;
    }

}

void MainWindow::ShowMessageBox(const QString& message, const QString& title){
    QMessageBox a(this);
    a.setText(message);
    a.setFixedSize(400, 150);
    a.setWindowTitle(title);
    a.exec();
}

// ==============================+===============================================================
// Private Slots

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
    ui->referenceTbl->removeRow(ui->referenceTbl->currentRow());
}

void MainWindow::on_copyBtn_clicked()
{

}

void MainWindow::on_executeBtn_clicked()
{

}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionGithub_triggered()
{
    system("start chrome /new-window https://github.com/jopemachine/CommentHelper");
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

void MainWindow::on_actionOpen_triggered()
{
    // FileDialog를 생성하고 연다.
    QFileDialog fileOpenDialog;
    fileOpenDialog.setFileMode(QFileDialog::AnyFile);
    fileOpenDialog.setNameFilter(tr("Open a Setting file (*.chs)"));
    fileOpenDialog.setViewMode(QFileDialog::Detail);
    fileOpenDialog.open(this, "Open a Setting file");

    // 파일을 선택했을 때
    if(fileOpenDialog.exec()){
        selectedFile = fileOpenDialog.selectedFiles()[0];
        pathQue->push_front(selectedFile);
    }

    clearTbl(ui->issueTblWidget);
    clearTbl(ui->descTblWidget);
    clearTbl(ui->referenceTbl);

    setCHSFile(selectedFile);
    setWindowTitle(selectedFile);
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    if(index == TAB_PREVIEW){
        QString text = "";

        QTextStream ts(&text);

        makeComment(ts, {});

        ui->previewTextEdit->setPlainText(text);
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


void MainWindow::on_actionOpen_and_run_triggered()
{

}

void MainWindow::on_actionAdd_Setting_triggered()
{

}

void MainWindow::on_actionOpen_Recents_triggered()
{

}

void MainWindow::on_actionRemove_Comments_triggered()
{
    QString chprojContent = "";

    // 리눅스의 경우 \\ 대신 / 를 써야한다
    QFile chprojFile(ui->pathEdit->text() + "\\" + "chproj");

    // 설정파일이 존재하면 파일을 읽어들여 주석을 지울 파일들의 리스트를 만든다
    if(chprojFile.exists()){
        chprojFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream ts(&chprojContent);
        ts << chprojFile.readAll();
        QStringList list = chprojContent.split(",");
        removeComment(list);
    }
    else{
        ShowMessageBox("chproj file not exist!", "Error");
        return;
    }

    chprojFile.remove();
    ShowMessageBox("done!", "Complete");
}

void MainWindow::on_actionExecute_triggered()
{

    if(ui->pathEdit->text().trimmed() == ""){
        ShowMessageBox("No directory include!", "No directory");
        return;
    }

    auto que = getAllTargetFiles(ui->pathEdit->text());

    // chproj는 지정 프로젝트 경로에서 주석을 추가해놓은 설정 파일이다.
    // chproj가 삭제되면 run 재 실행 시 해당 파일들에 주석이 한 번 더 들어가게 된다.
    QString chprojContent = "";

    // 리눅스의 경우 \\ 대신 / 를 써야한다
    QFile chprojFile(ui->pathEdit->text() + "\\" + "chproj");

    // 설정파일이 존재하면 파일을 읽어들여 주석을 지울 파일들의 리스트를 만든다
    if(chprojFile.exists()){
        chprojFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream ts(&chprojContent);
        ts << chprojFile.readAll();
        QStringList list = chprojContent.split(",");
        removeComment(list);
    }

    chprojContent = "";

    while(!que->empty()){
        prependComment(que->front());
        chprojContent += que->front().fileName + ",";
        que->pop();
    }

    if(chprojFile.isOpen()) chprojFile.close();

    chprojFile.open(QIODevice::WriteOnly|QFile::Text);

    chprojFile.write(chprojContent.toStdString().c_str());

    chprojFile.close();

    ShowMessageBox("done!", "Complete");
}



// ==============================+===============================================================
// Private Methods
// Setting Tables

void MainWindow::setFlagTable(){

    ui->flagTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->flagTblWidget->setSelectionBehavior(    QAbstractItemView::SelectRows   );

    // FlagTableWidget Setting
    insertItem(ui->flagTblWidget, false, "Author",         "0");
    insertItem(ui->flagTblWidget, false, "Last_Edited",    "0");
    insertItem(ui->flagTblWidget, false, "Desc",           "0");
    insertItem(ui->flagTblWidget, false, "Issue",          "0");
    insertItem(ui->flagTblWidget, false, "Sup_Div_Line",   "0");
    insertItem(ui->flagTblWidget, false, "Sub_Div_Line",   "0");
    insertItem(ui->flagTblWidget, false, "Email",          "0");
    insertItem(ui->flagTblWidget, false, "Telephone",      "0");
    insertItem(ui->flagTblWidget, false, "Github_Account", "0");
    insertItem(ui->flagTblWidget, false, "Ref_URLs",       "0");
    insertItem(ui->flagTblWidget, false, "Created_Date",   "0");
    insertItem(ui->flagTblWidget, false, "Team",           "0");
    insertItem(ui->flagTblWidget, false, "Memo",           "0");

}

void MainWindow::clearTbl(QTableWidget* tbl){
    tbl->setRowCount(0);
}

// ==============================+===============================================================
// Private Methods
// Handle Tables

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

void MainWindow::insertItem(QTableWidget* tbl, bool keyEditable,
                            const QString& key, const QString& value){

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

// ==============================+===============================================================
// Private Methods
// File save and load

void MainWindow::setCHSFile(const QString& chsPath){

    bool errFlag = false;

    selectedFile = chsPath;

    QFile selectFile(selectedFile);

    std::queue<QString>* confQueue = new std::queue<QString>;

    if(selectFile.exists())
    {
        selectFile.open(QFile::ReadOnly|QFile::Text);

        QTextStream ts(&selectFile);

        // Caution : 파일이 깨진다면, CHS 셋팅 파일의 인코딩이
        // UTF-8로 셋팅되어 있는지 확인할 것
        ts.setAutoDetectUnicode(true);

        while(!ts.atEnd())
        {
            confQueue->push(ts.readLine());
        }
    }

    selectFile.close();

    while(!confQueue->empty()){

        // 주석 및 빈줄은 생략
        if(confQueue->front().trimmed() == "" || confQueue->front().at(0) == "#"){
            confQueue->pop();
            continue;
        }

        // Flag Setting

        QRegularExpression flagRe("flag[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto flagMatch = flagRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(flagMatch.hasMatch()){
            auto item = searchTable(ui->flagTblWidget, flagMatch.captured("attKey"));
            item->setText(flagMatch.captured("attValue"));
            confQueue->pop();
            continue;
        }

        // Global Setting

        QRegularExpression globalRe("global[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto globalMatch = globalRe.match(confQueue->front(), 0,
                                          QRegularExpression::NormalMatch);

        if(globalMatch.hasMatch()){
            addGlobalVars(globalMatch.captured("attKey"), globalMatch.captured("attValue"));
            confQueue->pop();
            continue;
        }

        // Desc Setting

        QRegularExpression descRe("(?<attKey>\\w+[.]\\w+)::desc\\s+[+][=]\\s+(?<attValue>.+)");

        auto descMatch = descRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(descMatch.hasMatch()){
            insertItem(ui->descTblWidget, true,
                       descMatch.captured("attKey"), descMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("(?<attKey>\\w+[.]\\w+)::issue\\s+[+][=]\\s+(?<attValue>.+)");

        auto issueMatch = issueRe.match(confQueue->front(), 0,
                                        QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){
            insertItem(ui->issueTblWidget, true,
                       issueMatch.captured("attKey"), issueMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("(?<attKey>\\w+[.]\\w+)::refURLs\\s+[+][=]\\s+(?<attValue>.+)");

        auto refURLsMatch = refURLRe.match(confQueue->front(), 0,
                                           QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){
            insertItem(ui->referenceTbl, true,
                       refURLsMatch.captured("attKey"), refURLsMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        confQueue->pop();

        errFlag = true;
    }

    delete confQueue;

    if(errFlag){
        ShowMessageBox("Setting file could contain syntax error", "Caution");
    }

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

    ui->flagTblWidget->clearSelection();

    auto memo = ui->memoEdit->toPlainText();
    memo.replace("\n", ",");

    ts << "\n# Globals\n";

    ts << "global.Extension        =  " <<   ui->extensionEdit->text()      << "\n";
    ts << "global.Project_Path     =  " <<   ui->pathEdit->text()           << "\n";
    ts << "global.Author           =  " <<   ui->authorEdit->text()         << "\n";
    ts << "global.Separator        =  " <<   ui->separatorEdit->text()      << "\n";
    ts << "global.Sub_Div_Line     =  " <<   ui->subDivEdit->toPlainText()  << "\n";
    ts << "global.Sup_Div_Line     =  " <<   ui->supDivEdit->toPlainText()  << "\n";
    ts << "global.Email            =  " <<   ui->emailEdit->text()          << "\n";
    ts << "global.Telephone        =  " <<   ui->telepEdit->text()          << "\n";
    ts << "global.Github_Account   =  " <<   ui->githubEdit->text()         << "\n";
    ts << "global.Team             =  " <<   ui->teamEdit->text()           << "\n";
    ts << "global.Memo             =  " <<   memo                           << "\n";

    ts << "\n# Desc\n";


    bool existDuplicateKeys = false;

    for(int i = 0; i < ui->descTblWidget->rowCount(); i++){

        // 중복 키 값이 들어갈 수 없게 한다.
        auto dup = ui->descTblWidget->findItems(ui->descTblWidget->item(i, 0)->text(), Qt::MatchExactly);

        if(dup.length() != 1){
            existDuplicateKeys = true;
            continue;
        }

        ts << ui->descTblWidget->item(i, 0)->text() + "::desc       +=       "
              + ui->descTblWidget->item(i, 1)->text() << "\n";
    }

    ts << "\n# Issue\n";

    for(int i = 0; i < ui->issueTblWidget->rowCount(); i++){

        auto dup = ui->issueTblWidget->findItems(ui->issueTblWidget->item(i, 0)->text(), Qt::MatchExactly);

        if(dup.length() != 1){
            existDuplicateKeys = true;
            continue;
        }

        ts << ui->issueTblWidget->item(i, 0)->text() + "::issue       +=       "
              + ui->issueTblWidget->item(i, 1)->text() << "\n";
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < ui->referenceTbl->rowCount(); i++){

        // 중복 값 허용

        ts << ui->referenceTbl->item(i, 0)->text() + "::refURLs       +=       "
              + ui->referenceTbl->item(i, 1)->text() << "\n";
    }

    selectedFile = path;

    selectFile.close();

    if(existDuplicateKeys){
        ShowMessageBox("There is duplicate keys in some tables. "
                       "\nGenerated setting file does not contained these records",
                       "duplicate key error");
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
    if(key == "Team"){
        ui->teamEdit     ->setText(value);
    }
    if(key == "Memo"){
        QString& memo = const_cast<QString&>(value);
        memo.replace(",","\n");
        ui->memoEdit     ->setText(memo);
    }

    qDebug() << "wrong Info included in addGlobalVars";
}

// ==============================+===============================================================
// Private Methods
// Directory traversal

std::shared_ptr<std::queue<FileInfo>> MainWindow::getAllTargetFiles(const QString &dirName){

    // target Extension을 구하고, trim 한다.
    auto targetExtensions = ui->extensionEdit->text().split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
    }

    auto workQue = std::make_shared<std::queue<FileInfo>>();

    QDirIterator it(dirName, QDirIterator::Subdirectories);

    while(true){

        // directory 명과 올바르지 않은 path 제외
        if(!it.fileInfo().isDir() && it.filePath() != ""){

            // target 확장자가 아닌 경우 제외
            if(targetExtensions.contains(it.fileInfo().suffix())){
                workQue->push({
                         it.filePath(),
                         it.fileName(),
                         it.fileInfo().lastModified(),
                         it.fileInfo().birthTime()
                });
            }
        }

        if(!it.hasNext()) break;

        it.next();
    }

    //    while(!que->empty()){
    //        qDebug() << que->front();
    //        que->pop();
    //    }

    return workQue;
}

// ==============================+===============================================================
// Private Methods
// Make and prepend comment

void MainWindow::prependComment(FileInfo fileInfo){

    QFile qf(fileInfo.filePath);

    qf.open(QFile::ReadOnly | QFile::Text);

    QByteArray buffer = qf.readAll();

    qf.close();

    qf.open(QFile::WriteOnly | QFile::Text);

    QTextStream ts(&qf);

    ts.setCodec("UTF-8");

    makeComment(ts, fileInfo);

    // 개행 후 buffer 내용 출력
    ts << "\n" <<buffer;

}

void MainWindow::processFlag(QTextStream& ts, const QString& key, const QString& value,
                             FlagType flag, bool keyValueSpace = false){

    if(key.trimmed() == "" || key == nullptr){
        return;
    }

    if(ui->flagTblWidget->item(flag, 1)->text() == "1"){

        // div line의 경우
        if(flag == FlagType::SUBDIV || flag == FlagType::SUPDIV){
            ts << ui->separatorEdit->text() + " " + key + "\n";
            return;
        }

        // 값을 명시할 필요 없는 케이스
        else if(value == nullptr){
            return;
        }

        // key와 value 사이에 띄어쓰기를 넣을 것인지 여부
        if(keyValueSpace){
            ts << ui->separatorEdit->text() + " " + key + " : \n" + value;
        }
        else{
            ts << ui->separatorEdit->text() + " " + key + " : " + value + "\n";
        }

    }
}


void MainWindow::makeComment(QTextStream& ts, const FileInfo& fileInfo){

    QString
            edit    = nullptr,
            desc    = nullptr,
            issue   = nullptr,
            date    = nullptr,
            urls    = nullptr,
            memo    = nullptr,
            subd    = ui->subDivEdit->toPlainText(),
            supd    = ui->supDivEdit->toPlainText();

    // 함수를 preview tab에서 사용하는 경우
    if(fileInfo.fileName == nullptr){
        edit    =   "<Edited>";
        desc    =   "<Desc>";
        issue   =   "<Issue>";
        date    =   "<Date>";
        urls    =   "<URLs>";
        memo    =   "<Memo>";
    }
    // Run에서 사용하는 경우, fileName이 들어온다
    else{

        // # last modified
        edit = fileInfo.lastModified.toString("yyyy-MM-dd, HH:mm:ss");

        // # created
        date = fileInfo.created.toString("yyyy-MM-dd, HH:mm:ss");

        // # desc
        for(int i = 0; i < ui->descTblWidget->rowCount(); i++){
            auto fName = ui->descTblWidget->item(i, 0)->text();
            if(fName == fileInfo.fileName){
                desc = ui->descTblWidget->item(i, 1)->text();
                break;
            }
        }

        // # issue
        for(int i = 0; i < ui->issueTblWidget->rowCount(); i++){
            auto fName = ui->issueTblWidget->item(i, 0)->text();
            if(fName == fileInfo.fileName){
                issue = ui->issueTblWidget->item(i, 1)->text();
                break;
            }
        }

        // # urls
        int hits = 0;
        for(int i = 0; i < ui->referenceTbl->rowCount(); i++){
            auto fName = ui->referenceTbl->item(i, 0)->text();
            if(fName == fileInfo.fileName){
                urls +=
                        ui->separatorEdit->text() + " " +
                        QString::number(++hits) + ". " +
                        ui->referenceTbl->item(i, 1)->text()
                        + "\n";
            }
        }

        // # memo

        auto memoText = ui->memoEdit->toPlainText();
        auto memos = memoText.split("\n");

        for(auto& text : memos){
            if(text.trimmed() == "") continue;
            memo.append(ui->separatorEdit->text() + " " + text + "\n");
        }
    }

    processFlag(ts, supd,               "",                     FlagType::SUPDIV,     false);

    processFlag(ts, "@ Author",         ui->authorEdit->text(), FlagType::AUTHOR,     false);

    processFlag(ts, "@ Team",           ui->teamEdit->text(),   FlagType::TEAM,       false);

    processFlag(ts, "@ Created",        date,                   FlagType::CREATEDDATE,false);

    processFlag(ts, "@ Last Edited",    edit,                   FlagType::LASTEDITED, false);

    processFlag(ts, "@ Desc",           desc,                   FlagType::DESC,       false);

    processFlag(ts, "@ Issue",          issue,                  FlagType::ISSUE,      false);

    processFlag(ts, "@ Email",          ui->emailEdit->text(),  FlagType::EMAIL,      false);

    processFlag(ts, "@ Contact",        ui->telepEdit->text(),  FlagType::TELEP,      false);

    processFlag(ts, "@ Github Account", ui->githubEdit->text(), FlagType::GITHUBACC,  false);

    processFlag(ts, "@ Ref URLs",       urls,                   FlagType::REFURLS,    true );

    processFlag(ts, "@ Memo",           memo,                   FlagType::MEMO,       true );

    processFlag(ts, subd,               "",                     FlagType::SUBDIV,     false);


}


void MainWindow::removeComment(QStringList &strList){

    auto targetExtensions = ui->extensionEdit->text().split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
        if(i == ""){
            // 마지막 "" 원소 제거
            strList.pop_back();
        }
    }

    QDirIterator it(ui->pathEdit->text(), QDirIterator::Subdirectories);

    while(true){

        // directory 명과 올바르지 않은 path 제외
        if(!it.fileInfo().isDir() && it.filePath() != ""){

            // target 확장자가 아닌 경우 제외
            if(targetExtensions.contains(it.fileInfo().suffix())){

                // 리스트가 해당 원소를 포함하는 경우 주석을 제거
                if(strList.contains(it.fileName())){

                    QFile target(it.filePath());
                    QString bufferStr = "";
                    QTextStream ts(&target);

                    ts.setCodec("UTF-8");

                    target.open(QFile::ReadWrite|QFile::Text);

                    while(!target.atEnd()){

                        QString line = target.readLine();

                        bool isComment =
                                (line.left(ui->separatorEdit->text().length()) == ui->separatorEdit->text());

                        if(!isComment){
                            break;
                        }
                    }

                    while(!target.atEnd()){
                        bufferStr.append(target.readLine());
                    }

                    target.resize(0);
                    ts << bufferStr;
                    target.close();
                }
            }
        }
        if(!it.hasNext()) break;
        it.next();
    }

}

// ==============================+===============================================================
