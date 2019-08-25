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
#include <QStyleFactory>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// ==============================+===============================================================
// Public Method

MainWindow::MainWindow(char *argv[], QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette;
    applyPalette(palette);

    auto setTable = [](QTableWidget* tbl)-> void {
        tbl->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
        tbl->horizontalHeader()->setStretchLastSection(true);
        tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
    };

    setTable(FlagTable_t);
    setTable(DescTable_t);
    setTable(IssueTable_t);
    setTable(RefTable_t);
    setTable(ExcludeTable_t);

    setAcceptDrops(true);
    setShortCut();
    setToolbar();

    programPath = argv[0];
    execPath    = argv[1];

    pathQue  = new std::deque<QString>();
    sclately = new QFile(QFileInfo(programPath).dir().filePath(PROJECT_LATELY_OPEN_EXT));

    // scps 파일로 프로그램을 open한 경우
    if((execPath != nullptr) && execPath[0] != '\0') {
        clearAllTbls();
        setSCPSFile(QString(execPath));
        return;
    }

    // openRecentPathsFile : sclately에 최근 연 scps의 경로가 있다면 그 파일을 연다.
    if(!openRecentSCPS()){
        // 없다면 NewFile.
        NewFile();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete flagTypeTbl;

    if(sclately != nullptr){

        if(sclately->isOpen()){

            sclately->resize(0);
            QTextStream ts(&(*sclately));
            ts.setCodec("UTF-8");

            int hits = 0;
            while(!pathQue->empty()){

                if(++hits > SAVE_RECENT_PATH){
                    break;
                }

                ts << (pathQue->size() == 1 ? pathQue->front() : pathQue->front() + ",") ;
                pathQue->pop_front();
            }

            sclately->close();
        }
        delete sclately;
        delete pathQue;
    }
}


bool MainWindow::Open(){
    // FileDialog를 생성하고 연다.
    QFileDialog fileOpenDialog;
    fileOpenDialog.setFileMode(QFileDialog::AnyFile);

    QString nameFilter =
            QString ("Open a Setting file (*.") + QString(PROJECT_SETTING_FILE_EXT) + QString(")");

    fileOpenDialog.setNameFilter(nameFilter);
    fileOpenDialog.setViewMode(QFileDialog::Detail);
    fileOpenDialog.open(this, "Open a Setting file");

    // 파일을 선택했을 때
    if(fileOpenDialog.exec()){
        openedFile = fileOpenDialog.selectedFiles()[0];

        // pathQue에 해당 경로가 있는지 확인해 중복되면 큐에 추가하지 않는다.
        if(std::find(pathQue->begin(), pathQue->end(), openedFile) == pathQue->end()){
            pathQue->push_front(openedFile);
        }
    }
    else{
        return false;
    }

    clearAllTbls();
    setSCPSFile(openedFile);
    return true;
}

void MainWindow::OpenRecent(const int index){
    clearAllTbls();
    setSCPSFile(ui->menuOpen_Recents->actions()[index]->text());
}

void MainWindow::Run(){

    if(ProjectPath_t.trimmed() == ""){
        ShowMessageBox(QMessageBox::Critical, "No directory include!", "No directory");
        return;
    }

    // 설정파일이 존재하면 파일을 읽어들여 주석을 지울 파일들의 리스트를 만든다
    auto proj = readSCProjFile(ProjectPath_t + "\\" + PROJECT_WORKED_FILE_EXT);

    if(proj != nullptr){
        removeComment(proj->workedFiles, proj->div, proj->style);
    }

    queue<FileInfo> que  = *(getAllTargetFiles(ProjectPath_t));
    queue<FileInfo> que2 = que;

    while(!que.empty()){
        prependComment(que.front());
        que.pop();
    }

    writeSCProjFile(ProjectPath_t + "\\" + PROJECT_WORKED_FILE_EXT,
                    que2);

    ShowMessageBox(QMessageBox::Information, "work completed!", "Jobs done");
}

void MainWindow::NewFile()
{
    clearAllTbls();
    setWindowTitle(DEFAULT_WIN_TITLE);
    openedFile  = nullptr;
    flagTypeTbl = new FlagTypeTbl;
    flagTypeTbl->init();

    int size = static_cast<int>(flagTypeTbl->map.size());
    for(int i = 0; i < size; i++){
        insertItem(FlagTable_t, false, flagTypeTbl->map.at(i).key, QString::number(1));
    }
}

void MainWindow::ShowMessageBox(const QMessageBox::Icon icon, const QString& message, const QString& title){
    QMessageBox msgBox;
    msgBox.setIcon(icon);
    msgBox.setText(message);
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
    if(openedFile == "") {

        QString nameFilter =
                QString ("Summary Commenter Project Setting (*.") +
                QString(PROJECT_SETTING_FILE_EXT) +
                QString(");;All Files (*)");

        openedFile = QFileDialog::getSaveFileName(this,
                                                    tr("Save setting file"), "",
                                                    nameFilter);

        setWindowTitle(openedFile);
    }

    saveSCPSFile(openedFile);

}

void MainWindow::on_actionOpen_triggered()
{
    Open();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    if(index == TabIndex::TAB_PREVIEW){
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
            QString (PROJECT_SETTING_FILE_EXT) +
            QString (");;All Files (*)");

    openedFile = QFileDialog::getSaveFileName(this,
                                                tr("Save setting file"), "",
                                                nameFilter);

    // 저장을 하지 않고 종료했을 땐, return
    if(openedFile == ""){
        return;
    }

    setWindowTitle(openedFile);

    saveSCPSFile(openedFile);
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

        QString div = IsDivByStartEndTag_t ? EndTag_t : Separator_t;
        CommentStyle style = IsDivByStartEndTag_t ? CommentStyle::DivByStartEndTag : CommentStyle::DivBySeparator;

        if(style == CommentStyle::Undefined || div == ""){
            ShowMessageBox(QMessageBox::Critical, "Essential Input Not Specified!", "Error");
            return;
        }

        removeComment(list, div, style);
    }
    else{
        ShowMessageBox(QMessageBox::Critical, "scproj file not exist!", "Error");
        return;
    }

    scprojFile.remove();
    ShowMessageBox(QMessageBox::Information, "done!", "Complete");
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

void MainWindow::on_actionrecent5_triggered()
{
    OpenRecent(4);
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
        ShowMessageBox(QMessageBox::Critical, "Directory not specified", "Error");
        return;
    }

    QProcess::startDetached("explorer " + ProjectPath_t);
}

void MainWindow::on_actionRefresh_triggered()
{
    clearAllTbls();
    setSCPSFile(openedFile);
}

void MainWindow::on_actionSave_md_triggered()
{
    QFile md(ProjectPath_t + "\\" + "sc_document.md");

    // 파일이 존재하지 않을 땐 경로에 파일을 생성한다.
    md.open(QFile::WriteOnly|QFile::Text);

    QTextStream ts(&md);

    ts << "## Documentations\n";

    ts << "### Description\n";

    exportTblDataToMD(ts, DescTable_t,     "Description");

    ts << "\n### Issue\n";

    exportTblDataToMD(ts, IssueTable_t,    "Issue");

    ts << "\n### Reference\n";

    exportTblDataToMD(ts, RefTable_t,      "Reference");

    md.close();

    ShowMessageBox(QMessageBox::Information, "work done", "done!");
}

void MainWindow::on_actionRemove_Comments_From_All_File_triggered()
{
    int ans = QMessageBox::warning(this, tr("Warning"),
                                   tr("This action removes the comments of all files in the directory\n"
                                      "that are currently set to the program.\n"
                                      "In some cases, it may not work correctly."),
                                   QMessageBox::Yes | QMessageBox::Cancel,
                                   QMessageBox::Yes);

    if(ans == QMessageBox::Cancel){
        return;
    }

    QString div = IsDivByStartEndTag_t ? EndTag_t : Separator_t;
    CommentStyle style = IsDivByStartEndTag_t ? CommentStyle::DivByStartEndTag : CommentStyle::DivBySeparator;

    if(style == CommentStyle::Undefined || div == ""){
        ShowMessageBox(QMessageBox::Critical, "Essential Input Not Specified!", "Error");
        return;
    }

    removeComment(*(new QStringList()), div, style);

    ShowMessageBox(QMessageBox::Information, "done!", "Complete");
}


void MainWindow::on_actionOpen_setting_file_triggered()
{
    if(openedFile == nullptr){
        ShowMessageBox(QMessageBox::Critical, "No files are open", "Error");
        return;
    }

    QProcess::startDetached("notepad.exe " + openedFile);
}

void MainWindow::on_FlagUpBtn_clicked()
{
    QItemSelection selection = FlagTable_t->selectionModel()->selection();

    if(selection.size() == 0) return;

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

    if(selection.size() == 0) return;

    QModelIndexList i = selection[0].indexes();
    int target = i[0].row();

    if(target == static_cast<int>(flagTypeTbl->map.size()) - 1 || selection.count() != 1){
        return;
    }

    itemChange(FlagTable_t, target, target + 1);
    flagTypeTbl->swap(target, target + 1);
    FlagTable_t->selectRow(target + 1);
}

void MainWindow::on_actionNew_triggered()
{
    NewFile();
}

void MainWindow::on_FlagAddBtn_clicked()
{
    insertTbl(FlagTable_t, "flag" , "");
}

void MainWindow::on_FlagDeleteBtn_clicked()
{
    removeSelectedItems(FlagTable_t);
}

// ==============================+===============================================================
// Private Methods
// Init, set program

void MainWindow::setToolbar()
{
    QActionGroup* modeGroup = new QActionGroup(ui->menuComments_style);
    modeGroup->setExclusive(true);

    divBySeparator = ui->menuComments_style->addAction("Divide by Separator");
    divBySeparator->setCheckable(true);
    divBySeparator->setChecked(true);
    modeGroup->addAction(divBySeparator);

    divByStartEndTag = ui->menuComments_style->addAction("Divide by Start End tag");
    divByStartEndTag->setCheckable(true);
    modeGroup->addAction(divByStartEndTag);
}

void MainWindow::applyPalette(QPalette &palette)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

    palette.setColor(QPalette::Window,          QColor(33,33,33));
    palette.setColor(QPalette::WindowText,      Qt::white);
    palette.setColor(QPalette::Base,            QColor(61,61,61));
    palette.setColor(QPalette::AlternateBase,   QColor(61,61,61));
    palette.setColor(QPalette::ToolTipBase,     Qt::white);
    palette.setColor(QPalette::ToolTipText,     Qt::white);
    palette.setColor(QPalette::Text,            Qt::white);
    palette.setColor(QPalette::Button,          QColor(33,33,33));
    palette.setColor(QPalette::ButtonText,      Qt::white);
    palette.setColor(QPalette::BrightText,      Qt::red);
    palette.setColor(QPalette::Highlight,       QColor(148, 250, 255));
    palette.setColor(QPalette::HighlightedText, Qt::black);

    palette.setColor(QPalette::Disabled, QPalette::Text,        Qt::darkGray);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText,  Qt::darkGray);

    qApp->setPalette(palette);
}

