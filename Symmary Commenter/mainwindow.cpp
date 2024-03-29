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
    if(!applyFonts()) ShowMessageBox(QMessageBox::Critical, "Font file not found", "Error");

    setTables();
    setAcceptDrops(true);
    setShortCut();
    setToolbar();

    programPath = argv[0];
    execPath    = argv[1];

    pathQue  = new std::deque<QString>();
    sclately = new QFile(QFileInfo(programPath).dir().filePath(PROJECT_LATELY_OPEN_EXT));

    DescSearchBar     ->installEventFilter(this);
    IsseSearchBar     ->installEventFilter(this);
    ui->descLargeEdit ->installEventFilter(this);
    ui->issueLargeEdit->installEventFilter(this);

    connect(DescTable_t,  SIGNAL(cellClicked(int, int)), this, SLOT(on_tableItemClickedked(int,int)));
    connect(IssueTable_t, SIGNAL(cellClicked(int, int)), this, SLOT(on_tableItemClickedked(int,int)));

    // scps 파일로 프로그램을 open한 경우
    if((execPath != nullptr) && execPath[0] != '\0') {
        clearAllTbls();
        setSCPSFile(QString(execPath));
        QStringList list = readSClately();
        applyRecentBar(list);
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


auto MainWindow::Open() -> bool {
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

    // 작업할 디렉토리가 명시되지 않은 경우
    if(ProjectPath_t.trimmed() == ""){
        ShowMessageBox(QMessageBox::Critical, "No directory include!", "No directory");
        return;
    }

    // 작업에 필수적인 값이 빠져 있는 경우
    if((IsDivBySeparator_t && Separator_t == "") || (IsDivByStartEndTag_t && EndTag_t.trimmed() == "")){
        ShowMessageBox(QMessageBox::Critical, "Required value is missing", "Error");
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
    insertTbl(DescTable_t, "fileName." + exts[0], "", true);
}

void MainWindow::on_descRemoveBtn_clicked()
{
    removeSelectedItems(DescTable_t);
}

void MainWindow::on_issueAddBtn_clicked()
{
    QStringList exts = Extension_t.split(",");
    insertTbl(IssueTable_t, "fileName." + exts[0], "", true);
}

void MainWindow::on_issueRemoveBtn_clicked()
{
    removeSelectedItems(IssueTable_t);
}

void MainWindow::on_addReferenceBtn_clicked()
{
    QStringList exts = Extension_t.split(",");
    insertTbl(RefTable_t, "fileName." + exts[0], "", true);
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

    ui->descLargeEdit->clear();
    ui->issueLargeEdit->clear();

    switch (index) {
    // preview 탭이 클릭되면 preview에 들어갈 텍스트를 계산
    case TabIndex::TAB_PREVIEW:{
        QString text = "";

        QTextStream ts(&text);

        makeComment(ts, {});

        ui->previewTextEdit->setPlainText(text);
        break;
    }
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

        auto proj = readSCProjFile(ProjectPath_t + "\\" + PROJECT_WORKED_FILE_EXT);

        if(proj->style == CommentStyle::Undefined || proj->div == ""){
            ShowMessageBox(QMessageBox::Critical, "Essential Input Not Specified!", "Error");
            return;
        }

        removeComment(proj->workedFiles, proj->div, proj->style);
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

    QString         div = IsDivByStartEndTag_t ? EndTag_t : Separator_t;
    CommentStyle  style = IsDivByStartEndTag_t ? CommentStyle::DivByStartEndTag : CommentStyle::DivBySeparator;

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

void MainWindow::on_descAutoImtBtn_clicked()
{
    addAllItemBtnClicked();
}

void MainWindow::on_issueAutoImtBtn_clicked()
{
    addAllItemBtnClicked();
}

void MainWindow::on_refAutoImtBtn_clicked()
{
    addAllItemBtnClicked();
}

void MainWindow::on_actionHelp_triggered()
{
    system("start chrome /new-window https://github.com/jopemachine/Summary-Commenter/blob/master/README.md");
}

void MainWindow::on_tableItemClickedked(int row, int col)
{
    switch(ui->tabWidget->currentIndex()){

        case TabIndex::TAB_DESCRIPT:{
             QString selectedText_desc = static_cast<QPlainTextEdit*>(DescTable_t->cellWidget(row, 1))->toPlainText();
             ui->descLargeEdit->setPlainText(selectedText_desc);
             break;
        }

        case TabIndex::TAB_ISSUE:{
             QString selectedText_issue = static_cast<QPlainTextEdit*>(IssueTable_t->cellWidget(row, 1))->toPlainText();
             ui->issueLargeEdit->setPlainText(selectedText_issue);
             break;
        }
    }
}


// ==============================+===============================================================
// Private Methods
// Init, set program

bool MainWindow::eventFilter(QObject* obj, QEvent* e)
{
    if     (obj == DescSearchBar){
        if(e->type() == QEvent::KeyPress){
            QKeyEvent* kEvent = static_cast<QKeyEvent*>(e);
            if(kEvent->key() == Qt::Key_Enter || kEvent->key() == Qt::Key_Return){

                  showSearchResDial(searchTbl(DescTable_t, DescSearchBar->text()));
                  return true;
            }
        }
    }
    else if(obj == IsseSearchBar){
        if(e->type() == QEvent::KeyPress){
            QKeyEvent* kEvent = static_cast<QKeyEvent*>(e);
            if(kEvent->key() == Qt::Key_Enter || kEvent->key() == Qt::Key_Return){

                  showSearchResDial(searchTbl(IssueTable_t, IsseSearchBar->text()));
                  return true;
            }
        }
    }
    else if(obj == ui->descLargeEdit){
        if(e->type() == QEvent::KeyPress){
            QKeyEvent* kEvent = static_cast<QKeyEvent*>(e);
            if(kEvent->key() == Qt::Key_Enter || kEvent->key() == Qt::Key_Return){
                int row = DescTable_t->selectedItems()[0]->row();
                QPlainTextEdit* edit = static_cast<QPlainTextEdit*>(DescTable_t->cellWidget(row, 1));
                edit->setPlainText(ui->descLargeEdit->toPlainText());
            }
            else if(kEvent->key() == Qt::Key_Backspace){
                int row = DescTable_t->selectedItems()[0]->row();
                QPlainTextEdit* edit = static_cast<QPlainTextEdit*>(DescTable_t->cellWidget(row, 1));
                edit->setPlainText(ui->descLargeEdit->toPlainText().left(ui->descLargeEdit->toPlainText().length() - 1));
            }
        }
    }
    else if(obj == ui->issueLargeEdit){
        if(e->type() == QEvent::KeyPress){
            QKeyEvent* kEvent = static_cast<QKeyEvent*>(e);
            if(kEvent->key() == Qt::Key_Enter || kEvent->key() == Qt::Key_Return){
                int row = IssueTable_t->selectedItems()[0]->row();
                QPlainTextEdit* edit = static_cast<QPlainTextEdit*>(IssueTable_t->cellWidget(row, 1));
                edit->setPlainText(ui->issueLargeEdit->toPlainText());
            }
            else if(kEvent->key() == Qt::Key_Backspace){
                int row = IssueTable_t->selectedItems()[0]->row();
                QPlainTextEdit* edit = static_cast<QPlainTextEdit*>(IssueTable_t->cellWidget(row, 1));
                edit->setPlainText(ui->issueLargeEdit->toPlainText().left(ui->issueLargeEdit->toPlainText().length() - 1));
            }

        }
    }

    return false;
}

void MainWindow::addAllItemBtnClicked()
{
    QStringList allTargetFiles;

    queue<FileInfo> que  = *(getAllTargetFiles(ProjectPath_t));

    while(!que.empty()){
        allTargetFiles.push_back(que.front().filePath);
        que.pop();
    }

    handleDrop(allTargetFiles);
}

void MainWindow::setTables()
{
    QList<int> spliterSizes;
    spliterSizes << 100 << 145 << 200;

    FlagTable_t->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    FlagTable_t->horizontalHeader()->setStretchLastSection(true);
    FlagTable_t->setSelectionBehavior(QAbstractItemView::SelectRows);
    FlagTable_t->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    DescTable_t->horizontalHeader()->setStretchLastSection(true);
    DescTable_t->setSelectionBehavior(QAbstractItemView::SelectRows);
    DescTable_t->verticalHeader()->setDefaultSectionSize(60);
    DescTable_t->setColumnWidth(0, 250);
    DescTable_t->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->descEditSpliter->setSizes(spliterSizes);

    IssueTable_t->horizontalHeader()->setStretchLastSection(true);
    IssueTable_t->setSelectionBehavior(QAbstractItemView::SelectRows);
    IssueTable_t->verticalHeader()->setDefaultSectionSize(60);
    IssueTable_t->setColumnWidth(0, 250);
    IssueTable_t->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->issueSplitter->setSizes(spliterSizes);

    RefTable_t->horizontalHeader()->setStretchLastSection(true);
    RefTable_t->setSelectionBehavior(QAbstractItemView::SelectRows);
    RefTable_t->verticalHeader()->setDefaultSectionSize(60);
    RefTable_t->setColumnWidth(0, 250);
    RefTable_t->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ExcludeTable_t->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ExcludeTable_t->horizontalHeader()->setStretchLastSection(true);
    ExcludeTable_t->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::setToolbar()
{
    QFont font("Consolas");
    // Exclusive한 라디오 버튼 그룹을 만들기 위한 메서드
    QActionGroup* modeGroup = new QActionGroup(ui->menuComments_style);
    modeGroup->setExclusive(true);

    divBySeparator = ui->menuComments_style->addAction("Divide by Separator");
    divBySeparator->setCheckable(true);
    divBySeparator->setChecked(true);
    divBySeparator->setFont(font);
    modeGroup->addAction(divBySeparator);

    divByStartEndTag = ui->menuComments_style->addAction("Divide by Start End tag");
    divByStartEndTag->setCheckable(true);
    divBySeparator->setFont(font);
    modeGroup->addAction(divByStartEndTag);

    ui->menuComments_style->setFont(font);
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

bool MainWindow::applyFonts()
{
    // 외부 폰트 로드 및 적용
    QFile fontFile("./res/fonts/JejuGothic.ttf");

    QFileInfo info(fontFile);
//    qDebug() << fontFile.fileName();
//    qDebug() << info.absolutePath();

//  ShowMessageBox(QMessageBox::Critical, info.absolutePath(), "1");

    if(!fontFile.exists()) return false;

    int id = QFontDatabase::addApplicationFont(fontFile.fileName());
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QFont
            tblItemFont(family),
            largeEditFont(family),
            settingTabFont(family),
            tabBarFont(family),
            previewFont("Consolas");

    tblItemFont.setPointSize(10);
    settingTabFont.setPointSize(10);
    largeEditFont.setPointSize(11);
    tabBarFont.setPointSize(9);
    previewFont.setPointSize(10);

    ui->SettingTab->setFont(settingTabFont);
    FlagTable_t->setFont(tblItemFont);
    DescTable_t->setFont(tblItemFont);
    ui->descLargeEdit->setFont(largeEditFont);
    IssueTable_t->setFont(tblItemFont);
    ui->issueLargeEdit->setFont(largeEditFont);
    RefTable_t->setFont(tblItemFont);
    ExcludeTable_t->setFont(tblItemFont);

    ui->tabWidget->setFont(tabBarFont);
    ui->PreviewTab->setFont(previewFont);

    return true;
}

// ==============================+===============================================================
// Private Methods
// Setting Tables

void MainWindow::sortTbl(QTableWidget *tbl){
    tbl->sortByColumn(0, Qt::AscendingOrder);
}

void MainWindow::insertTbl(QTableWidget *tbl, const QString& key, const QString& value, bool isMultiline){
    if(isMultiline){
        insertMultiLineItem(tbl, true, key, value);
    }
    else{
        insertItem(tbl, true, key, value);
    }

    tbl->selectRow(tbl->rowCount() - 1);

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

    // Up, Down
    bindKey(QKeySequence(Qt::Key_Up)          , ui->FlagUpBtn);
    bindKey(QKeySequence(Qt::Key_Down)        , ui->FlagDownBtn);

    // Auto Import
    bindKey(QKeySequence(Qt::Key_F6)          , ui->descAutoImtBtn);
    bindKey(QKeySequence(Qt::Key_F6)          , ui->issueAutoImtBtn);
    bindKey(QKeySequence(Qt::Key_F6)          , ui->refAutoImtBtn);

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

void MainWindow::dragEnterEvent(QDragEnterEvent* e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent* e)
{
    QStringList strList;
    QList<QUrl> list = e->mimeData()->urls();

    // QList<> to QStringList
    foreach (const QUrl &url, list) {
        strList.push_back(url.toLocalFile());
    }

    handleDrop(strList);
}

void MainWindow::handleDrop(const QStringList& list)
{
    foreach (const QString& localPath, list) {

        QFileInfo fi(localPath);

        if(fi.isDir()){
            QStringList newList;
            QDirIterator it(QDir(localPath), QDirIterator::IteratorFlag::Subdirectories);
            while(true){

                if(!it.fileInfo().isDir() && it.filePath() != ""){
                    newList.push_back(it.filePath());
                }

                if(!it.hasNext()) break;
                it.next();
            }
            handleDrop(newList);
        }

        else if(fi.isFile()){

            // 지정한 확장자에 해당하는 파일만 가져온다.

            QRegularExpression re("."               // file Name
                                  "[.]"             // file Name.Ext
                                  "(?<Ext>\\w+)");  // extract Ext

            auto match = re.match(fi.fileName(), 0, QRegularExpression::NormalMatch);

            if(match.captured("Ext") != "" && Extension_t.contains(match.captured("Ext"))){

                switch(ui->tabWidget->currentIndex()){

                case TabIndex::TAB_DESCRIPT:
                    if(!isDuplicateItem(DescTable_t,    fi.fileName()))
                    insertTbl(DescTable_t,    fi.fileName(), "", true);
                    break;

                case TabIndex::TAB_ISSUE:
                    if(!isDuplicateItem(IssueTable_t,   fi.fileName()))
                    insertTbl(IssueTable_t,   fi.fileName(), "", true);
                    break;

                case TabIndex::TAB_REF:
                    if(!isDuplicateItem(RefTable_t,     fi.fileName()))
                    insertTbl(RefTable_t,     fi.fileName(), "", true);
                    break;

                case TabIndex::TAB_EXCLUDE:
                    if(!isDuplicateItem(ExcludeTable_t, fi.fileName()))
                    insertTbl(ExcludeTable_t, fi.fileName());
                    break;

                };
            }
        }
    }
}

// ==============================+===============================================================
// Private Methods
// Handle Tables

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

void MainWindow::insertMultiLineItem(QTableWidget *tbl, bool keyEditable, const QString &key, const QString &value)
{
    int row =   tbl->rowCount();
    tbl->insertRow(row);

    // key, value
    auto keyColumn      = new QTableWidgetItem(key);

    if(!keyEditable){
        keyColumn->setFlags(keyColumn->flags() & ~Qt::ItemIsEditable);
    }

    tbl->setItem(row, 0, keyColumn);

    QPlainTextEdit *edit = new QPlainTextEdit();
    edit->setPlainText(value);
    edit->setFrameStyle(QFrame::NoFrame);
    tbl->setCellWidget(row, 1, edit);
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

bool MainWindow::isDuplicateItem(QTableWidget *tbl, const QString &item)
{
    for(int i = 0; i < tbl->rowCount(); i++){
        if(tbl->item(i, 0)->text() == item){
            return true;
        }
    }

    return false;
}

// ==============================+===============================================================
// Private Methods
// Handle SCPS file

void MainWindow::setSCPSFile(const QString& settingFilePath){

    ui->tabWidget->setCurrentIndex(TabIndex::TAB_GLOBAL);

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

    bool isBuffering         = false;
    QString strKeyBuf        = "";
    QString strValueBuf      = "";
    QTableWidget* buffed_tbl = nullptr;

    while(!confQueue->empty()){

        // 주석 및 빈줄은 생략
        if(!isBuffering && (confQueue->front().trimmed() == "" || confQueue->front().at(0) == "#")){
            confQueue->pop();
            continue;
        }

        // 버퍼링 상태에선 끝을 알리는 "가 언제 오는지 확인
        if(isBuffering){
            QRegularExpression isEndRe("(?<buf>.*)\"");

            auto isEnd = isEndRe.match(confQueue->front(), 0,
                                       QRegularExpression::NormalMatch);

            if(isEnd.hasMatch()){

                isBuffering = false;
                strValueBuf += isEnd.captured("buf");
                insertMultiLineItem(buffed_tbl, true, strKeyBuf, strValueBuf);

                //strBuf 사용 후 초기화
                strKeyBuf   = "";
                strValueBuf = "";
                buffed_tbl  = nullptr;
            }
            else{
                strValueBuf += confQueue->front() + "\n";
            }

            confQueue->pop();

            continue;
        }

        // Setting
        QRegularExpression settingRe("setting[.]"            // setting.
                                     "(?<attKey>\\w+)\\s+"   // setting.key
                                     "[=]\\s+"               // =
                                     "(?<attValue>.+)");     // value

        auto settingMatch = settingRe.match(confQueue->front(), 0,
                                            QRegularExpression::NormalMatch);

        if(settingMatch.hasMatch()){
            setSettingFlags(settingMatch.captured("attKey"), settingMatch.captured("attValue").toInt());
            confQueue->pop();
            continue;
        }

        // Flag Setting

        QRegularExpression flagRe("flag[.]"
                                  "(?<attKey>\\w+)\\s+"
                                  "[=]\\s+"
                                  "(?<attValue>.+)");

        auto flagMatch = flagRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(flagMatch.hasMatch()){
            // 읽은 순서대로 flagTypeTbl에 기록하고, 테이블에 추가
            bool LineFeed = false;
            if(flagMatch.captured("attKey") == "Desc" || flagMatch.captured("attKey") == "Issue" ||
                    flagMatch.captured("attKey") == "Memo" || flagMatch.captured("attKey") == "Ref_URLs"){
                LineFeed = true;
            }

            flagTypeTbl->map.insert({ flagHits++, { flagMatch.captured("attKey"), LineFeed }});

            insertItem(FlagTable_t, false, flagMatch.captured("attKey"), flagMatch.captured("attValue"));
            confQueue->pop();
            continue;
        }

        // Global Setting

        QRegularExpression globalRe("global[.]"
                                    "(?<attKey>\\w+)\\s+"
                                    "[=]\\s+"
                                    "\"(?<attValue>.*)\"");

        auto globalMatch = globalRe.match(confQueue->front(), 0,
                                          QRegularExpression::NormalMatch);

        if(globalMatch.hasMatch()){
            addGlobalVars(globalMatch.captured("attKey"), globalMatch.captured("attValue"));
            confQueue->pop();
            continue;
        }

        // Desc Setting

        QRegularExpression descRe("(?<attKey>.*)"
                                  "::desc\\s+"
                                  "[+][=]\\s+"
                                  "\"(?<attValue>.*)\"?");

        auto descMatch = descRe.match(confQueue->front(), 0,
                                      QRegularExpression::NormalMatch);

        if(descMatch.hasMatch()){

            QString val = descMatch.captured("attValue");

            if(val.at(val.length() - 1) == "\""){
                insertMultiLineItem(DescTable_t, true,
                           descMatch.captured("attKey"), val.left(val.length() - 1));
            }
            else{
                isBuffering = true;
                buffed_tbl  = DescTable_t;
                strKeyBuf   = descMatch.captured("attKey");
                strValueBuf = descMatch.captured("attValue") + "\n";
            }

            confQueue->pop();
            continue;
        }

        // Issue Setting

        QRegularExpression issueRe("(?<attKey>.*)"
                                   "::issue\\s+"
                                   "[+][=]\\s+"
                                   "\"(?<attValue>.*)\"?");

        auto issueMatch = issueRe.match(confQueue->front(), 0,
                                        QRegularExpression::NormalMatch);

        if(issueMatch.hasMatch()){

            QString val = issueMatch.captured("attValue");

            if(val.at(val.length() - 1) == "\""){
                insertMultiLineItem(IssueTable_t, true,
                           issueMatch.captured("attKey"), val.left(val.length() - 1));
            }
            else{
                isBuffering = true;
                buffed_tbl  = IssueTable_t;
                strKeyBuf   = issueMatch.captured("attKey");
                strValueBuf = issueMatch.captured("attValue") + "\n";
            }

            confQueue->pop();
            continue;
        }

        // Reference URLs Setting

        QRegularExpression refURLRe("(?<attKey>.*)"
                                    "::refURLs\\s+"
                                    "[+][=]\\s+"
                                    "\"(?<attValue>.*)\"?");

        auto refURLsMatch = refURLRe.match(confQueue->front(), 0,
                                           QRegularExpression::NormalMatch);

        if(refURLsMatch.hasMatch()){

            QString val = refURLsMatch.captured("attValue");

            if(val.at(val.length() - 1) == "\""){
                insertMultiLineItem(RefTable_t, true,
                           refURLsMatch.captured("attKey"), val.left(val.length() - 1));
            }
            else{
                isBuffering = true;
                buffed_tbl  = RefTable_t;
                strKeyBuf   = refURLsMatch.captured("attKey");
                strValueBuf = refURLsMatch.captured("attValue") + "\n";
            }

            confQueue->pop();
            continue;
        }

        // Excluded files

        QRegularExpression excludingRe("(?<attKey>.*)"
                                       "::exclude");

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
    ts << "setting.refURLNumbering      =   "         + QString::number(IsRefURLNumbering_t)     + "\n";
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

    QString subDs = SubDiv_t.replace("\n", ",");
    QString supDs = SupDiv_t.replace("\n", ",");

    ts << "global.Extension        =  \"" <<   Extension_t      << "\"\n";
    ts << "global.Project_Name     =  \"" <<   ProjectName_t    << "\"\n";
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

        ts << DescTable_t->item(i, 0)->text() + "::desc       +=       \""
                  + static_cast<QPlainTextEdit*>(DescTable_t->cellWidget(i, 1))->toPlainText() << "\"\n";

    }

    ts << "\n# Issue\n";

    for(int i = 0; i < IssueTable_t->rowCount(); i++){

         ts << IssueTable_t->item(i, 0)->text() + "::issue       +=       \""
                  + static_cast<QPlainTextEdit*>(IssueTable_t->cellWidget(i, 1))->toPlainText() << "\"\n";
    }

    ts << "\n# Reference URLs\n";

    for(int i = 0; i < RefTable_t->rowCount(); i++){

        ts << RefTable_t->item(i, 0)->text() + "::refURLs       +=       \""
                  + static_cast<QPlainTextEdit*>(RefTable_t->cellWidget(i, 1))->toPlainText() << "\"\n";

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
    else if (flagName   == "refURLNumbering"){
        ui->actionRefe_URL_Numbering->setChecked(flag);
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

    QStringList list = readSClately();

    applyRecentBar(list);

    if(list.empty() || list[0].trimmed() == "") return false;

    setSCPSFile(list[0]);

    return true;
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

QStringList MainWindow::readSClately()
{
    if(sclately->exists()){

        sclately->open( QFile::ReadWrite | QFile::Text  );

        QString fileContent = sclately->readLine();

        QStringList list = fileContent.split(",");

        for(auto& path : list){
            if(path == "") continue;
            pathQue->push_back( path );
        }

        return list;

    }
    else{

        sclately->open( QFile::ReadWrite | QFile::Text  );

        QStringList empty{};

        return empty;

    }
}

// ==============================+===============================================================
// Private Methods
// Handle SCProj file

s_ptr<Scproj> MainWindow::readSCProjFile(const QString &path){

    QFile scprojFile(path);

    if( !scprojFile.exists() ){
        return nullptr;
    }

    scprojFile.open(QFile::ReadOnly|QFile::Text);

    s_ptr<Scproj> result = std::make_shared<Scproj>();

    result->style = CommentStyle::Undefined;

    while( !scprojFile.atEnd() ){

        QString line = scprojFile.readLine();

        QRegularExpression sepRe("DivBySeparator:\\s*"              // keyword
                                 "\"(?<sep>.*)\""                   // separator
        );

        auto sepMatch = sepRe.match(line, 0,
                                      QRegularExpression::NormalMatch);

        if(sepMatch.hasMatch()){

            result->div = sepMatch.captured("sep");
            result->style = CommentStyle::DivBySeparator;
        }

        QRegularExpression endTagRe("DivByStartEndTag:\\s*"       // keyword
                                    "\"(?<tag>.*)\""              // end tag
        );

        auto tagMatch = endTagRe.match(line, 0,
                                      QRegularExpression::NormalMatch);

        if(tagMatch.hasMatch()){

            result->div = tagMatch.captured("tag");
            result->style = CommentStyle::DivByStartEndTag;
        }

        QRegularExpression workedFileRe(":\\s*"
                                        "\"(?<files>.*)\"");

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

    while( !workedFilesQue.empty() ){
        // prepend 할 때 마다 workedFiles에 추가
        workedFiles += workedFilesQue.size() == 1 ?
                    workedFilesQue.front().fileName : workedFilesQue.front().fileName + ",";
        workedFilesQue.pop();
    }

    // 작업 방식
    scprojFile.write("# Worked_Method\n");

    QString method;

    if     (IsDivBySeparator_t){
        method = QString("DivBySeparator: \"")     + QString(Separator_t) + QString("\"\n");
    }
    else if(IsDivByStartEndTag_t){
        method = QString("DivByStartEndTag: \"")   + QString(StartTag_t) +  QString(",") + QString(EndTag_t) + QString("\"\n");
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

    for(int i = 0; i < tbl->rowCount(); i++){

        auto line = static_cast<QPlainTextEdit*>(tbl->cellWidget(i, 1))->toPlainText();

        ts << "| " + tbl->item(i, 0)->text() + " | "
              + line.replace("\n", " ") +    " |\n";
    }

}

// ==============================+===============================================================
// Private Methods
// Directory traversal

s_ptr<queue<FileInfo>> MainWindow::getAllTargetFiles(const QString& dirName){

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

    if( !previewMode && flag.value.trimmed() == "" ){
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

    desc    = *(makeFromTbl(DescTable_t , IsDescNumbering_t   , fileInfo));
    issue   = *(makeFromTbl(IssueTable_t, IsIssueNumbering_t  , fileInfo));
    urls    = *(makeFromTbl(RefTable_t  , IsRefURLNumbering_t , fileInfo));

    auto memoText   = Memo_t;
    auto memos      = memoText.split("\n");

    for(auto& text : memos){
        if(text.trimmed() == "") continue;
        memo.append(Separator_t + "   " + text + "\n");
    }

    if(IsDivByStartEndTag_t && StartTag_t.trimmed() != "") ts << StartTag_t + "\n";

    int loop = static_cast<int>(flagTypeTbl->map.size());

    for(int i = 0; i < loop; i++){

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
            auto edit  = static_cast<QPlainTextEdit*>(tbl->cellWidget(i, 1));

            if(edit->toPlainText().trimmed() == ""){
                continue;
            }

            if(fName == fileInfo.fileName){
                QStringList list = edit->toPlainText().split("\n");

                for(auto& line : list){
                    *ret +=
                            Separator_t + "   " +
                            QString::number(++hits) + ". " +
                            line + "\n";
                }
            }
        }
    }
    else{

        for(int i = 0; i < tbl->rowCount(); i++){

            auto fName = tbl->item(i, 0)->text();
            auto edit  = static_cast<QPlainTextEdit*>(tbl->cellWidget(i, 1));

            if(edit->toPlainText().trimmed() == ""){
                continue;
            }

            if(fName == fileInfo.fileName){

                QStringList list = edit->toPlainText().split("\n");

                for(auto& line : list){
                    *ret +=
                            Separator_t + "   " +
                            line + "\n";
                }
            }
        }
    }

    return ret;
}

void MainWindow::removeComment(QStringList &strList, const QString &div, const CommentStyle style)
{
    auto recursiveFlag = IsRecursiveTraversal_t ?
                QDirIterator::IteratorFlag::Subdirectories :
                QDirIterator::IteratorFlag::NoIteratorFlags;

    if     (style == CommentStyle::DivBySeparator){
        removeCommentBySeparator  (strList, div, recursiveFlag);
    }
    else if(style == CommentStyle::DivByStartEndTag){

        auto tags      = div.split(",");
        auto startTag  = tags[0];
        auto endTag    = tags[1];

        removeCommentByStartEndTag(strList, startTag, endTag, recursiveFlag);
    }
}


void MainWindow::removeCommentByStartEndTag(QStringList &strList, const QString& startTag, const QString& endTag,
                                            const QDirIterator::IteratorFlag& flag){

    auto targetExtensions = Extension_t.split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
    }

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
                        return line.left(endTag.length()) == endTag;
                    };

                    bool isCommentStarted = false;

                    QString line;
                    if(!target.atEnd()) line = target.readLine();
                        if(line.left(startTag.length()) == startTag) isCommentStarted = true;

                    // 주석이 시작되지 않았다면 이 파일을 넘김
                    if(!isCommentStarted) { it.next(); continue; }

                    while(!target.atEnd()){
                        line = target.readLine();
                        if(isCommentStarted && isEndPoint(line)) break;
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

void MainWindow::removeCommentBySeparator(QStringList& strList, const QString& separator,
                                          const QDirIterator::IteratorFlag& flag){

    auto targetExtensions = Extension_t.split(",");

    for(auto& i : targetExtensions){
        i = i.trimmed();
    }

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
                            return line.left(separator.length()) != separator;
                    };

                    QString line;
                    if(!target.atEnd()) line = target.readLine();

                    while(!target.atEnd()){
                        line = target.readLine();
                        if(isEndPoint(line)) break;
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

s_ptr<std::list<TblRecord>> MainWindow::searchTbl(QTableWidget* tbl, QString target)
{
    auto resList = std::make_shared<std::list<TblRecord>>();

    QRegularExpression re(".*" + target + ".*");

    for (int i = 0; i < tbl->rowCount(); i++){

        QString fileName = tbl->item(i, 0)->text();
        QString tblText  = static_cast<QPlainTextEdit*>(tbl->cellWidget(i, 1))->toPlainText();

        auto match = re.match(tblText, 0,
                                      QRegularExpression::NormalMatch);

        if(match.hasMatch()){
            resList->push_back(TblRecord {fileName, tblText});
        }
    }

    return resList;
}

void MainWindow::showSearchResDial(s_ptr<std::list<TblRecord>> recordList)
{

    if(recordList->size() == 0){
        ShowMessageBox(QMessageBox::Warning, "Search results do not exist", "Error");
        return;
    }

    int WINDOWSIZE_X = 1000;
    int WINDOWSIZE_Y = 600;

    QDialog *dialog = new QDialog;

    QTableWidget* resTbl = new QTableWidget(dialog);

    dialog->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dialog->setFixedSize(WINDOWSIZE_X, WINDOWSIZE_Y);
    dialog->setWindowTitle("Search result");

    QStringList *header = new QStringList{ "File Name", "Content" };
    resTbl->setRowCount(0);
    resTbl->setColumnCount(2);
    resTbl->setHorizontalHeaderLabels(*header);
    resTbl->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    resTbl->setFixedSize(WINDOWSIZE_X, WINDOWSIZE_Y);
    resTbl->verticalHeader()->setDefaultSectionSize(75);
    resTbl->setColumnWidth(0, 250);
    resTbl->horizontalHeader()->setStretchLastSection(true);

    for(auto& rec : *recordList){
        insertMultiLineItem(resTbl, false, rec.fileName, rec.content);
    }

    dialog->adjustSize();
    dialog->show();
}
