// ==============================+===============================================================
// Import

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDirIterator>
#include <QProcess>

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
    setWindowTitle(DEFAULT_WIN_TITLE);

    chLately = new QFile(QDir::currentPath() + "\\" + "chlately");

    pathQue = new std::deque<QString>();

    QString latest = nullptr;

    setTable(ui->flagTblWidget);
    setTable(ui->descTblWidget);
    setTable(ui->issueTblWidget);
    setTable(ui->referenceTbl);
    setTable(ui->excludeTbl);
    setAcceptDrops(true);
    setShortCut();

    if(chLately->exists()){

        chLately->open( QFile::ReadWrite | QFile::Text  );

        QString o = chLately->readLine();

        QStringList list = o.split(",");

        latest = list[0];

        auto actionList = ui->menuOpen_Recents->actions();

        int index = 0;

        for (auto& action : actionList){
            if(list.length() <= index) {
                action->setVisible( false );
            }
            else{
                action->setText( list[index++] );
            }
        }

        for(auto& path : list){
            if(path == "") continue;
            pathQue->push_back( path );
        }

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

                ts << (pathQue->size() == 1 ? pathQue->front() : pathQue->front() + ",") ;
                pathQue->pop_front();
            }

            chLately->close();
        }
        delete chLately;
        delete pathQue;
    }
}


bool MainWindow::Open(){
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
    else{
        return false;
    }

    setCHSFile(selectedFile);
    return true;
}

void MainWindow::OpenRecent(const int index){
    setCHSFile(ui->menuOpen_Recents->actions()[index]->text());
}

void MainWindow::Run(){
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
        chprojContent += que->size() == 1 ? que->front().fileName : que->front().fileName + ",";
        que->pop();
    }

    if(chprojFile.isOpen()) chprojFile.close();

    chprojFile.open(QIODevice::WriteOnly|QFile::Text);

    chprojFile.write(chprojContent.toStdString().c_str());

    chprojFile.close();

    ShowMessageBox("work completed!", "Jobs done");
}

void MainWindow::ShowMessageBox(const QString& message, const QString& title){
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setBaseSize(QSize(600, 120));
    msgBox.setWindowTitle(title);
    msgBox.exec();
}

// ==============================+===============================================================
// Private Slots

void MainWindow::on_descAddBtn_clicked()
{
    QStringList exts = ui->extensionEdit->text().split(",");
    insertTbl(ui->descTblWidget, "fileName." + exts[0], "");
}

void MainWindow::on_descRemoveBtn_clicked()
{
    removeSelectedItems(ui->descTblWidget);
}

void MainWindow::on_issueAddBtn_clicked()
{
    QStringList exts = ui->extensionEdit->text().split(",");
    insertTbl(ui->issueTblWidget, "fileName." + exts[0], "");
}

void MainWindow::on_issueRemoveBtn_clicked()
{
    removeSelectedItems(ui->issueTblWidget);
}

void MainWindow::on_addReferenceBtn_clicked()
{
    QStringList exts = ui->extensionEdit->text().split(",");
    insertTbl(ui->referenceTbl, "fileName." + exts[0], "");
}

void MainWindow::on_rmReferenceBtn_clicked()
{
    removeSelectedItems(ui->referenceTbl);
}

void MainWindow::on_copyBtn_clicked()
{
    ui->previewTextEdit->selectAll();
    ui->previewTextEdit->copy();
}