// ==============================+===============================================================
// Private Methods
// Setting Tables

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

    // Add
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->descAddBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->issueAddBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->addReferenceBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->addExcludeBtn);
    bindKey(QKeySequence(Qt::Key_Plus)        , ui->FlagAddBtn);

    // Remove
    bindKey(QKeySequence::Delete              , ui->descRemoveBtn);
    bindKey(QKeySequence::Delete              , ui->issueRemoveBtn);
    bindKey(QKeySequence::Delete              , ui->rmReferenceBtn);
    bindKey(QKeySequence::Delete              , ui->rmExcludeBtn);
    bindKey(QKeySequence::Delete              , ui->FlagDeleteBtn);

    // Sort
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->descSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->issueSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->referenceSortBtn);
    bindKey(QKeySequence(Qt::CTRL + Qt::Key_T), ui->sortExcludeBtn);

    // Copy
    bindKey(QKeySequence(Qt::Key_C)           , ui->copyBtn);

    // Up, Down
    bindKey(QKeySequence(Qt::Key_Up)          , ui->FlagUpBtn);
    bindKey(QKeySequence(Qt::Key_Down)        , ui->FlagDownBtn);

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

void MainWindow::clearAllTbls()
{
    flagTypeTbl = new FlagTypeTbl;

    auto clearTbl = [](QTableWidget* tbl) -> void {
        tbl->setRowCount(0);
    };

    clearTbl(FlagTable_t);
    clearTbl(IssueTable_t);
    clearTbl(DescTable_t);
    clearTbl(RefTable_t);
    clearTbl(ExcludeTable_t);
}

