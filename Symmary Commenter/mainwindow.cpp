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
#include <QMimeData>
#include <QDragEnterEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// ==============================+===============================================================
// Public Method

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(DEFAULT_WIN_TITLE);

    auto setTable = [](QTableWidget* tbl)-> void {
        tbl->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
        tbl->horizontalHeader()->setStretchLastSection(true);
        tbl->setSelectionBehavior(    QAbstractItemView::SelectRows   );
    };

    setTable(FlagTable_t);
    setTable(DescTable_t);
    setTable(IssueTable_t);
    setTable(RefTable_t);
    setTable(ExcludeTable_t);

    setAcceptDrops(true);
    setShortCut();

    if(!openRecentPathsFile()){
        // scps 파일을 열지 않았다면 기본 값으로 초기화
        flagTypeTbl = new FlagType_tbl;
        flagTypeTbl->init();
        int size = static_cast<int>(flagTypeTbl->map.size());
        for(int i = 0; i < size; i++){
            insertItem(FlagTable_t, false, flagTypeTbl->map.at(i).key, QString::number(1));
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete flagTypeTbl;

    if(latelyPathsFile != nullptr){
        if(latelyPathsFile->isOpen()){

            latelyPathsFile->resize(0);
            QTextStream ts(&(*latelyPathsFile));
            ts.setCodec("UTF-8");

            int hits = 0;
            while(!pathQue->empty()){

                if(++hits > SAVE_RECENT_PATH){
                    break;
                }

                ts << (pathQue->size() == 1 ? pathQue->front() : pathQue->front() + ",") ;
                pathQue->pop_front();
            }

            latelyPathsFile->close();
        }
        delete latelyPathsFile;
        delete pathQue;
    }
}


bool MainWindow::Open(){
    // FileDialog를 생성하고 연다.
    QFileDialog fileOpenDialog;
    fileOpenDialog.setFileMode(QFileDialog::AnyFile);

    QString nameFilter = QString ("Open a Setting file (*.") + QString(PROJECT_SETTING_FILE_EXT) + QString(")");

    fileOpenDialog.setNameFilter(nameFilter);
    fileOpenDialog.setViewMode(QFileDialog::Detail);
    fileOpenDialog.open(this, "Open a Setting file");

    // 파일을 선택했을 때
    if(fileOpenDialog.exec()){
        selectedFile = fileOpenDialog.selectedFiles()[0];

        // queue에 해당 값이 있는지 확인해 중복되면 큐에 추가하지 않는다.
        if(std::find(pathQue->begin(), pathQue->end(), selectedFile) == pathQue->end()){
            pathQue->push_front(selectedFile);
        }
    }
    else{
        return false;
    }

    initProgram();
    setSCPSFile(selectedFile);
    return true;
}

void MainWindow::OpenRecent(const int index){
    initProgram();
    setSCPSFile(ui->menuOpen_Recents->actions()[index]->text());
}

void MainWindow::Run(){
    if(ProjectPath_t.trimmed() == ""){
        ShowMessageBox("No directory include!", "No directory");
        return;
    }

    auto que = getAllTargetFiles(ProjectPath_t);

    // chproj는 지정 프로젝트 경로에서 주석을 추가해놓은 설정 파일이다.
    // chproj가 삭제되면 run 재 실행 시 해당 파일들에 주석이 한 번 더 들어가게 된다.
    QString scprojContent = "";

    // 리눅스의 경우 \\ 대신 / 를 써야한다
    QFile scprojFile(ProjectPath_t + "\\" + PROJECT_WORKED_FILE_EXT);

    // 설정파일이 존재하면 파일을 읽어들여 주석을 지울 파일들의 리스트를 만든다
    if(scprojFile.exists()){
        scprojFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream ts(&scprojContent);
        ts << scprojFile.readAll();
        QStringList list = scprojContent.split(",");
        if(!removeComment(list)){
            ShowMessageBox("Essential Input Not Specified!", "Error");
            return;
        }
    }

    scprojContent = "";

    while(!que->empty()){
        prependComment(que->front());
        scprojContent += que->size() == 1 ? que->front().fileName : que->front().fileName + ",";
        que->pop();
    }

    if(scprojFile.isOpen()) scprojFile.close();

    scprojFile.open(QIODevice::WriteOnly|QFile::Text);

    scprojFile.write(scprojContent.toStdString().c_str());

    scprojFile.close();

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
    QStringList exts = Extension_t.split(",");
    insertTbl(DescTable_t, "fileName." + exts[0], "");
}

void MainWindow::on_descRemoveBtn_clicked()
{
    removeSelectedItems(DescTable_t);
}

void MainWindow::on_issueAddBtn_clicked()
{
    QStringList exts = Extension_t.split(",");
    insertTbl(IssueTable_t, "fileName." + exts[0], "");
}

void MainWindow::on_issueRemoveBtn_clicked()
{
    removeSelectedItems(IssueTable_t);
}

void MainWindow::on_addReferenceBtn_clicked()
{
    QStringList exts = Extension_t.split(",");
    insertTbl(RefTable_t, "fileName." + exts[0], "");
}

void MainWindow::on_rmReferenceBtn_clicked()
{
    removeSelectedItems(RefTable_t);
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
    system("start chrome /new-window https://github.com/jopemachine/Summary-Commenter");
}

void MainWindow::on_actionSave_triggered()
{
    // 파일이 열려 있지 않을 땐 파일 저장 Dialog를 띄워 먼저 저장할 파일의 경로를 받아온다
    if(selectedFile == "") {

        QString nameFilter =
                QString ("Summary Commenter Project Setting (*.") +
                QString(PROJECT_SETTING_FILE_EXT) +
                QString(");;All Files (*)");

        selectedFile = QFileDialog::getSaveFileName(this,
                                                    tr("Save setting file"), "",
                                                    nameFilter);

        setWindowTitle(selectedFile);
    }

    saveSCPSFile(selectedFile);

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

    QString nameFilter =
            QString ("Summary Commenter Project Setting (*.") +
            QString(PROJECT_SETTING_FILE_EXT) +
            QString(");;All Files (*)");

    selectedFile = QFileDialog::getSaveFileName(this,
                                                tr("Save setting file"), "",
                                                nameFilter);

    if(selectedFile == ""){
        return;
    }

    setWindowTitle(selectedFile);

    saveSCPSFile(selectedFile);
}


void MainWindow::on_actionOpen_and_run_triggered()
{
    if(Open()){
        Run();
    }
}

void MainWindow::on_actionRemove_Comments_triggered()
{
    QString scprojContent = "";

    // 리눅스의 경우 \\ 대신 / 를 써야한다
    QFile scprojFile(ProjectPath_t + "\\" + PROJECT_WORKED_FILE_EXT);

    // 설정파일이 존재하면 파일을 읽어들여 주석을 지울 파일들의 리스트를 만든다
    if(scprojFile.exists()){
        scprojFile.open(QFile::ReadOnly|QFile::Text);
        QTextStream ts(&scprojContent);
        ts << scprojFile.readAll();
        QStringList list = scprojContent.split(",");
        if(!removeComment(list)){
            ShowMessageBox("Essential Input Not Specified!", "Error");
            return;
        }
    }
    else{
        ShowMessageBox("scproj file not exist!", "Error");
        return;
    }

    scprojFile.remove();
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
    sortTbl(DescTable_t);
}

void MainWindow::on_issueSortBtn_clicked()
{
    sortTbl(IssueTable_t);
}

void MainWindow::on_referenceSortBtn_clicked()
{
    sortTbl(RefTable_t);
}

void MainWindow::on_sortExcludeBtn_clicked()
{
    sortTbl(ExcludeTable_t);
}

void MainWindow::on_addExcludeBtn_clicked()
{
    QStringList exts = Extension_t.split(",");
    insertTbl(ExcludeTable_t, "fileName." + exts[0]);
}

void MainWindow::on_rmExcludeBtn_clicked()
{
    removeSelectedItems(ExcludeTable_t);
}

void MainWindow::on_actionOpen_Project_Path_triggered()
{
    if(ProjectPath_t.trimmed() == ""){
        ShowMessageBox("Directory not specified", "Error");
        return;
    }

    QProcess::startDetached("explorer " + ProjectPath_t);
}

void MainWindow::on_actionRefresh_triggered()
{
    initProgram();
    setSCPSFile(selectedFile);
}

void MainWindow::on_actionSave_md_triggered()
{
    QFile md(ProjectPath_t + "\\" + "sc_readme.md");

    // 파일이 존재하지 않을 땐 경로에 파일을 생성한다.
    md.open(QFile::WriteOnly|QFile::Text);

    QTextStream ts(&md);

    ts << "## Documentations\n";

    ts << "### Description\n";

    makeMDForm(ts, DescTable_t,     "Description");

    ts << "\n### Issue\n";

    makeMDForm(ts, IssueTable_t,    "Issue");

    ts << "\n### Reference\n";

    makeMDForm(ts, RefTable_t,      "Reference");

    md.close();

    ShowMessageBox("work done", "done!");
}

void MainWindow::on_actionRemove_Comments_From_All_File_triggered()
{
    if(!removeComment(*(new QStringList()))){
        ShowMessageBox("Essential Input Not Specified!", "Error");
        return;
    }

    ShowMessageBox("done!", "Complete");
}


void MainWindow::on_actionOpen_setting_file_triggered()
{
    if(pathQue->empty()){
        ShowMessageBox("No files are open", "Error");
        return;
    }

    QString front = pathQue->front();
    QString path = front.replace("/", "\\");

    QProcess::startDetached("explorer " + path);
}

void MainWindow::on_FlagUpBtn_clicked()
{
    QItemSelection selection = FlagTable_t->selectionModel()->selection();

    QModelIndexList i = selection[0].indexes();
    int target = i[0].row();

    if(target == 0 || selection.count() != 1){
        return;
    }

    itemChange(FlagTable_t, target, target - 1);
    flagTypeTbl->swap(target, target - 1);
    FlagTable_t->selectRow(target - 1);

}

void MainWindow::on_FlagDownBtn_clicked()
{
    QItemSelection selection = FlagTable_t->selectionModel()->selection();

    QModelIndexList i = selection[0].indexes();
    int target = i[0].row();

    if(target == static_cast<int>(flagTypeTbl->map.size()) - 1 || selection.count() != 1){
        return;
    }

    itemChange(FlagTable_t, target, target + 1);
    flagTypeTbl->swap(target, target + 1);
    FlagTable_t->selectRow(target + 1);
}


// ==============================+===============================================================
// Private Methods
// Setting Tables

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
    auto bindKey = [](QKeySequence key, QAbstractButton* widget)-> void {
        widget->setShortcut(key);
    };

    // Add, Up
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->descAddBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->issueAddBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->addReferenceBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->addExcludeBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->FlagUpBtn);

    // Remove
    bindKey(QKeySequence::Delete              , ui->descRemoveBtn);
    bindKey(QKeySequence::Delete              , ui->issueRemoveBtn);
    bindKey(QKeySequence::Delete              , ui->rmReferenceBtn);
    bindKey(QKeySequence::Delete              , ui->rmExcludeBtn);

    // Sort
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->descSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->issueSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->referenceSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->sortExcludeBtn);

    // Copy
    bindKey(QKeySequence(Qt::Key_C)           , ui->copyBtn);

    // Down
    bindKey(QKeySequence(Qt::Key_Minus)       , ui->FlagDownBtn);

}