void MainWindow::on_executeBtn_clicked()
{
    Run();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
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
    Open();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    if(index == tab_index::TAB_PREVIEW){
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
    if(Open()){
        Run();
    }
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
    Run();
}

void MainWindow::on_actionrecent1_triggered()
{
    OpenRecent(0);
}

void MainWindow::on_actionrecent2_triggered()
{
    OpenRecent(1);
}

void MainWindow::on_actionrecent3_triggered()
{
    OpenRecent(2);
}

void MainWindow::on_actionrecent4_triggered()
{
    OpenRecent(3);
}

void MainWindow::on_descSortBtn_clicked()
{
    sortTbl(ui->descTblWidget);
}

void MainWindow::on_issueSortBtn_clicked()
{
    sortTbl(ui->issueTblWidget);
}

void MainWindow::on_referenceSortBtn_clicked()
{
    sortTbl(ui->referenceTbl);
}

void MainWindow::on_sortExcludeBtn_clicked()
{
    sortTbl(ui->excludeTbl);
}

void MainWindow::on_addExcludeBtn_clicked()
{
    QStringList exts = ui->extensionEdit->text().split(",");
    insertTbl(ui->excludeTbl, "fileName." + exts[0]);
}

void MainWindow::on_rmExcludeBtn_clicked()
{
    removeSelectedItems(ui->excludeTbl);
}

void MainWindow::on_actionOpen_Project_Path_triggered()
{
    QProcess::startDetached("explorer " + ui->pathEdit->text());
}

void MainWindow::on_actionRefresh_triggered()
{
    setCHSFile(selectedFile);
}

void MainWindow::on_actionSave_md_triggered()
{
    QFile md(ui->pathEdit->text() + "\\" + "ch_readme.md");

    // 파일이 존재하지 않을 땐 경로에 파일을 생성한다.
    md.open(QFile::WriteOnly|QFile::Text);

    QTextStream ts(&md);

    ts << "## Description\n";

    makeMDForm(ts, ui->descTblWidget, "Description");

    ts << "\n## Issue\n";

    makeMDForm(ts, ui->issueTblWidget, "Issue");

    ts << "\n## Reference\n";

    makeMDForm(ts, ui->referenceTbl, "Reference");

    md.close();

    ShowMessageBox("work done", "done!");
}

void MainWindow::on_actionRemove_Comments_From_All_File_triggered()
{

    removeComment(*(new QStringList()));

    ShowMessageBox("done!", "Complete");
}


// ==============================+===============================================================
// Private Methods
// Setting Tables

void MainWindow::setTable(QTableWidget* tbl){
    tbl->horizontalHeader()->setStretchLastSection(true);
    tbl->setSelectionBehavior(    QAbstractItemView::SelectRows   );
}

void MainWindow::clearTbl(QTableWidget* tbl){
    tbl->setRowCount(0);
}

void MainWindow::sortTbl(QTableWidget *tbl){
    tbl->sortByColumn(0, Qt::AscendingOrder);
}

void MainWindow::insertTbl(QTableWidget *tbl, const QString& key, const QString& value){
    insertItem(tbl, true, key, value);
    tbl->selectRow(tbl->rowCount() - 1);
    // tbl->item(tbl->rowCount() - 1, 0)->setSelected(true);
}

void MainWindow::setShortCut()
{

    // Add Buttons
    ui->descAddBtn->setShortcut(QKeySequence(Qt::Key_Plus));
    ui->issueAddBtn->setShortcut(QKeySequence(Qt::Key_Plus));
    ui->addReferenceBtn->setShortcut(QKeySequence(Qt::Key_Plus));
    ui->addExcludeBtn->setShortcut(QKeySequence(Qt::Key_Plus));

    // Delete Buttons
    ui->descRemoveBtn->setShortcut(QKeySequence::Delete);
    ui->issueRemoveBtn->setShortcut(QKeySequence::Delete);
    ui->rmReferenceBtn->setShortcut(QKeySequence::Delete);
    ui->rmExcludeBtn->setShortcut(QKeySequence::Delete);

    // Sort Buttons

    // Other Buttons
    ui->copyBtn->setShortcut(QKeySequence(Qt::Key_C));

}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    // http://www.moneybook.co.kr/pages/blog_dev_note/543888

    QRegularExpression fileNameRe("(?<fileName>[^\\/\n]+$)");

    foreach (const QUrl &url, e->mimeData()->urls()) {

        auto fileNameMatch = fileNameRe.match(url.toLocalFile(), 0,
                                            QRegularExpression::NormalMatch);

        QString name = fileNameMatch.captured("fileName");

        switch(ui->tabWidget->currentIndex()){

        case tab_index::TAB_DESCRIPT: insertTbl(ui->descTblWidget, name, " ");
        break;

        case tab_index::TAB_ISSUE: insertTbl(ui->issueTblWidget, name, " ");
        break;

        case tab_index::TAB_EXCLUDE: insertTbl(ui->excludeTbl, name);
        break;

        case tab_index::TAB_REF: insertTbl(ui->referenceTbl, name, " ");
        break;

        };
    }
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

    int row =   tbl->rowCount();
    tbl->insertRow(row);

    // key
    auto keyColumn      = new QTableWidgetItem(key);

    if(!keyEditable){
        keyColumn->setFlags(keyColumn->flags() & ~Qt::ItemIsEditable);
    }

    tbl->setItem(row, 0, keyColumn);

    // value
    if(value != nullptr){
        auto valueColumn    = new QTableWidgetItem(value);
        tbl->setItem(row, 1, valueColumn);
    }

}