// ==============================+===============================================================
// Private Methods
// Setting Table's dragging event

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    handleDrop(e->mimeData()->urls());
}

void MainWindow::handleDrop(const QList<QUrl> & list)
{
    foreach (const QUrl &url, list) {

        QString localPath = url.toLocalFile();
        QFileInfo fi(localPath);

        if(fi.isDir()){
            QList<QUrl> newList;
            QDirIterator it(QDir(localPath), QDirIterator::IteratorFlag::Subdirectories);
            while(true){

                if(!it.fileInfo().isDir() && it.filePath() != ""){
                    newList.append(QUrl::fromLocalFile(it.filePath()));
                }

                if(!it.hasNext()) break;
                it.next();
            }
            handleDrop(newList);
        }

        else if(fi.isFile()){

            // 지정한 확장자에 해당하는 파일만 가져온다.
            QRegularExpression re(".[.](?<Ext>\\w+)");

            auto match = re.match(fi.fileName(), 0, QRegularExpression::NormalMatch);

            if(match.captured("Ext") != "" && Extension_t.contains(match.captured("Ext"))){

                switch(ui->tabWidget->currentIndex()){

                case TabIndex::TAB_DESCRIPT:   insertTbl(DescTable_t,    url.fileName(), "");
                    break;

                case TabIndex::TAB_ISSUE:      insertTbl(IssueTable_t,   url.fileName(), "");
                    break;

                case TabIndex::TAB_REF:        insertTbl(RefTable_t,     url.fileName(), "");
                    break;

                case TabIndex::TAB_EXCLUDE:    insertTbl(ExcludeTable_t, url.fileName());
                    break;

                };
            }
        }
    }
}