void MainWindow::itemChange(QTableWidget* tbl, int prev, int dest)
{
    auto swap = [](QTableWidget* tbl, int curr, int targ)-> void{
        auto target_1stCol = tbl->item(targ, 0)->text();
        auto target_2ndCol = tbl->item(targ, 1)->text();

        tbl->item(targ, 0)->setText(tbl->item(curr, 0)->text());
        tbl->item(targ, 1)->setText(tbl->item(curr, 1)->text());
        tbl->item(curr, 0)->setText(target_1stCol);
        tbl->item(curr, 1)->setText(target_2ndCol);
    };

    swap(tbl, prev, dest);
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

        case tab_index::TAB_DESCRIPT:   insertTbl(DescTable_t,  name, " ");
            break;

        case tab_index::TAB_ISSUE:      insertTbl(IssueTable_t, name, " ");
            break;

        case tab_index::TAB_REF:        insertTbl(RefTable_t,   name, " ");
            break;

        case tab_index::TAB_EXCLUDE:    insertTbl(ExcludeTable_t, name);
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

void MainWindow::initProgram()
{
    flagTypeTbl = new FlagType_tbl;

    clearTbl(FlagTable_t);
    clearTbl(IssueTable_t);
    clearTbl(DescTable_t);
    clearTbl(RefTable_t);
    clearTbl(ExcludeTable_t);
}


void MainWindow::setSCPSFile(const QString& settingFilePath){

    setWindowTitle(settingFilePath);

    int flagHits = 0;

    bool errFlag = false;

    selectedFile = settingFilePath;

    QFile selectFile(selectedFile);

    std::queue<QString>* confQueue = new std::queue<QString>;

    if(selectFile.exists())
    {
        selectFile.open(QFile::ReadOnly|QFile::Text);

        QTextStream ts(&selectFile);

        // Caution : 파일이 깨진다면, SCPS 셋팅 파일의 인코딩이
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
            // 읽은 순서대로 flagTypeTbl에 기록하고, 테이블에 추가
            bool LineFeed = false;
            if(flagMatch.captured("attKey") == "Desc" || flagMatch.captured("attKey") == "Issue" ||
                    flagMatch.captured("attKey") == "Memo"){
                LineFeed = true;
            }

            flagTypeTbl->map.insert({ flagHits++, { flagMatch.captured("attKey"), LineFeed }});

            insertItem(FlagTable_t, false, flagMatch.captured("attKey"), flagMatch.captured("attValue"));
            confQueue->pop();
            continue;
        }

        // Global Setting

        QRegularExpression globalRe("global[.](?<attKey>\\w+)\\s+[=]\\s+\"(?<attValue>.*)\"");

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
            insertItem(DescTable_t, true,
                       descMatch.captured("attKey"), descMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("(?<attKey>\\w+[.]?\\w+)::issue\\s+[+][=]\\s+(?<attValue>.+)");

        auto issueMatch = issueRe.match(confQueue->front(), 0,
                                        QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){
            insertItem(IssueTable_t, true,
                       issueMatch.captured("attKey"), issueMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("(?<attKey>\\w+[.]?\\w+)::refURLs\\s+[+][=]\\s+(?<attValue>.+)");

        auto refURLsMatch = refURLRe.match(confQueue->front(), 0,
                                           QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){
            insertItem(RefTable_t, true,
                       refURLsMatch.captured("attKey"), refURLsMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Excluded files

        QRegularExpression excludingRe("(?<attKey>\\w+[.]?\\w+)::exclude");

        auto excludeMatch = excludingRe.match(confQueue->front(), 0,
                                              QRegularExpression::NormalMatch);

        if(excludeMatch.hasMatch()){
            insertItem(ExcludeTable_t, true,
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

void MainWindow::saveSCPSFile(const QString& path){

    QFile selectFile(path);

    // 파일이 존재하지 않을 땐 경로에 파일을 생성한다.
    selectFile.open(QFile::WriteOnly|QFile::Text);

    QTextStream ts(&selectFile);

    ts << CSH_START_COMMENT << "\n";

    ts << "\n# Setting\n";

    ts << "setting.descNumbering        =   "         + QString::number(IsDescNumbering_t)       + "\n";
    ts << "setting.issueNumbering       =   "         + QString::number(IsIssueNumbering_t)      + "\n";
    ts << "setting.recursiveTraversal   =   "         + QString::number(IsRecursiveTraversal_t)  + "\n";
    ts << "setting.divBySeparator       =   "         + QString::number(IsDivBySeparator_t)      + "\n";
    ts << "setting.divByStartEndTag     =   "         + QString::number(IsDivByStartEndTag_t)    + "\n";

    ts << "\n# Flags\n";

    FlagTable_t->selectAll();
    QList<QTableWidgetItem *> selectedCells = FlagTable_t->selectedItems();

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

    FlagTable_t->clearSelection();

    auto memo = Memo_t;
    memo.replace("\n", ",");

    ts << "\n# Globals\n";

    QString subDs = SubDiv_t.replace("\n",",");
    QString supDs = SupDiv_t.replace("\n",",");

    ts << "global.Extension        =  \"" <<   Extension_t      << "\"\n";
    ts << "global.Project_Path     =  \"" <<   ProjectPath_t    << "\"\n";
    ts << "global.Author           =  \"" <<   Author_t         << "\"\n";
    ts << "global.Separator        =  \"" <<   Separator_t      << "\"\n";
    ts << "global.StartTag         =  \"" <<   StartTag_t       << "\"\n";
    ts << "global.EndTag           =  \"" <<   EndTag_t         << "\"\n";
    ts << "global.Sub_Div_Line     =  \"" <<   subDs            << "\"\n";
    ts << "global.Sup_Div_Line     =  \"" <<   supDs            << "\"\n";
    ts << "global.Email            =  \"" <<   Email_t          << "\"\n";
    ts << "global.Telephone        =  \"" <<   Telep_t          << "\"\n";
    ts << "global.Github_Account   =  \"" <<   GithubAcc_t      << "\"\n";
    ts << "global.Team             =  \"" <<   Team_t           << "\"\n";
    ts << "global.Memo             =  \"" <<   memo             << "\"\n";

    ts << "\n# Desc\n";

    for(int i = 0; i < DescTable_t->rowCount(); i++){

        QStringList list = DescTable_t->item(i, 1)->text().split("\n");

        for (auto& desc : list){
            ts << DescTable_t->item(i, 0)->text() + "::desc       +=       "
                  + desc << "\n";
        }
    }

    ts << "\n# Issue\n";

    for(int i = 0; i < IssueTable_t->rowCount(); i++){

        QStringList list = IssueTable_t->item(i, 1)->text().split("\n");

        for (auto& issue : list){
            ts << IssueTable_t->item(i, 0)->text() + "::issue       +=       "
                  + issue << "\n";
        }
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < RefTable_t->rowCount(); i++){

        QStringList list = RefTable_t->item(i, 1)->text().split("\n");

        for (auto& url : list){
            ts << RefTable_t->item(i, 0)->text() + "::refURLs       +=       "
                  + url << "\n";
        }

    }

    ts << "\n# Excluded files\n";

    for (int i = 0; i < ExcludeTable_t->rowCount(); i++){
        ts << ExcludeTable_t->item(i, 0)->text() + "::exclude\n";
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
    if(key == "StartTag"){
        ui->sTagEdit    ->setText(value);
        return;
    }
    if(key == "EndTag"){
        ui->eTagEdit    ->setText(value);
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
    else if (flagName   == "divBySeparator"){
        ui->actionDivide_by_Separator->setChecked(flag);
    }
    else if (flagName   == "divByStartEndTag"){
        ui->actionDivide_by_Start_End_tag->setChecked(flag);
    }
    else {
        qDebug() << "Wrong Setting value";
    }
}

void MainWindow::makeMDForm(QTextStream& ts, const QTableWidget *tbl, const QString &tblName)
{

    ts << "| File Name | " + tblName + " | \n";
    ts << "|---|---|          \n";

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

        if     (nextSameKey && !prevSameKey){
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

bool MainWindow::openRecentPathsFile()
{
    QString latest = nullptr;

    pathQue = new std::deque<QString>();

    latelyPathsFile = new QFile(QDir(QDir::currentPath()).filePath(PROJECT_LATELY_OPEN_EXT));

    if(latelyPathsFile->exists()){

        latelyPathsFile->open( QFile::ReadWrite | QFile::Text  );

        QString o = latelyPathsFile->readLine();

        QStringList list = o.split(",");

        latest = list[0];

        if(latest.trimmed() == "") return false;

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

        initProgram();
        setSCPSFile(latest);
        return true;
    }
    else{
        latelyPathsFile->open( QFile::ReadWrite | QFile::Text  );
        return false;
    }
}


// ==============================+===============================================================
// Private Methods
// Directory traversal

s_ptr<queue<FileInfo>> MainWindow::getAllTargetFiles(const QString &dirName){

    // target Extension을 구하고, trim 한다.
    QStringList targetExtensions = Extension_t.split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
    }

    // 주석을 붙히지 않을 파일 이름의 List
    QStringList excludeList;
    for(int i = 0; i < ExcludeTable_t->rowCount(); i++){
        excludeList.append(ExcludeTable_t->item(i, 0)->text());
    }

    auto workQue = std::make_shared<std::queue<FileInfo>>();

    auto flag = IsRecursiveTraversal_t ?
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
    ts << "\n" << buffer;

}

void MainWindow::processFlag(QTextStream& ts, Flag& flag, bool previewMode){

    if(flag.type.key.trimmed() == "" || flag.type.key == nullptr){
        return;
    }

    if(!previewMode && flag.value.trimmed() == ""){
        return;
    }

    if(FlagTable_t->item(flag.pos, 1)->text() == "1"){

        // div line의 경우
        QString val = flag.type.key;

        if(val == "Sup_Div_Line" || val == "Sub_Div_Line"){

            QStringList list = flag.value.split("\n");

            for(auto line : list){
                ts << line + "\n";
            }
            return;
        }

        // key와 value 사이에 띄어쓰기를 넣을 것인지 여부
        if(flag.type.ExistLineFeed){
            ts << Separator_t + flag.type.key + " : \n" + flag.value;
        }
        else{
            ts << Separator_t + flag.type.key + " : "   + flag.value + "\n";
        }
    }
}

void MainWindow::makeComment(QTextStream& ts, const FileInfo& fileInfo){

    // Run에서 사용하는 경우, fileName이 들어온다
    // isPreviewMode는 함수를 preview tab에서 사용하는 경우 true
    bool isPreviewMode = fileInfo.fileName == nullptr ? true : false;

    QString
            edit    = nullptr,
            desc    = nullptr,
            issue   = nullptr,
            date    = nullptr,
            urls    = nullptr,
            memo    = nullptr;

    edit    = fileInfo.lastModified.toString("yyyy-MM-dd, HH:mm:ss");
    date    = fileInfo.created     .toString("yyyy-MM-dd, HH:mm:ss");
    desc    = *(makeFromTbl(DescTable_t , IsDescNumbering_t , fileInfo));
    issue   = *(makeFromTbl(IssueTable_t, IsIssueNumbering_t, fileInfo));
    urls    = *(makeFromTbl(RefTable_t  , true              , fileInfo));

    auto memoText   = Memo_t;
    auto memos      = memoText.split("\n");

    for(auto& text : memos){
        if(text.trimmed() == "") continue;
        memo.append(Separator_t + "  " + text + "\n");
    }

    if(IsDivByStartEndTag_t) ts << StartTag_t + "\n";

    int loop = static_cast<int>(flagTypeTbl->map.size());

    for(int i = 0; i < loop; i++){
        \
        QString key = flagTypeTbl->map.at(i).key;
        QString value = "";

        if     (key == "Author")         value = Author_t;
        else if(key == "Last_Edited")    value = edit;
        else if(key == "Desc")           value = desc;
        else if(key == "Issue")          value = issue;
        else if(key == "Sup_Div_Line")   value = SupDiv_t;
        else if(key == "Sub_Div_Line")   value = SubDiv_t;
        else if(key == "Email")          value = Email_t;
        else if(key == "Telephone")      value = Telep_t;
        else if(key == "Github_Account") value = GithubAcc_t;
        else if(key == "Ref_URLs")       value = urls;
        else if(key == "Created_Date")   value = date;
        else if(key == "Team")           value = Team_t;
        else if(key == "Memo")           value = memo;
        else if(key == "File_Name")      value = fileInfo.fileName;

        Flag flag =
        {
            i,                      // Tbl  pos
            flagTypeTbl->map.at(i), // Flag Type
            value                   // Flag Value
        };

        processFlag(ts, flag, isPreviewMode);
    }

    if(IsDivByStartEndTag_t) ts << EndTag_t;

}

s_ptr<QString> MainWindow::makeFromTbl(QTableWidget* tbl, bool numbering, const FileInfo& fileInfo){

    auto ret = std::make_shared<QString>();

    if(numbering){

        int hits = 0;
        for(int i = 0; i < tbl->rowCount(); i++){

            auto fName = tbl->item(i, 0)->text();

            if(tbl->item(i, 1)->text().trimmed() == ""){
                continue;
            }

            if(fName == fileInfo.fileName){
                *ret +=
                        Separator_t + "   " +
                        QString::number(++hits) + ". " +
                        tbl->item(i, 1)->text()
                        + "\n";
            }
        }
    }
    else{

        for(int i = 0; i < tbl->rowCount(); i++){

            auto fName = tbl->item(i, 0)->text();

            if(tbl->item(i, 1)->text().trimmed() == ""){
                continue;
            }

            if(fName == fileInfo.fileName){
                *ret +=
                        Separator_t + "   " +
                        tbl->item(i, 1)->text()
                        + "\n";
            }
        }
    }

    return ret;
}



bool MainWindow::removeComment(QStringList &strList){

    if((IsDivByStartEndTag_t && EndTag_t.trimmed() == "") ||
            (IsDivBySeparator_t && Separator_t == "")){
        return false;
    }

    auto targetExtensions = Extension_t.split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
        if(i == ""){
            // 마지막 "" 원소 제거
            strList.pop_back();
        }
    }

    auto flag = IsRecursiveTraversal_t ?
                QDirIterator::IteratorFlag::Subdirectories :
                QDirIterator::IteratorFlag::NoIteratorFlags;

    QDirIterator it(ProjectPath_t, flag);

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


                    auto isEndPoint =
                            [&](QString line) -> bool {
                        if(IsDivByStartEndTag_t){
                            return line.left(EndTag_t.length()) == EndTag_t;
                        }
                        else {
                            return line.left(Separator_t.length()) != Separator_t;
                        }
                    };

                    while(!target.atEnd()){

                        QString line = target.readLine();

                        if(isEndPoint(line)){
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

    if(pathQue->size() < 2){
        ui->menuOpen_Recents->setEnabled(false);
    }

    return true;
}


// ==============================+===============================================================