// https://www.qtcentre.org/threads/4885-Remove-selected-rows-from-a-QTableView 참고
void MainWindow::removeSelectedItems(QTableWidget* tbl){

    //get selections
    QItemSelection selection = tbl->selectionModel()->selection();

    //find out selected rows
    QList<int> removeRows;
    foreach(QModelIndex index, selection.indexes()) {
        if(!removeRows.contains(index.row())) {
            removeRows.append(index.row());
        }
    }

    //loop through all selected rows
    for(int i=0;i<removeRows.count();++i)
    {
        //decrement all rows after the current - as the row-number will change if we remove the current
        for(int j=i;j<removeRows.count();++j) {
            if(removeRows.at(j) > removeRows.at(i)) {
                removeRows[j]--;
            }
        }
        //remove the selected row
        tbl->removeRow(removeRows.at(i));
    }
}

// ==============================+===============================================================
// Private Methods
// File save and load

void MainWindow::setCHSFile(const QString& chsPath){

    clearTbl(ui->issueTblWidget);
    clearTbl(ui->descTblWidget);
    clearTbl(ui->referenceTbl);
    clearTbl(ui->excludeTbl);

    setWindowTitle(chsPath);

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

        // Setting
        QRegularExpression settingRe("setting[.](?<attKey>\\w+)\\s+[=]\\s+(?<attValue>.+)");

        auto settingMatch = settingRe.match(confQueue->front(), 0,
                                            QRegularExpression::NormalMatch);

        if(settingMatch.hasMatch()){
            setSettingFlags(settingMatch.captured("attKey"), settingMatch.captured("attValue").toInt());
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

        QRegularExpression descRe("(?<attKey>\\w+[.]?\\w+)::desc\\s+[+][=]\\s+(?<attValue>.+)");

        auto descMatch = descRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(descMatch.hasMatch()){
            insertItem(ui->descTblWidget, true,
                       descMatch.captured("attKey"), descMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("(?<attKey>\\w+[.]?\\w+)::issue\\s+[+][=]\\s+(?<attValue>.+)");

        auto issueMatch = issueRe.match(confQueue->front(), 0,
                                        QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){
            insertItem(ui->issueTblWidget, true,
                       issueMatch.captured("attKey"), issueMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("(?<attKey>\\w+[.]?\\w+)::refURLs\\s+[+][=]\\s+(?<attValue>.+)");

        auto refURLsMatch = refURLRe.match(confQueue->front(), 0,
                                           QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){
            insertItem(ui->referenceTbl, true,
                       refURLsMatch.captured("attKey"), refURLsMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Excluded files

        QRegularExpression excludingRe("(?<attKey>\\w+[.]?\\w+)::exclude");

        auto excludeMatch = excludingRe.match(confQueue->front(), 0,
                                              QRegularExpression::NormalMatch);

        if(excludeMatch.hasMatch()){
            insertItem(ui->excludeTbl, true,
                       excludeMatch.captured("attKey"), nullptr);

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

    ts << "\n# Setting\n";

    ts << "setting.descNumbering        =   "         + QString::number(ui->actionDesc_Numbering->isChecked())       + "\n";
    ts << "setting.issueNumbering       =   "         + QString::number(ui->actionIssue_Numbering->isChecked())      + "\n";
    ts << "setting.recursiveTraversal   =   "         + QString::number(ui->actionRecursive_Traversal->isChecked())  + "\n";

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

    // ui->subDivEdit->toPlainText()

    QString subDs = ui->subDivEdit->toPlainText().replace("\n",",");
    QString supDs = ui->supDivEdit->toPlainText().replace("\n",",");

    ts << "global.Extension        =  " <<   ui->extensionEdit->text()      << "\n";
    ts << "global.Project_Path     =  " <<   ui->pathEdit->text()           << "\n";
    ts << "global.Author           =  " <<   ui->authorEdit->text()         << "\n";
    ts << "global.Separator        =  " <<   ui->separatorEdit->text()      << "\n";
    ts << "global.Sub_Div_Line     =  " <<   subDs                          << "\n";
    ts << "global.Sup_Div_Line     =  " <<   supDs                          << "\n";
    ts << "global.Email            =  " <<   ui->emailEdit->text()          << "\n";
    ts << "global.Telephone        =  " <<   ui->telepEdit->text()          << "\n";
    ts << "global.Github_Account   =  " <<   ui->githubEdit->text()         << "\n";
    ts << "global.Team             =  " <<   ui->teamEdit->text()           << "\n";
    ts << "global.Memo             =  " <<   memo                           << "\n";

    ts << "\n# Desc\n";

    for(int i = 0; i < ui->descTblWidget->rowCount(); i++){

        QStringList list = ui->descTblWidget->item(i, 1)->text().split("\n");

        for (auto& desc : list){
            ts << ui->descTblWidget->item(i, 0)->text() + "::desc       +=       "
                  + desc << "\n";
        }
    }

    ts << "\n# Issue\n";

    for(int i = 0; i < ui->issueTblWidget->rowCount(); i++){

        QStringList list = ui->issueTblWidget->item(i, 1)->text().split("\n");

        for (auto& issue : list){
            ts << ui->issueTblWidget->item(i, 0)->text() + "::issue       +=       "
                  + issue << "\n";
        }
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < ui->referenceTbl->rowCount(); i++){

        QStringList list = ui->referenceTbl->item(i, 1)->text().split("\n");

        for (auto& url : list){
            ts << ui->referenceTbl->item(i, 0)->text() + "::refURLs       +=       "
                  + url << "\n";
        }

    }

    ts << "\n# Excluded files\n";

    for (int i = 0; i < ui->excludeTbl->rowCount(); i++){
        ts << ui->excludeTbl->item(i, 0)->text() + "::exclude\n";
    }

    selectedFile = path;

    selectFile.close();

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
        QString& subD = const_cast<QString&>(value);
        subD.replace(",","\n");
        ui->subDivEdit  ->setPlainText(value);
        return;
    }
    if(key == "Sup_Div_Line"){
        QString& supD = const_cast<QString&>(value);
        supD.replace(",","\n");
        ui->supDivEdit  ->setPlainText(value);
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
        return;
    }
    if(key == "Memo"){
        QString& memo = const_cast<QString&>(value);
        memo.replace(",","\n");
        ui->memoEdit     ->setText(memo);
        return;
    }

    qDebug() << "wrong Info included in addGlobalVars, value: " << key;
}

void MainWindow::setSettingFlags(const QString &flagName, bool flag)
{
    if      (flagName   == "descNumbering"){
        ui->actionDesc_Numbering->setChecked(flag);
    }
    else if (flagName   == "issueNumbering"){
        ui->actionIssue_Numbering->setChecked(flag);
    }
    else if (flagName   == "recursiveTraversal"){
        ui->actionRecursive_Traversal->setChecked(flag);
    }
    else {
        qDebug() << "Wrong Setting value";
    }
}

void MainWindow::makeMDForm(QTextStream& ts, const QTableWidget *tbl, const QString &tblName)
{

    ts << "| File Name | " + tblName + " | \n";
    ts << "|---|:---:|          \n";

    bool prevSameKey = false;
    bool nextSameKey = false;

    for(int i = 0; i < tbl->rowCount(); i++){
        // 다음 오는 키가 동일한 값인지 판단
        if(i == tbl->rowCount() - 1){
            nextSameKey = false;
        }
        else{
            if(tbl->item(i, 0)->text() == tbl->item(i + 1, 0)->text()){
                nextSameKey = true;
            }
            else{
                nextSameKey = false;
            }
        }

        // 이전의 키가 동일한 키인지 판단
        if(i == 0){
            prevSameKey = false;
        }
        else{
            if(tbl->item(i, 0)->text() == tbl->item(i - 1, 0)->text()){
                prevSameKey = true;
            }
            else{
                prevSameKey = false;
            }
        }

        if(nextSameKey && !prevSameKey){
            ts << "| " + tbl->item(i, 0)->text() + " | " + tbl->item(i, 1)->text() +    " ";
        }
        else if(nextSameKey && prevSameKey){
            ts <<        tbl->item(i, 1)->text()                                   +    " ";
        }
        else if(!nextSameKey && prevSameKey){
            ts <<        tbl->item(i, 1)->text()                                   + " |\n";
        }
        else{
            ts << "| " + tbl->item(i, 0)->text() + " | " + tbl->item(i, 1)->text() + " |\n";
        }
    }

}


// ==============================+===============================================================
// Private Methods
// Directory traversal

s_ptr<queue<FileInfo>> MainWindow::getAllTargetFiles(const QString &dirName){

    // target Extension을 구하고, trim 한다.
    QStringList targetExtensions = ui->extensionEdit->text().split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
    }

    // 주석을 붙히지 않을 파일 이름의 List
    QStringList excludeList;
    for(int i = 0; i < ui->excludeTbl->rowCount(); i++){
        excludeList.append(ui->excludeTbl->item(i, 0)->text());
    }

    auto workQue = std::make_shared<std::queue<FileInfo>>();

    auto flag = ui->actionRecursive_Traversal->isChecked() ?
                QDirIterator::IteratorFlag::Subdirectories :
                QDirIterator::IteratorFlag::NoIteratorFlags;

    QDirIterator it(dirName, flag);

    while(true){

        // directory 명과 올바르지 않은 path 제외
        if(!it.fileInfo().isDir() && it.filePath() != ""){

            // target 확장자가 아닌 경우와 exclude 리스트에 있는 항목 제외
            if(targetExtensions.contains(it.fileInfo().suffix()) &&
                    !excludeList.contains(it.fileName())){

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
                             FlagType flag, bool previewMode, bool keyValueSpace){

    if(key.trimmed() == "" || key == nullptr){
        return;
    }

    if(ui->flagTblWidget->item(flag, 1)->text() == "1"){

        // div line의 경우
        if(IS_DIV(flag)){

            QStringList list = key.split("\n");

            for(auto line : list){
                ts << ui->separatorEdit->text() + " " + line + "\n";
            }
            return;
        }

        if(!previewMode && value == ""){
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

    bool isPreviewMode = false;

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
        desc    =   "";
        issue   =   "";
        date    =   "<Date>";
        urls    =   "";
        memo    =   "";
        isPreviewMode = true;
    }
    // Run에서 사용하는 경우, fileName이 들어온다
    else{

        edit    = fileInfo.lastModified.toString("yyyy-MM-dd, HH:mm:ss");
        date    = fileInfo.created     .toString("yyyy-MM-dd, HH:mm:ss");
        desc    = *(makeFromTbl(ui->descTblWidget,  ui->actionDesc_Numbering ->isChecked(), fileInfo));
        issue   = *(makeFromTbl(ui->issueTblWidget, ui->actionIssue_Numbering->isChecked(), fileInfo));
        urls    = *(makeFromTbl(ui->referenceTbl, true, fileInfo));

        auto memoText   = ui->memoEdit->toPlainText();
        auto memos      = memoText.split("\n");

        for(auto& text : memos){
            if(text.trimmed() == "") continue;
            memo.append(ui->separatorEdit->text() + "  " + text + "\n");
        }
    }

    processFlag(ts, supd,               "",                     FlagType::SUPDIV,     isPreviewMode, false);

    processFlag(ts, "@ Author",         ui->authorEdit->text(), FlagType::AUTHOR,     isPreviewMode, false);

    processFlag(ts, "@ Team",           ui->teamEdit->text(),   FlagType::TEAM,       isPreviewMode, false);

    processFlag(ts, "@ Created",        date,                   FlagType::CREATEDDATE,isPreviewMode, false);

    processFlag(ts, "@ Last Edited",    edit,                   FlagType::LASTEDITED, isPreviewMode, false);

    processFlag(ts, "@ Desc",           desc,                   FlagType::DESC,       isPreviewMode, true );

    processFlag(ts, "@ Issue",          issue,                  FlagType::ISSUE,      isPreviewMode, true );

    processFlag(ts, "@ Email",          ui->emailEdit->text(),  FlagType::EMAIL,      isPreviewMode, false);

    processFlag(ts, "@ Contact",        ui->telepEdit->text(),  FlagType::TELEP,      isPreviewMode, false);

    processFlag(ts, "@ Github Account", ui->githubEdit->text(), FlagType::GITHUBACC,  isPreviewMode, false);

    processFlag(ts, "@ Ref URLs",       urls,                   FlagType::REFURLS,    isPreviewMode, true );

    processFlag(ts, "@ Memo",           memo,                   FlagType::MEMO,       isPreviewMode, true );

    processFlag(ts, subd,               "",                     FlagType::SUBDIV,     isPreviewMode, false);


}

s_ptr<QString> MainWindow::makeFromTbl(QTableWidget* tbl, bool numbering, const FileInfo& fileInfo){

    auto ret = std::make_shared<QString>();

    if(numbering){

        int hits = 0;
        for(int i = 0; i < tbl->rowCount(); i++){
            auto fName = tbl->item(i, 0)->text();
            if(fName == fileInfo.fileName){
                *ret +=
                        ui->separatorEdit->text() + " @     " +
                        QString::number(++hits) + ". " +
                        tbl->item(i, 1)->text()
                        + "\n";
            }
        }
    }
    else{

        for(int i = 0; i < tbl->rowCount(); i++){
            auto fName = tbl->item(i, 0)->text();
            if(fName == fileInfo.fileName){
                *ret +=
                        ui->separatorEdit->text() + " @     " +
                        tbl->item(i, 1)->text()
                        + "\n";
            }
        }
    }

    return ret;
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

    auto flag = ui->actionRecursive_Traversal->isChecked() ?
                QDirIterator::IteratorFlag::Subdirectories :
                QDirIterator::IteratorFlag::NoIteratorFlags;

    QDirIterator it(ui->pathEdit->text(), flag);

    while(true){

        // directory 명과 올바르지 않은 path 제외
        if(!it.fileInfo().isDir() && it.filePath() != ""){

            // target 확장자가 아닌 경우 제외
            if(targetExtensions.contains(it.fileInfo().suffix())){

                // 리스트가 해당 원소를 포함하는 경우, 또는
                // 리스트의 길이가 0인 경우 (모두 제거) 주석을 제거
                if(strList.length() == 0 || strList.contains(it.fileName())){

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