// ==============================+===============================================================
// Private Methods
// Handle Tables

// key를 String input으로 받고 해당하는 row의 value item을 반환한다
QTableWidgetItem* MainWindow::searchTable(QTableWidget* table, const QString& key){
    for(int i = 0;  i < table->rowCount(); i++){
        if(table->item(i, 0)->text() == key){
            return table->item(i, 1);
        }
    }
    return nullptr;
}

void MainWindow::insertItem(QTableWidget* tbl, bool keyEditable, const QString& item){

    int row =   tbl->rowCount();
    tbl->insertRow(row);

    // key
    auto keyColumn      = new QTableWidgetItem(item);

    if(!keyEditable){
        keyColumn->setFlags(keyColumn->flags() & ~Qt::ItemIsEditable);
    }

    tbl->setItem(row, 0, keyColumn);
}

void MainWindow::insertItem(QTableWidget* tbl, bool keyEditable,
                            const QString& key, const QString& value){

    int row =   tbl->rowCount();
    tbl->insertRow(row);

    // key, value
    auto keyColumn      = new QTableWidgetItem(key);
    auto valueColumn    = new QTableWidgetItem(value);

    if(!keyEditable){
        keyColumn->setFlags(keyColumn->flags() & ~Qt::ItemIsEditable);
    }

    tbl->setItem(row, 0, keyColumn);
    tbl->setItem(row, 1, valueColumn);

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
// Handle SCPS file

void MainWindow::setSCPSFile(const QString& settingFilePath){

    setWindowTitle(settingFilePath);

    int flagHits = 0;

    bool errFlag = false;

    openedFile = settingFilePath;

    QFile selectFile(openedFile);

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

        QRegularExpression descRe("(?<attKey>.+[.]?\\w+)::desc\\s+[+][=]\\s+\"(?<attValue>.*)\"");

        auto descMatch = descRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(descMatch.hasMatch()){
            insertItem(DescTable_t, true,
                       descMatch.captured("attKey"), descMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("(?<attKey>.+[.]?\\w+)::issue\\s+[+][=]\\s+\"(?<attValue>.*)\"");

        auto issueMatch = issueRe.match(confQueue->front(), 0,
                                        QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){
            insertItem(IssueTable_t, true,
                       issueMatch.captured("attKey"), issueMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("(?<attKey>.+[.]?\\w+)::refURLs\\s+[+][=]\\s+\"(?<attValue>.*)\"");

        auto refURLsMatch = refURLRe.match(confQueue->front(), 0,
                                           QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){
            insertItem(RefTable_t, true,
                       refURLsMatch.captured("attKey"), refURLsMatch.captured("attValue"));

            confQueue->pop();
            continue;
        }

        // Excluded files

        QRegularExpression excludingRe("(?<attKey>.+[.]?\\w+)::exclude");

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
        ShowMessageBox(QMessageBox::Warning, "Setting file could contain syntax error", "Caution");
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
    ts << "global.Project_Name     =  \"" <<   ProjectName_t    << "\"\n";

    ts << "\n# Desc\n";

    for(int i = 0; i < DescTable_t->rowCount(); i++){

        // qDebug() << DescTable_t->item(i, 1)->text();

        QStringList list = DescTable_t->item(i, 1)->text().split("\n");

        for (auto& desc : list){
            ts << DescTable_t->item(i, 0)->text() + "::desc       +=       \""
                  + desc << "\"\n";
        }
    }

    ts << "\n# Issue\n";

    for(int i = 0; i < IssueTable_t->rowCount(); i++){

        QStringList list = IssueTable_t->item(i, 1)->text().split("\n");

        for (auto& issue : list){
            ts << IssueTable_t->item(i, 0)->text() + "::issue       +=       \""
                  + issue << "\"\n";
        }
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < RefTable_t->rowCount(); i++){

        QStringList list = RefTable_t->item(i, 1)->text().split("\n");

        for (auto& url : list){
            ts << RefTable_t->item(i, 0)->text() + "::refURLs       +=       \""
                  + url << "\"\n";
        }

    }

    ts << "\n# Excluded files\n";

    for (int i = 0; i < ExcludeTable_t->rowCount(); i++){
        ts << ExcludeTable_t->item(i, 0)->text() + "::exclude\n";
    }

    openedFile = path;

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
    if(key == "Project_Name"){
       ui->projectNameEdit->setText(value);
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
        divBySeparator->setChecked(flag);
    }
    else if (flagName   == "divByStartEndTag"){
        divByStartEndTag->setChecked(flag);
    }
    else {
        qDebug() << "Wrong Setting value";
    }
}

// ==============================+===============================================================
// Private Methods
// Handle SClately file

bool MainWindow::openRecentSCPS()
{
    clearAllTbls();

    QString latest = nullptr;

    if(sclately->exists()){

        sclately->open( QFile::ReadWrite | QFile::Text  );

        QString fileContent = sclately->readLine();

        QStringList list = fileContent.split(",");

        latest = list[0];

        for(auto& path : list){
            if(path == "") continue;
            pathQue->push_back( path );
        }

        applyRecentBar(list);

        if(latest.trimmed() == "") return false;

        setSCPSFile(latest);

        return true;
    }
    else{
        sclately->open( QFile::ReadWrite | QFile::Text  );

        QStringList empty{};

        applyRecentBar(empty);

        return false;
    }
}

void MainWindow::applyRecentBar(QStringList &list)
{
    auto actionList = ui->menuOpen_Recents->actions();

    int index = 0;

    for (auto& action : actionList){
        if(list.length() <= index || list[index].trimmed() == "") {
            action->setVisible( false );
        }
        else{
            action->setText( list[index++] );
        }
    }
}

// ==============================+===============================================================
// Private Methods
// Handle SCProj file

s_ptr<Scproj> MainWindow::readSCProjFile(const QString &path){

    QFile scprojFile(path);

    if(!scprojFile.exists()){
        return nullptr;
    }

    scprojFile.open(QFile::ReadOnly|QFile::Text);

    s_ptr<Scproj> result = std::make_shared<Scproj>();

    result->style = CommentStyle::Undefined;

    while(!scprojFile.atEnd()){

        QString line = scprojFile.readLine();

        QRegularExpression sepRe("DivBySeparator:\\s*\"(?<sep>.*)\"");

        auto sepMatch = sepRe.match(line, 0,
                                      QRegularExpression::NormalMatch);

        if(sepMatch.hasMatch()){

            result->div = sepMatch.captured("sep");
            result->style = CommentStyle::DivBySeparator;
        }

        QRegularExpression endTagRe("DivByStartEndTag_t:\\s*\"(?<tag>.*)\"");

        auto tagMatch = endTagRe.match(line, 0,
                                      QRegularExpression::NormalMatch);

        if(tagMatch.hasMatch()){

            result->div = tagMatch.captured("tag");
            result->style = CommentStyle::DivByStartEndTag;
        }

        QRegularExpression workedFileRe(":\\s*\"(?<files>.*)\"");

        auto fileMatch = workedFileRe.match(line, 0,
                                      QRegularExpression::NormalMatch);

        if(fileMatch.hasMatch()){
            result->workedFiles = fileMatch.captured("files").split(",");
        }
    }

    scprojFile.close();

    return result;
}

void MainWindow::writeSCProjFile(const QString &path, queue<FileInfo>& workedFilesQue)
{
    QFile scprojFile(path);

    scprojFile.open(QIODevice::WriteOnly|QFile::Text);

    QString workedFiles = "";

    while(!workedFilesQue.empty()){
        // prepend 할 때 마다 workedFiles에 추가
        workedFiles += workedFilesQue.size() == 1 ?
                    workedFilesQue.front().fileName : workedFilesQue.front().fileName + ",";
        workedFilesQue.pop();
    }

    // 작업 방식
    scprojFile.write("# Worked_Method\n");

    QString method;

    if(IsDivBySeparator_t){
        method = QString("DivBySeparator: \"")     + QString(Separator_t) + QString("\"\n");
    }
    else if(IsDivByStartEndTag_t){
        method = QString("DivByStartEndTag_t: \"") + QString(EndTag_t)    + QString("\"\n");
    }

    scprojFile.write(method.toStdString().c_str());

    // 작업한 파일들
    scprojFile.write("\n# Worked_Files\n");

    QString worked = QString(": \"") + workedFiles + QString("\"\n");

    scprojFile.write(worked.toStdString().c_str());

    scprojFile.close();
}

// ==============================+===============================================================
// Private Methods
// Handle Other Files

void MainWindow::exportTblDataToMD(QTextStream& ts, const QTableWidget *tbl, const QString &tblName)
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

    QString key = flag.type.key;
    key.replace("_", " ");

    if(key.trimmed() == "" || key == nullptr){
        return;
    }

    if(!previewMode && flag.value.trimmed() == ""){
        return;
    }

    if(FlagTable_t->item(flag.pos, 1)->text() == "1"){

        // div line의 경우
        if(key == "Sup Div Line" || key == "Sub Div Line"){

            QStringList list = flag.value.split("\n");

            for(auto line : list){
                ts << line + "\n";
            }
            return;
        }

        // key와 value 사이에 띄어쓰기를 넣을 것인지 여부
        if(flag.type.existLineFeed){
            ts << Separator_t + key + " : \n" + flag.value;
        }
        else{
            ts << Separator_t + key + " : "   + flag.value + "\n";
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

    if(IsDivByStartEndTag_t && StartTag_t.trimmed() != "") ts << StartTag_t + "\n";

    int loop = static_cast<int>(flagTypeTbl->map.size());

    for(int i = 0; i < loop; i++){
        \
        QString key = flagTypeTbl->map.at(i).key;
        QString value = "";

        if     (key == "Author")         value = Author_t;
        else if(key == "Last_Edited")    value = edit;
        else if(key == "Desc")           value = desc;
        else if(key == "Issue")          value = issue;
        else if(key == "Sup_Div_Line")   value = IsDivBySeparator_t ? Separator_t + SupDiv_t : SupDiv_t;
        else if(key == "Sub_Div_Line")   value = IsDivBySeparator_t ? Separator_t + SubDiv_t : SubDiv_t;
        else if(key == "Email")          value = Email_t;
        else if(key == "Telephone")      value = Telep_t;
        else if(key == "Github_Account") value = GithubAcc_t;
        else if(key == "Ref_URLs")       value = urls;
        else if(key == "Created_Date")   value = date;
        else if(key == "Team")           value = Team_t;
        else if(key == "Memo")           value = memo;
        else if(key == "File_Name")      value = fileInfo.fileName;
        else if(key == "Project_Name")   value = ProjectName_t;

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



void MainWindow::removeComment(QStringList &strList, const QString& div, const CommentStyle style){

    auto targetExtensions = Extension_t.split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
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
                        if      (style == CommentStyle::DivByStartEndTag){
                            return line.left(div.length()) == div;
                        }
                        else if (style == CommentStyle::DivBySeparator){
                            return line.left(div.length()) != div;
                        }
                        else{
                            qDebug() << "problem occured in removeComment";
                            return true;
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

}


// ==============================+===============================================================

