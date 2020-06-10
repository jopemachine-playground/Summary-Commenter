/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGithub;
    QAction *actionExecute;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionOpen_and_run;
    QAction *actionRemove_Comments;
    QAction *actionRecursive_Traversal;
    QAction *actionrecent1;
    QAction *actionrecent2;
    QAction *actionrecent3;
    QAction *actionrecent4;
    QAction *actionIssue_Numbering;
    QAction *actionDesc_Numbering;
    QAction *actionOpen_Project_Path;
    QAction *actionRefresh;
    QAction *actionSave_md;
    QAction *actionRemove_Comments_From_All_File;
    QAction *actionHelp;
    QAction *actionOpen_setting_file;
    QAction *actionNew;
    QAction *actionrecent5;
    QAction *actionRefe_URL_Numbering;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QHBoxLayout *horizontalLayout_13;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *ExtensionL;
    QLabel *extensionLbl;
    QSpacerItem *spacer1;
    QLineEdit *extensionEdit;
    QHBoxLayout *PathL;
    QLabel *pathLbl;
    QSpacerItem *spacer2;
    QLineEdit *pathEdit;
    QHBoxLayout *SeparatorL;
    QLabel *separatorLbl;
    QSpacerItem *spacer4;
    QLineEdit *separatorEdit;
    QHBoxLayout *StartTagL;
    QLabel *sTagLbl;
    QSpacerItem *spacer1_6;
    QLineEdit *sTagEdit;
    QHBoxLayout *EndTagL;
    QLabel *eTagLbl;
    QSpacerItem *spacer1_7;
    QLineEdit *eTagEdit;
    QHBoxLayout *SupDivLineL;
    QLabel *supDivLbl;
    QPlainTextEdit *supDivEdit;
    QHBoxLayout *SubDivLineL;
    QLabel *subDivLbl;
    QPlainTextEdit *subDivEdit;
    QFrame *line;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *authorLbl;
    QSpacerItem *spacer3;
    QLineEdit *authorEdit;
    QHBoxLayout *TelephoneL;
    QLabel *telepLbl;
    QSpacerItem *spacer8;
    QLineEdit *telepEdit;
    QHBoxLayout *GithubL;
    QLabel *githubLbl;
    QSpacerItem *spacer1_4;
    QLineEdit *githubEdit;
    QHBoxLayout *TeamL;
    QLabel *teamLbl;
    QSpacerItem *spacer1_5;
    QLineEdit *teamEdit;
    QHBoxLayout *ProjectNameL;
    QLabel *projectNameLbl;
    QSpacerItem *spacer1_8;
    QLineEdit *projectNameEdit;
    QHBoxLayout *EmailL;
    QLabel *emailLbl;
    QSpacerItem *spacer7;
    QLineEdit *emailEdit;
    QHBoxLayout *MemoL;
    QLabel *memoLbl;
    QTextEdit *memoEdit;
    QWidget *FlagTab;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *flagTblWidget;
    QHBoxLayout *FlagBtnL;
    QPushButton *FlagUpBtn;
    QPushButton *FlagDownBtn;
    QWidget *DescTab;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *descSearchLbl;
    QLineEdit *descSearchEdit;
    QSplitter *descEditSpliter;
    QTableWidget *descTblWidget;
    QPlainTextEdit *descLargeEdit;
    QHBoxLayout *descTabL2;
    QPushButton *descAddBtn;
    QPushButton *descRemoveBtn;
    QPushButton *descSortBtn;
    QPushButton *descAutoImtBtn;
    QWidget *IssueTab;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *issueSearchLbl;
    QLineEdit *issueSearchEdit;
    QSplitter *issueSplitter;
    QTableWidget *issueTblWidget;
    QPlainTextEdit *issueLargeEdit;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *issueAddBtn;
    QPushButton *issueRemoveBtn;
    QPushButton *issueSortBtn;
    QPushButton *issueAutoImtBtn;
    QWidget *referenceTab;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *referenceTbl;
    QHBoxLayout *ReferenceL_2;
    QPushButton *addReferenceBtn;
    QPushButton *rmReferenceBtn;
    QPushButton *referenceSortBtn;
    QPushButton *refAutoImtBtn;
    QWidget *excludeTab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *excludeTbl;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addExcludeBtn;
    QPushButton *rmExcludeBtn;
    QPushButton *sortExcludeBtn;
    QWidget *PreviewTab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *previewTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *copyBtn;
    QPushButton *executeBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_Recents;
    QMenu *menuHelp;
    QMenu *menuSetting;
    QMenu *menuComments_style;
    QMenu *menuExecute;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 727);
        actionGithub = new QAction(MainWindow);
        actionGithub->setObjectName(QString::fromUtf8("actionGithub"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/img/res/img/github.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGithub->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        actionGithub->setFont(font);
        actionExecute = new QAction(MainWindow);
        actionExecute->setObjectName(QString::fromUtf8("actionExecute"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/img/res/img/trending-up.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecute->setIcon(icon1);
        actionExecute->setFont(font);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/img/res/img/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave->setFont(font);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/img/res/img/book-open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon3);
        actionOpen->setFont(font);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_as->setIcon(icon2);
        actionSave_as->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setFont(font);
        actionOpen_and_run = new QAction(MainWindow);
        actionOpen_and_run->setObjectName(QString::fromUtf8("actionOpen_and_run"));
        actionOpen_and_run->setIcon(icon1);
        actionOpen_and_run->setFont(font);
        actionRemove_Comments = new QAction(MainWindow);
        actionRemove_Comments->setObjectName(QString::fromUtf8("actionRemove_Comments"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/img/res/img/trash-2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_Comments->setIcon(icon4);
        actionRemove_Comments->setFont(font);
        actionRecursive_Traversal = new QAction(MainWindow);
        actionRecursive_Traversal->setObjectName(QString::fromUtf8("actionRecursive_Traversal"));
        actionRecursive_Traversal->setCheckable(true);
        actionRecursive_Traversal->setChecked(true);
        actionRecursive_Traversal->setFont(font);
        actionrecent1 = new QAction(MainWindow);
        actionrecent1->setObjectName(QString::fromUtf8("actionrecent1"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/img/res/img/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionrecent1->setIcon(icon5);
        actionrecent1->setFont(font);
        actionrecent2 = new QAction(MainWindow);
        actionrecent2->setObjectName(QString::fromUtf8("actionrecent2"));
        actionrecent2->setIcon(icon5);
        actionrecent2->setFont(font);
        actionrecent3 = new QAction(MainWindow);
        actionrecent3->setObjectName(QString::fromUtf8("actionrecent3"));
        actionrecent3->setIcon(icon5);
        actionrecent3->setFont(font);
        actionrecent4 = new QAction(MainWindow);
        actionrecent4->setObjectName(QString::fromUtf8("actionrecent4"));
        actionrecent4->setIcon(icon5);
        actionrecent4->setFont(font);
        actionIssue_Numbering = new QAction(MainWindow);
        actionIssue_Numbering->setObjectName(QString::fromUtf8("actionIssue_Numbering"));
        actionIssue_Numbering->setCheckable(true);
        actionIssue_Numbering->setChecked(false);
        actionIssue_Numbering->setFont(font);
        actionDesc_Numbering = new QAction(MainWindow);
        actionDesc_Numbering->setObjectName(QString::fromUtf8("actionDesc_Numbering"));
        actionDesc_Numbering->setCheckable(true);
        actionDesc_Numbering->setChecked(false);
        actionDesc_Numbering->setFont(font);
        actionOpen_Project_Path = new QAction(MainWindow);
        actionOpen_Project_Path->setObjectName(QString::fromUtf8("actionOpen_Project_Path"));
        actionOpen_Project_Path->setFont(font);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/img/res/img/refresh-cw.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon6);
        actionRefresh->setFont(font);
        actionSave_md = new QAction(MainWindow);
        actionSave_md->setObjectName(QString::fromUtf8("actionSave_md"));
        actionSave_md->setFont(font);
        actionRemove_Comments_From_All_File = new QAction(MainWindow);
        actionRemove_Comments_From_All_File->setObjectName(QString::fromUtf8("actionRemove_Comments_From_All_File"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/img/res/img/alert-triangle.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_Comments_From_All_File->setIcon(icon7);
        actionRemove_Comments_From_All_File->setFont(font);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/img/res/img/help-circle.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon8);
        actionHelp->setFont(font);
        actionOpen_setting_file = new QAction(MainWindow);
        actionOpen_setting_file->setObjectName(QString::fromUtf8("actionOpen_setting_file"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/img/res/img/settings.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_setting_file->setIcon(icon9);
        actionOpen_setting_file->setFont(font);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/img/res/img/plus-circle.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon10);
        actionNew->setFont(font);
        actionrecent5 = new QAction(MainWindow);
        actionrecent5->setObjectName(QString::fromUtf8("actionrecent5"));
        actionrecent5->setIcon(icon5);
        actionrecent5->setFont(font);
        actionRefe_URL_Numbering = new QAction(MainWindow);
        actionRefe_URL_Numbering->setObjectName(QString::fromUtf8("actionRefe_URL_Numbering"));
        actionRefe_URL_Numbering->setCheckable(true);
        actionRefe_URL_Numbering->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        SettingTab = new QWidget();
        SettingTab->setObjectName(QString::fromUtf8("SettingTab"));
        horizontalLayout_13 = new QHBoxLayout(SettingTab);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        groupBox = new QGroupBox(SettingTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ExtensionL = new QHBoxLayout();
        ExtensionL->setSpacing(6);
        ExtensionL->setObjectName(QString::fromUtf8("ExtensionL"));
        extensionLbl = new QLabel(groupBox);
        extensionLbl->setObjectName(QString::fromUtf8("extensionLbl"));

        ExtensionL->addWidget(extensionLbl);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ExtensionL->addItem(spacer1);

        extensionEdit = new QLineEdit(groupBox);
        extensionEdit->setObjectName(QString::fromUtf8("extensionEdit"));
        extensionEdit->setMinimumSize(QSize(200, 0));
        extensionEdit->setMaximumSize(QSize(200, 16777215));

        ExtensionL->addWidget(extensionEdit);


        gridLayout->addLayout(ExtensionL, 0, 0, 1, 1);

        PathL = new QHBoxLayout();
        PathL->setSpacing(6);
        PathL->setObjectName(QString::fromUtf8("PathL"));
        pathLbl = new QLabel(groupBox);
        pathLbl->setObjectName(QString::fromUtf8("pathLbl"));

        PathL->addWidget(pathLbl);

        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PathL->addItem(spacer2);

        pathEdit = new QLineEdit(groupBox);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setMinimumSize(QSize(200, 0));
        pathEdit->setMaximumSize(QSize(200, 16777215));

        PathL->addWidget(pathEdit);


        gridLayout->addLayout(PathL, 1, 0, 1, 1);

        SeparatorL = new QHBoxLayout();
        SeparatorL->setSpacing(6);
        SeparatorL->setObjectName(QString::fromUtf8("SeparatorL"));
        separatorLbl = new QLabel(groupBox);
        separatorLbl->setObjectName(QString::fromUtf8("separatorLbl"));

        SeparatorL->addWidget(separatorLbl);

        spacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SeparatorL->addItem(spacer4);

        separatorEdit = new QLineEdit(groupBox);
        separatorEdit->setObjectName(QString::fromUtf8("separatorEdit"));
        separatorEdit->setMinimumSize(QSize(200, 0));
        separatorEdit->setMaximumSize(QSize(200, 16777215));

        SeparatorL->addWidget(separatorEdit);


        gridLayout->addLayout(SeparatorL, 2, 0, 1, 1);

        StartTagL = new QHBoxLayout();
        StartTagL->setSpacing(6);
        StartTagL->setObjectName(QString::fromUtf8("StartTagL"));
        sTagLbl = new QLabel(groupBox);
        sTagLbl->setObjectName(QString::fromUtf8("sTagLbl"));

        StartTagL->addWidget(sTagLbl);

        spacer1_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        StartTagL->addItem(spacer1_6);

        sTagEdit = new QLineEdit(groupBox);
        sTagEdit->setObjectName(QString::fromUtf8("sTagEdit"));
        sTagEdit->setMinimumSize(QSize(200, 0));
        sTagEdit->setMaximumSize(QSize(200, 16777215));

        StartTagL->addWidget(sTagEdit);


        gridLayout->addLayout(StartTagL, 3, 0, 1, 1);

        EndTagL = new QHBoxLayout();
        EndTagL->setSpacing(6);
        EndTagL->setObjectName(QString::fromUtf8("EndTagL"));
        eTagLbl = new QLabel(groupBox);
        eTagLbl->setObjectName(QString::fromUtf8("eTagLbl"));

        EndTagL->addWidget(eTagLbl);

        spacer1_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        EndTagL->addItem(spacer1_7);

        eTagEdit = new QLineEdit(groupBox);
        eTagEdit->setObjectName(QString::fromUtf8("eTagEdit"));
        eTagEdit->setMinimumSize(QSize(200, 0));
        eTagEdit->setMaximumSize(QSize(200, 16777215));

        EndTagL->addWidget(eTagEdit);


        gridLayout->addLayout(EndTagL, 4, 0, 1, 1);

        SupDivLineL = new QHBoxLayout();
        SupDivLineL->setSpacing(6);
        SupDivLineL->setObjectName(QString::fromUtf8("SupDivLineL"));
        supDivLbl = new QLabel(groupBox);
        supDivLbl->setObjectName(QString::fromUtf8("supDivLbl"));

        SupDivLineL->addWidget(supDivLbl);

        supDivEdit = new QPlainTextEdit(groupBox);
        supDivEdit->setObjectName(QString::fromUtf8("supDivEdit"));

        SupDivLineL->addWidget(supDivEdit);


        gridLayout->addLayout(SupDivLineL, 5, 0, 1, 1);

        SubDivLineL = new QHBoxLayout();
        SubDivLineL->setSpacing(6);
        SubDivLineL->setObjectName(QString::fromUtf8("SubDivLineL"));
        subDivLbl = new QLabel(groupBox);
        subDivLbl->setObjectName(QString::fromUtf8("subDivLbl"));

        SubDivLineL->addWidget(subDivLbl);

        subDivEdit = new QPlainTextEdit(groupBox);
        subDivEdit->setObjectName(QString::fromUtf8("subDivEdit"));

        SubDivLineL->addWidget(subDivEdit);


        gridLayout->addLayout(SubDivLineL, 6, 0, 1, 1);


        horizontalLayout_13->addWidget(groupBox);

        line = new QFrame(SettingTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_13->addWidget(line);

        groupBox_2 = new QGroupBox(SettingTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        authorLbl = new QLabel(groupBox_2);
        authorLbl->setObjectName(QString::fromUtf8("authorLbl"));

        horizontalLayout_2->addWidget(authorLbl);

        spacer3 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer3);

        authorEdit = new QLineEdit(groupBox_2);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));
        authorEdit->setMinimumSize(QSize(200, 0));
        authorEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(authorEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        TelephoneL = new QHBoxLayout();
        TelephoneL->setSpacing(6);
        TelephoneL->setObjectName(QString::fromUtf8("TelephoneL"));
        telepLbl = new QLabel(groupBox_2);
        telepLbl->setObjectName(QString::fromUtf8("telepLbl"));

        TelephoneL->addWidget(telepLbl);

        spacer8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TelephoneL->addItem(spacer8);

        telepEdit = new QLineEdit(groupBox_2);
        telepEdit->setObjectName(QString::fromUtf8("telepEdit"));
        telepEdit->setMinimumSize(QSize(200, 0));
        telepEdit->setMaximumSize(QSize(200, 16777215));

        TelephoneL->addWidget(telepEdit);


        gridLayout_2->addLayout(TelephoneL, 1, 0, 1, 1);

        GithubL = new QHBoxLayout();
        GithubL->setSpacing(6);
        GithubL->setObjectName(QString::fromUtf8("GithubL"));
        githubLbl = new QLabel(groupBox_2);
        githubLbl->setObjectName(QString::fromUtf8("githubLbl"));

        GithubL->addWidget(githubLbl);

        spacer1_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        GithubL->addItem(spacer1_4);

        githubEdit = new QLineEdit(groupBox_2);
        githubEdit->setObjectName(QString::fromUtf8("githubEdit"));
        githubEdit->setMinimumSize(QSize(200, 0));
        githubEdit->setMaximumSize(QSize(200, 16777215));

        GithubL->addWidget(githubEdit);


        gridLayout_2->addLayout(GithubL, 2, 0, 1, 1);

        TeamL = new QHBoxLayout();
        TeamL->setSpacing(6);
        TeamL->setObjectName(QString::fromUtf8("TeamL"));
        teamLbl = new QLabel(groupBox_2);
        teamLbl->setObjectName(QString::fromUtf8("teamLbl"));

        TeamL->addWidget(teamLbl);

        spacer1_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TeamL->addItem(spacer1_5);

        teamEdit = new QLineEdit(groupBox_2);
        teamEdit->setObjectName(QString::fromUtf8("teamEdit"));
        teamEdit->setMinimumSize(QSize(200, 0));
        teamEdit->setMaximumSize(QSize(200, 16777215));

        TeamL->addWidget(teamEdit);


        gridLayout_2->addLayout(TeamL, 3, 0, 1, 1);

        ProjectNameL = new QHBoxLayout();
        ProjectNameL->setSpacing(6);
        ProjectNameL->setObjectName(QString::fromUtf8("ProjectNameL"));
        projectNameLbl = new QLabel(groupBox_2);
        projectNameLbl->setObjectName(QString::fromUtf8("projectNameLbl"));

        ProjectNameL->addWidget(projectNameLbl);

        spacer1_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProjectNameL->addItem(spacer1_8);

        projectNameEdit = new QLineEdit(groupBox_2);
        projectNameEdit->setObjectName(QString::fromUtf8("projectNameEdit"));
        projectNameEdit->setMinimumSize(QSize(200, 0));
        projectNameEdit->setMaximumSize(QSize(200, 16777215));

        ProjectNameL->addWidget(projectNameEdit);


        gridLayout_2->addLayout(ProjectNameL, 4, 0, 1, 1);

        EmailL = new QHBoxLayout();
        EmailL->setSpacing(6);
        EmailL->setObjectName(QString::fromUtf8("EmailL"));
        emailLbl = new QLabel(groupBox_2);
        emailLbl->setObjectName(QString::fromUtf8("emailLbl"));

        EmailL->addWidget(emailLbl);

        spacer7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        EmailL->addItem(spacer7);

        emailEdit = new QLineEdit(groupBox_2);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));
        emailEdit->setMinimumSize(QSize(200, 0));
        emailEdit->setMaximumSize(QSize(200, 16777215));

        EmailL->addWidget(emailEdit);


        gridLayout_2->addLayout(EmailL, 5, 0, 1, 1);

        MemoL = new QHBoxLayout();
        MemoL->setSpacing(6);
        MemoL->setObjectName(QString::fromUtf8("MemoL"));
        memoLbl = new QLabel(groupBox_2);
        memoLbl->setObjectName(QString::fromUtf8("memoLbl"));

        MemoL->addWidget(memoLbl);

        memoEdit = new QTextEdit(groupBox_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        MemoL->addWidget(memoEdit);


        gridLayout_2->addLayout(MemoL, 6, 0, 1, 1);


        horizontalLayout_13->addWidget(groupBox_2);

        tabWidget->addTab(SettingTab, QString());
        FlagTab = new QWidget();
        FlagTab->setObjectName(QString::fromUtf8("FlagTab"));
        horizontalLayout_6 = new QHBoxLayout(FlagTab);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        flagTblWidget = new QTableWidget(FlagTab);
        if (flagTblWidget->columnCount() < 2)
            flagTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        flagTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        flagTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        flagTblWidget->setObjectName(QString::fromUtf8("flagTblWidget"));

        verticalLayout_8->addWidget(flagTblWidget);

        FlagBtnL = new QHBoxLayout();
        FlagBtnL->setSpacing(6);
        FlagBtnL->setObjectName(QString::fromUtf8("FlagBtnL"));
        FlagUpBtn = new QPushButton(FlagTab);
        FlagUpBtn->setObjectName(QString::fromUtf8("FlagUpBtn"));

        FlagBtnL->addWidget(FlagUpBtn);

        FlagDownBtn = new QPushButton(FlagTab);
        FlagDownBtn->setObjectName(QString::fromUtf8("FlagDownBtn"));

        FlagBtnL->addWidget(FlagDownBtn);


        verticalLayout_8->addLayout(FlagBtnL);


        horizontalLayout_6->addLayout(verticalLayout_8);

        tabWidget->addTab(FlagTab, QString());
        DescTab = new QWidget();
        DescTab->setObjectName(QString::fromUtf8("DescTab"));
        gridLayout_4 = new QGridLayout(DescTab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        descSearchLbl = new QLabel(DescTab);
        descSearchLbl->setObjectName(QString::fromUtf8("descSearchLbl"));

        horizontalLayout_3->addWidget(descSearchLbl);

        descSearchEdit = new QLineEdit(DescTab);
        descSearchEdit->setObjectName(QString::fromUtf8("descSearchEdit"));

        horizontalLayout_3->addWidget(descSearchEdit);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        descEditSpliter = new QSplitter(DescTab);
        descEditSpliter->setObjectName(QString::fromUtf8("descEditSpliter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(descEditSpliter->sizePolicy().hasHeightForWidth());
        descEditSpliter->setSizePolicy(sizePolicy);
        descEditSpliter->setMinimumSize(QSize(0, 300));
        descEditSpliter->setBaseSize(QSize(0, 0));
        descEditSpliter->setOrientation(Qt::Vertical);
        descTblWidget = new QTableWidget(descEditSpliter);
        if (descTblWidget->columnCount() < 2)
            descTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        descTblWidget->setObjectName(QString::fromUtf8("descTblWidget"));
        descTblWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(descTblWidget->sizePolicy().hasHeightForWidth());
        descTblWidget->setSizePolicy(sizePolicy1);
        descTblWidget->setMinimumSize(QSize(0, 300));
        descEditSpliter->addWidget(descTblWidget);
        descLargeEdit = new QPlainTextEdit(descEditSpliter);
        descLargeEdit->setObjectName(QString::fromUtf8("descLargeEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(descLargeEdit->sizePolicy().hasHeightForWidth());
        descLargeEdit->setSizePolicy(sizePolicy2);
        descLargeEdit->setMinimumSize(QSize(0, 0));
        descLargeEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        descLargeEdit->setTabStopDistance(80.000000000000000);
        descLargeEdit->setBackgroundVisible(false);
        descLargeEdit->setCenterOnScroll(false);
        descEditSpliter->addWidget(descLargeEdit);

        gridLayout_3->addWidget(descEditSpliter, 1, 0, 1, 1);

        descTabL2 = new QHBoxLayout();
        descTabL2->setSpacing(6);
        descTabL2->setObjectName(QString::fromUtf8("descTabL2"));
        descAddBtn = new QPushButton(DescTab);
        descAddBtn->setObjectName(QString::fromUtf8("descAddBtn"));

        descTabL2->addWidget(descAddBtn);

        descRemoveBtn = new QPushButton(DescTab);
        descRemoveBtn->setObjectName(QString::fromUtf8("descRemoveBtn"));

        descTabL2->addWidget(descRemoveBtn);

        descSortBtn = new QPushButton(DescTab);
        descSortBtn->setObjectName(QString::fromUtf8("descSortBtn"));

        descTabL2->addWidget(descSortBtn);

        descAutoImtBtn = new QPushButton(DescTab);
        descAutoImtBtn->setObjectName(QString::fromUtf8("descAutoImtBtn"));

        descTabL2->addWidget(descAutoImtBtn);


        gridLayout_3->addLayout(descTabL2, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(DescTab, QString());
        IssueTab = new QWidget();
        IssueTab->setObjectName(QString::fromUtf8("IssueTab"));
        gridLayout_6 = new QGridLayout(IssueTab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        issueSearchLbl = new QLabel(IssueTab);
        issueSearchLbl->setObjectName(QString::fromUtf8("issueSearchLbl"));

        horizontalLayout_7->addWidget(issueSearchLbl);

        issueSearchEdit = new QLineEdit(IssueTab);
        issueSearchEdit->setObjectName(QString::fromUtf8("issueSearchEdit"));

        horizontalLayout_7->addWidget(issueSearchEdit);


        gridLayout_5->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        issueSplitter = new QSplitter(IssueTab);
        issueSplitter->setObjectName(QString::fromUtf8("issueSplitter"));
        issueSplitter->setOrientation(Qt::Vertical);
        issueTblWidget = new QTableWidget(issueSplitter);
        if (issueTblWidget->columnCount() < 2)
            issueTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        issueTblWidget->setObjectName(QString::fromUtf8("issueTblWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(issueTblWidget->sizePolicy().hasHeightForWidth());
        issueTblWidget->setSizePolicy(sizePolicy3);
        issueTblWidget->setMinimumSize(QSize(0, 300));
        issueSplitter->addWidget(issueTblWidget);
        issueLargeEdit = new QPlainTextEdit(issueSplitter);
        issueLargeEdit->setObjectName(QString::fromUtf8("issueLargeEdit"));
        sizePolicy2.setHeightForWidth(issueLargeEdit->sizePolicy().hasHeightForWidth());
        issueLargeEdit->setSizePolicy(sizePolicy2);
        issueSplitter->addWidget(issueLargeEdit);

        gridLayout_5->addWidget(issueSplitter, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        issueAddBtn = new QPushButton(IssueTab);
        issueAddBtn->setObjectName(QString::fromUtf8("issueAddBtn"));

        horizontalLayout_8->addWidget(issueAddBtn);

        issueRemoveBtn = new QPushButton(IssueTab);
        issueRemoveBtn->setObjectName(QString::fromUtf8("issueRemoveBtn"));

        horizontalLayout_8->addWidget(issueRemoveBtn);

        issueSortBtn = new QPushButton(IssueTab);
        issueSortBtn->setObjectName(QString::fromUtf8("issueSortBtn"));

        horizontalLayout_8->addWidget(issueSortBtn);

        issueAutoImtBtn = new QPushButton(IssueTab);
        issueAutoImtBtn->setObjectName(QString::fromUtf8("issueAutoImtBtn"));

        horizontalLayout_8->addWidget(issueAutoImtBtn);


        gridLayout_5->addLayout(horizontalLayout_8, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(IssueTab, QString());
        referenceTab = new QWidget();
        referenceTab->setObjectName(QString::fromUtf8("referenceTab"));
        verticalLayout_10 = new QVBoxLayout(referenceTab);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        referenceTbl = new QTableWidget(referenceTab);
        if (referenceTbl->columnCount() < 2)
            referenceTbl->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        referenceTbl->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        referenceTbl->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        referenceTbl->setObjectName(QString::fromUtf8("referenceTbl"));

        verticalLayout_9->addWidget(referenceTbl);

        ReferenceL_2 = new QHBoxLayout();
        ReferenceL_2->setSpacing(6);
        ReferenceL_2->setObjectName(QString::fromUtf8("ReferenceL_2"));
        addReferenceBtn = new QPushButton(referenceTab);
        addReferenceBtn->setObjectName(QString::fromUtf8("addReferenceBtn"));

        ReferenceL_2->addWidget(addReferenceBtn);

        rmReferenceBtn = new QPushButton(referenceTab);
        rmReferenceBtn->setObjectName(QString::fromUtf8("rmReferenceBtn"));

        ReferenceL_2->addWidget(rmReferenceBtn);

        referenceSortBtn = new QPushButton(referenceTab);
        referenceSortBtn->setObjectName(QString::fromUtf8("referenceSortBtn"));

        ReferenceL_2->addWidget(referenceSortBtn);

        refAutoImtBtn = new QPushButton(referenceTab);
        refAutoImtBtn->setObjectName(QString::fromUtf8("refAutoImtBtn"));

        ReferenceL_2->addWidget(refAutoImtBtn);


        verticalLayout_9->addLayout(ReferenceL_2);


        verticalLayout_10->addLayout(verticalLayout_9);

        tabWidget->addTab(referenceTab, QString());
        excludeTab = new QWidget();
        excludeTab->setObjectName(QString::fromUtf8("excludeTab"));
        horizontalLayout_5 = new QHBoxLayout(excludeTab);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        excludeTbl = new QTableWidget(excludeTab);
        if (excludeTbl->columnCount() < 1)
            excludeTbl->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        excludeTbl->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        excludeTbl->setObjectName(QString::fromUtf8("excludeTbl"));

        verticalLayout_7->addWidget(excludeTbl);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addExcludeBtn = new QPushButton(excludeTab);
        addExcludeBtn->setObjectName(QString::fromUtf8("addExcludeBtn"));

        horizontalLayout_4->addWidget(addExcludeBtn);

        rmExcludeBtn = new QPushButton(excludeTab);
        rmExcludeBtn->setObjectName(QString::fromUtf8("rmExcludeBtn"));

        horizontalLayout_4->addWidget(rmExcludeBtn);

        sortExcludeBtn = new QPushButton(excludeTab);
        sortExcludeBtn->setObjectName(QString::fromUtf8("sortExcludeBtn"));

        horizontalLayout_4->addWidget(sortExcludeBtn);


        verticalLayout_7->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_7);

        tabWidget->addTab(excludeTab, QString());
        PreviewTab = new QWidget();
        PreviewTab->setObjectName(QString::fromUtf8("PreviewTab"));
        verticalLayout_5 = new QVBoxLayout(PreviewTab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        previewTextEdit = new QPlainTextEdit(PreviewTab);
        previewTextEdit->setObjectName(QString::fromUtf8("previewTextEdit"));
        previewTextEdit->setStyleSheet(QString::fromUtf8(""));
        previewTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(previewTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        copyBtn = new QPushButton(PreviewTab);
        copyBtn->setObjectName(QString::fromUtf8("copyBtn"));

        horizontalLayout->addWidget(copyBtn);

        executeBtn = new QPushButton(PreviewTab);
        executeBtn->setObjectName(QString::fromUtf8("executeBtn"));

        horizontalLayout->addWidget(executeBtn);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_3);

        tabWidget->addTab(PreviewTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1120, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setFont(font);
        menuOpen_Recents = new QMenu(menuFile);
        menuOpen_Recents->setObjectName(QString::fromUtf8("menuOpen_Recents"));
        menuOpen_Recents->setFont(font);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setFont(font);
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuComments_style = new QMenu(menuSetting);
        menuComments_style->setObjectName(QString::fromUtf8("menuComments_style"));
        menuComments_style->setFont(font);
        menuExecute = new QMenu(menuBar);
        menuExecute->setObjectName(QString::fromUtf8("menuExecute"));
        menuExecute->setFont(font);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuExecute->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_and_run);
        menuFile->addAction(menuOpen_Recents->menuAction());
        menuFile->addAction(actionOpen_Project_Path);
        menuFile->addAction(actionOpen_setting_file);
        menuFile->addSeparator();
        menuFile->addAction(actionRefresh);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_md);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOpen_Recents->addAction(actionrecent1);
        menuOpen_Recents->addAction(actionrecent2);
        menuOpen_Recents->addAction(actionrecent3);
        menuOpen_Recents->addAction(actionrecent4);
        menuOpen_Recents->addAction(actionrecent5);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionGithub);
        menuSetting->addAction(actionRecursive_Traversal);
        menuSetting->addSeparator();
        menuSetting->addAction(actionIssue_Numbering);
        menuSetting->addAction(actionDesc_Numbering);
        menuSetting->addAction(actionRefe_URL_Numbering);
        menuSetting->addSeparator();
        menuSetting->addAction(menuComments_style->menuAction());
        menuExecute->addAction(actionExecute);
        menuExecute->addSeparator();
        menuExecute->addAction(actionRemove_Comments);
        menuExecute->addAction(actionRemove_Comments_From_All_File);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGithub->setText(QApplication::translate("MainWindow", "Github", nullptr));
        actionExecute->setText(QApplication::translate("MainWindow", "Run", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExecute->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionOpen_and_run->setText(QApplication::translate("MainWindow", "Open and Run", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen_and_run->setShortcut(QApplication::translate("MainWindow", "Shift+F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionRemove_Comments->setText(QApplication::translate("MainWindow", "Remove Worked Comments", nullptr));
        actionRecursive_Traversal->setText(QApplication::translate("MainWindow", "Recursive Traversal", nullptr));
        actionrecent1->setText(QApplication::translate("MainWindow", "recent1", nullptr));
        actionrecent2->setText(QApplication::translate("MainWindow", "recent2", nullptr));
        actionrecent3->setText(QApplication::translate("MainWindow", "recent3", nullptr));
        actionrecent4->setText(QApplication::translate("MainWindow", "recent4", nullptr));
        actionIssue_Numbering->setText(QApplication::translate("MainWindow", "Issue Numbering", nullptr));
        actionDesc_Numbering->setText(QApplication::translate("MainWindow", "Desc Numbering", nullptr));
        actionOpen_Project_Path->setText(QApplication::translate("MainWindow", "Open Project Path", nullptr));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_md->setText(QApplication::translate("MainWindow", "Export as Markdown", nullptr));
        actionRemove_Comments_From_All_File->setText(QApplication::translate("MainWindow", "Remove Comments From All Files", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Manual", nullptr));
        actionOpen_setting_file->setText(QApplication::translate("MainWindow", "Open Setting File", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionrecent5->setText(QApplication::translate("MainWindow", "recent5", nullptr));
        actionRefe_URL_Numbering->setText(QApplication::translate("MainWindow", "Ref URL Numbering", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Project Settings", nullptr));
        extensionLbl->setText(QApplication::translate("MainWindow", "Extension", nullptr));
        pathLbl->setText(QApplication::translate("MainWindow", "Project Path", nullptr));
        separatorLbl->setText(QApplication::translate("MainWindow", "Separator", nullptr));
        separatorEdit->setText(QApplication::translate("MainWindow", "// @ ", nullptr));
        sTagLbl->setText(QApplication::translate("MainWindow", "Start Tag", nullptr));
        eTagLbl->setText(QApplication::translate("MainWindow", "End Tag", nullptr));
        eTagEdit->setText(QString());
        supDivLbl->setText(QApplication::translate("MainWindow", "Sup Div Line", nullptr));
        supDivEdit->setPlainText(QApplication::translate("MainWindow", "// ==============================+===============================================================", nullptr));
        subDivLbl->setText(QApplication::translate("MainWindow", "Sub Div Line", nullptr));
        subDivEdit->setPlainText(QApplication::translate("MainWindow", "// ==============================+===============================================================", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Common Info", nullptr));
        authorLbl->setText(QApplication::translate("MainWindow", "Author", nullptr));
        telepLbl->setText(QApplication::translate("MainWindow", "Telephone", nullptr));
        githubLbl->setText(QApplication::translate("MainWindow", "Github Account", nullptr));
        teamLbl->setText(QApplication::translate("MainWindow", "Team", nullptr));
        projectNameLbl->setText(QApplication::translate("MainWindow", "Project Name", nullptr));
        emailLbl->setText(QApplication::translate("MainWindow", "Email", nullptr));
        memoLbl->setText(QApplication::translate("MainWindow", "Memo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QApplication::translate("MainWindow", "Global", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flagTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flagTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", nullptr));
        FlagUpBtn->setText(QApplication::translate("MainWindow", "Up", nullptr));
        FlagDownBtn->setText(QApplication::translate("MainWindow", "Down", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(FlagTab), QApplication::translate("MainWindow", "Flag", nullptr));
        descSearchLbl->setText(QApplication::translate("MainWindow", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = descTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = descTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Description", nullptr));
        descLargeEdit->setDocumentTitle(QString());
        descLargeEdit->setPlaceholderText(QApplication::translate("MainWindow", "Edit Description by here", nullptr));
        descAddBtn->setText(QApplication::translate("MainWindow", "Add (+)", nullptr));
        descRemoveBtn->setText(QApplication::translate("MainWindow", "Remove (Del)", nullptr));
        descSortBtn->setText(QApplication::translate("MainWindow", "Sort By File Name (Ctrl + T)", nullptr));
        descAutoImtBtn->setText(QApplication::translate("MainWindow", "Add All Files (F6)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DescTab), QApplication::translate("MainWindow", "Desc", nullptr));
        issueSearchLbl->setText(QApplication::translate("MainWindow", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = issueTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = issueTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Issue", nullptr));
        issueLargeEdit->setPlaceholderText(QApplication::translate("MainWindow", "Edit Issue by here", nullptr));
        issueAddBtn->setText(QApplication::translate("MainWindow", "Add (+)", nullptr));
        issueRemoveBtn->setText(QApplication::translate("MainWindow", "Remove (Del)", nullptr));
        issueSortBtn->setText(QApplication::translate("MainWindow", "Sort By File Name (Ctrl + T)", nullptr));
        issueAutoImtBtn->setText(QApplication::translate("MainWindow", "Add All Files (F6)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(IssueTab), QApplication::translate("MainWindow", "Issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = referenceTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = referenceTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "URLs", nullptr));
        addReferenceBtn->setText(QApplication::translate("MainWindow", "Add (+)", nullptr));
        rmReferenceBtn->setText(QApplication::translate("MainWindow", "Remove (Del)", nullptr));
        referenceSortBtn->setText(QApplication::translate("MainWindow", "Sort By File Name (Ctrl + T)", nullptr));
        refAutoImtBtn->setText(QApplication::translate("MainWindow", "Add All Files (F6)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(referenceTab), QApplication::translate("MainWindow", "Reference", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = excludeTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "File Name to exclude", nullptr));
        addExcludeBtn->setText(QApplication::translate("MainWindow", "Add (+)", nullptr));
        rmExcludeBtn->setText(QApplication::translate("MainWindow", "Remove (Del)", nullptr));
        sortExcludeBtn->setText(QApplication::translate("MainWindow", "Sort By File Name (Ctrl + T)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(excludeTab), QApplication::translate("MainWindow", "Exclude", nullptr));
#ifndef QT_NO_TOOLTIP
        previewTextEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Check the comments to add</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        copyBtn->setText(QApplication::translate("MainWindow", "Copy (C)", nullptr));
        executeBtn->setText(QApplication::translate("MainWindow", "Run (F5)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PreviewTab), QApplication::translate("MainWindow", "Preview", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuOpen_Recents->setTitle(QApplication::translate("MainWindow", "Open Recents", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", nullptr));
        menuComments_style->setTitle(QApplication::translate("MainWindow", "Comments style", nullptr));
        menuExecute->setTitle(QApplication::translate("MainWindow", "Execute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
