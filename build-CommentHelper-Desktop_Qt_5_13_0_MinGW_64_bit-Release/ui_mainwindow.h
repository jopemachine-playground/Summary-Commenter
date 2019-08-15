/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *ExtensionL;
    QLabel *extensionLbl;
    QSpacerItem *spacer1;
    QLineEdit *extensionEdit;
    QHBoxLayout *PathL;
    QLabel *pathLbl;
    QSpacerItem *spacer2;
    QLineEdit *pathEdit;
    QHBoxLayout *AuthorL;
    QLabel *authorLbl;
    QSpacerItem *spacer3;
    QLineEdit *authorEdit;
    QHBoxLayout *SeparatorL;
    QLabel *separatorLbl;
    QSpacerItem *spacer4;
    QLineEdit *separatorEdit;
    QHBoxLayout *EmailL;
    QLabel *emailLbl;
    QSpacerItem *spacer7;
    QLineEdit *emailEdit;
    QHBoxLayout *TelephoneL;
    QLabel *telepLbl;
    QSpacerItem *spacer8;
    QLineEdit *telepEdit;
    QHBoxLayout *SupDivLineL;
    QLabel *supDivLbl;
    QTextEdit *supDivEdit;
    QHBoxLayout *SubDivLineL;
    QLabel *subDivLbl;
    QTextEdit *subDivEdit;
    QFrame *line;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *GithubL;
    QLabel *githubLbl;
    QSpacerItem *spacer1_4;
    QLineEdit *githubEdit;
    QHBoxLayout *TeamL;
    QLabel *teamLbl;
    QSpacerItem *spacer1_5;
    QLineEdit *teamEdit;
    QHBoxLayout *MemoL;
    QLabel *memoLbl;
    QTextEdit *memoEdit;
    QWidget *FlagTab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *flagTabL1;
    QTableWidget *flagTblWidget;
    QWidget *DescTab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *descTabL1;
    QTableWidget *descTblWidget;
    QHBoxLayout *descTabL2;
    QPushButton *descAddBtn;
    QPushButton *descRemoveBtn;
    QPushButton *descSortBtn;
    QWidget *IssueTab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *issueTabL;
    QTableWidget *issueTblWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *issueAddBtn;
    QPushButton *issueRemoveBtn;
    QPushButton *issueSortBtn;
    QWidget *referenceTab;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *referenceTbl;
    QHBoxLayout *ReferenceL_2;
    QPushButton *addReferenceBtn;
    QPushButton *rmReferenceBtn;
    QPushButton *referenceSortBtn;
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
    QMenu *menuFiel;
    QMenu *menuOpen_Recents;
    QMenu *menuHelp;
    QMenu *menuSetting;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 530);
        actionGithub = new QAction(MainWindow);
        actionGithub->setObjectName(QString::fromUtf8("actionGithub"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/img/github.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGithub->setIcon(icon);
        actionExecute = new QAction(MainWindow);
        actionExecute->setObjectName(QString::fromUtf8("actionExecute"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpen_and_run = new QAction(MainWindow);
        actionOpen_and_run->setObjectName(QString::fromUtf8("actionOpen_and_run"));
        actionRemove_Comments = new QAction(MainWindow);
        actionRemove_Comments->setObjectName(QString::fromUtf8("actionRemove_Comments"));
        actionRecursive_Traversal = new QAction(MainWindow);
        actionRecursive_Traversal->setObjectName(QString::fromUtf8("actionRecursive_Traversal"));
        actionRecursive_Traversal->setCheckable(true);
        actionRecursive_Traversal->setChecked(true);
        actionrecent1 = new QAction(MainWindow);
        actionrecent1->setObjectName(QString::fromUtf8("actionrecent1"));
        actionrecent2 = new QAction(MainWindow);
        actionrecent2->setObjectName(QString::fromUtf8("actionrecent2"));
        actionrecent3 = new QAction(MainWindow);
        actionrecent3->setObjectName(QString::fromUtf8("actionrecent3"));
        actionrecent4 = new QAction(MainWindow);
        actionrecent4->setObjectName(QString::fromUtf8("actionrecent4"));
        actionIssue_Numbering = new QAction(MainWindow);
        actionIssue_Numbering->setObjectName(QString::fromUtf8("actionIssue_Numbering"));
        actionIssue_Numbering->setCheckable(true);
        actionIssue_Numbering->setChecked(true);
        actionDesc_Numbering = new QAction(MainWindow);
        actionDesc_Numbering->setObjectName(QString::fromUtf8("actionDesc_Numbering"));
        actionDesc_Numbering->setCheckable(true);
        actionDesc_Numbering->setChecked(true);
        actionOpen_Project_Path = new QAction(MainWindow);
        actionOpen_Project_Path->setObjectName(QString::fromUtf8("actionOpen_Project_Path"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
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
        frame = new QFrame(SettingTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        frame->setMidLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ExtensionL = new QHBoxLayout();
        ExtensionL->setSpacing(6);
        ExtensionL->setObjectName(QString::fromUtf8("ExtensionL"));
        extensionLbl = new QLabel(frame);
        extensionLbl->setObjectName(QString::fromUtf8("extensionLbl"));

        ExtensionL->addWidget(extensionLbl);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ExtensionL->addItem(spacer1);

        extensionEdit = new QLineEdit(frame);
        extensionEdit->setObjectName(QString::fromUtf8("extensionEdit"));

        ExtensionL->addWidget(extensionEdit);


        verticalLayout->addLayout(ExtensionL);

        PathL = new QHBoxLayout();
        PathL->setSpacing(6);
        PathL->setObjectName(QString::fromUtf8("PathL"));
        pathLbl = new QLabel(frame);
        pathLbl->setObjectName(QString::fromUtf8("pathLbl"));

        PathL->addWidget(pathLbl);

        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PathL->addItem(spacer2);

        pathEdit = new QLineEdit(frame);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        PathL->addWidget(pathEdit);


        verticalLayout->addLayout(PathL);

        AuthorL = new QHBoxLayout();
        AuthorL->setSpacing(6);
        AuthorL->setObjectName(QString::fromUtf8("AuthorL"));
        authorLbl = new QLabel(frame);
        authorLbl->setObjectName(QString::fromUtf8("authorLbl"));

        AuthorL->addWidget(authorLbl);

        spacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AuthorL->addItem(spacer3);

        authorEdit = new QLineEdit(frame);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));

        AuthorL->addWidget(authorEdit);


        verticalLayout->addLayout(AuthorL);

        SeparatorL = new QHBoxLayout();
        SeparatorL->setSpacing(6);
        SeparatorL->setObjectName(QString::fromUtf8("SeparatorL"));
        separatorLbl = new QLabel(frame);
        separatorLbl->setObjectName(QString::fromUtf8("separatorLbl"));

        SeparatorL->addWidget(separatorLbl);

        spacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SeparatorL->addItem(spacer4);

        separatorEdit = new QLineEdit(frame);
        separatorEdit->setObjectName(QString::fromUtf8("separatorEdit"));

        SeparatorL->addWidget(separatorEdit);


        verticalLayout->addLayout(SeparatorL);

        EmailL = new QHBoxLayout();
        EmailL->setSpacing(6);
        EmailL->setObjectName(QString::fromUtf8("EmailL"));
        emailLbl = new QLabel(frame);
        emailLbl->setObjectName(QString::fromUtf8("emailLbl"));

        EmailL->addWidget(emailLbl);

        spacer7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        EmailL->addItem(spacer7);

        emailEdit = new QLineEdit(frame);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        EmailL->addWidget(emailEdit);


        verticalLayout->addLayout(EmailL);

        TelephoneL = new QHBoxLayout();
        TelephoneL->setSpacing(6);
        TelephoneL->setObjectName(QString::fromUtf8("TelephoneL"));
        telepLbl = new QLabel(frame);
        telepLbl->setObjectName(QString::fromUtf8("telepLbl"));

        TelephoneL->addWidget(telepLbl);

        spacer8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TelephoneL->addItem(spacer8);

        telepEdit = new QLineEdit(frame);
        telepEdit->setObjectName(QString::fromUtf8("telepEdit"));

        TelephoneL->addWidget(telepEdit);


        verticalLayout->addLayout(TelephoneL);

        SupDivLineL = new QHBoxLayout();
        SupDivLineL->setSpacing(6);
        SupDivLineL->setObjectName(QString::fromUtf8("SupDivLineL"));
        supDivLbl = new QLabel(frame);
        supDivLbl->setObjectName(QString::fromUtf8("supDivLbl"));

        SupDivLineL->addWidget(supDivLbl);

        supDivEdit = new QTextEdit(frame);
        supDivEdit->setObjectName(QString::fromUtf8("supDivEdit"));

        SupDivLineL->addWidget(supDivEdit);


        verticalLayout->addLayout(SupDivLineL);

        SubDivLineL = new QHBoxLayout();
        SubDivLineL->setSpacing(6);
        SubDivLineL->setObjectName(QString::fromUtf8("SubDivLineL"));
        subDivLbl = new QLabel(frame);
        subDivLbl->setObjectName(QString::fromUtf8("subDivLbl"));

        SubDivLineL->addWidget(subDivLbl);

        subDivEdit = new QTextEdit(frame);
        subDivEdit->setObjectName(QString::fromUtf8("subDivEdit"));

        SubDivLineL->addWidget(subDivEdit);


        verticalLayout->addLayout(SubDivLineL);


        horizontalLayout_2->addLayout(verticalLayout);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(1);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(line);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        GithubL = new QHBoxLayout();
        GithubL->setSpacing(6);
        GithubL->setObjectName(QString::fromUtf8("GithubL"));
        githubLbl = new QLabel(frame);
        githubLbl->setObjectName(QString::fromUtf8("githubLbl"));

        GithubL->addWidget(githubLbl);

        spacer1_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        GithubL->addItem(spacer1_4);

        githubEdit = new QLineEdit(frame);
        githubEdit->setObjectName(QString::fromUtf8("githubEdit"));

        GithubL->addWidget(githubEdit);


        verticalLayout_6->addLayout(GithubL);

        TeamL = new QHBoxLayout();
        TeamL->setSpacing(6);
        TeamL->setObjectName(QString::fromUtf8("TeamL"));
        teamLbl = new QLabel(frame);
        teamLbl->setObjectName(QString::fromUtf8("teamLbl"));

        TeamL->addWidget(teamLbl);

        spacer1_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        TeamL->addItem(spacer1_5);

        teamEdit = new QLineEdit(frame);
        teamEdit->setObjectName(QString::fromUtf8("teamEdit"));

        TeamL->addWidget(teamEdit);


        verticalLayout_6->addLayout(TeamL);

        MemoL = new QHBoxLayout();
        MemoL->setSpacing(6);
        MemoL->setObjectName(QString::fromUtf8("MemoL"));
        memoLbl = new QLabel(frame);
        memoLbl->setObjectName(QString::fromUtf8("memoLbl"));

        MemoL->addWidget(memoLbl);

        memoEdit = new QTextEdit(frame);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        MemoL->addWidget(memoEdit);


        verticalLayout_6->addLayout(MemoL);


        horizontalLayout_2->addLayout(verticalLayout_6);


        horizontalLayout_13->addWidget(frame);

        tabWidget->addTab(SettingTab, QString());
        FlagTab = new QWidget();
        FlagTab->setObjectName(QString::fromUtf8("FlagTab"));
        horizontalLayout_3 = new QHBoxLayout(FlagTab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        flagTabL1 = new QVBoxLayout();
        flagTabL1->setSpacing(6);
        flagTabL1->setObjectName(QString::fromUtf8("flagTabL1"));
        flagTblWidget = new QTableWidget(FlagTab);
        if (flagTblWidget->columnCount() < 2)
            flagTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        flagTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        flagTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (flagTblWidget->rowCount() < 13)
            flagTblWidget->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        flagTblWidget->setVerticalHeaderItem(12, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        flagTblWidget->setItem(0, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        flagTblWidget->setItem(0, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        flagTblWidget->setItem(1, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        flagTblWidget->setItem(1, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        flagTblWidget->setItem(2, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        flagTblWidget->setItem(2, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        flagTblWidget->setItem(3, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        flagTblWidget->setItem(3, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        flagTblWidget->setItem(4, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        flagTblWidget->setItem(4, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        flagTblWidget->setItem(5, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        flagTblWidget->setItem(5, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        flagTblWidget->setItem(6, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        flagTblWidget->setItem(6, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        flagTblWidget->setItem(7, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        flagTblWidget->setItem(7, 1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        flagTblWidget->setItem(8, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        flagTblWidget->setItem(8, 1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        flagTblWidget->setItem(9, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        flagTblWidget->setItem(9, 1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        flagTblWidget->setItem(10, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        flagTblWidget->setItem(10, 1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        flagTblWidget->setItem(11, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        flagTblWidget->setItem(11, 1, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        flagTblWidget->setItem(12, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        flagTblWidget->setItem(12, 1, __qtablewidgetitem40);
        flagTblWidget->setObjectName(QString::fromUtf8("flagTblWidget"));

        flagTabL1->addWidget(flagTblWidget);


        horizontalLayout_3->addLayout(flagTabL1);

        tabWidget->addTab(FlagTab, QString());
        DescTab = new QWidget();
        DescTab->setObjectName(QString::fromUtf8("DescTab"));
        verticalLayout_4 = new QVBoxLayout(DescTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        descTabL1 = new QVBoxLayout();
        descTabL1->setSpacing(6);
        descTabL1->setObjectName(QString::fromUtf8("descTabL1"));
        descTblWidget = new QTableWidget(DescTab);
        if (descTblWidget->columnCount() < 2)
            descTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem42);
        descTblWidget->setObjectName(QString::fromUtf8("descTblWidget"));

        descTabL1->addWidget(descTblWidget);

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


        descTabL1->addLayout(descTabL2);


        verticalLayout_4->addLayout(descTabL1);

        tabWidget->addTab(DescTab, QString());
        IssueTab = new QWidget();
        IssueTab->setObjectName(QString::fromUtf8("IssueTab"));
        horizontalLayout_10 = new QHBoxLayout(IssueTab);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        issueTabL = new QVBoxLayout();
        issueTabL->setSpacing(6);
        issueTabL->setObjectName(QString::fromUtf8("issueTabL"));
        issueTblWidget = new QTableWidget(IssueTab);
        if (issueTblWidget->columnCount() < 2)
            issueTblWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        issueTblWidget->setObjectName(QString::fromUtf8("issueTblWidget"));

        issueTabL->addWidget(issueTblWidget);

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


        issueTabL->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(issueTabL);

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
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        referenceTbl->setHorizontalHeaderItem(0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        referenceTbl->setHorizontalHeaderItem(1, __qtablewidgetitem46);
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
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        excludeTbl->setHorizontalHeaderItem(0, __qtablewidgetitem47);
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
        menuBar->setGeometry(QRect(0, 0, 755, 21));
        menuFiel = new QMenu(menuBar);
        menuFiel->setObjectName(QString::fromUtf8("menuFiel"));
        menuOpen_Recents = new QMenu(menuFiel);
        menuOpen_Recents->setObjectName(QString::fromUtf8("menuOpen_Recents"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFiel->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFiel->addAction(actionOpen);
        menuFiel->addAction(actionOpen_Project_Path);
        menuFiel->addAction(actionOpen_and_run);
        menuFiel->addAction(menuOpen_Recents->menuAction());
        menuFiel->addSeparator();
        menuFiel->addAction(actionRefresh);
        menuFiel->addSeparator();
        menuFiel->addAction(actionSave);
        menuFiel->addAction(actionSave_as);
        menuFiel->addSeparator();
        menuFiel->addAction(actionExecute);
        menuFiel->addAction(actionRemove_Comments);
        menuFiel->addSeparator();
        menuFiel->addAction(actionExit);
        menuOpen_Recents->addAction(actionrecent1);
        menuOpen_Recents->addAction(actionrecent2);
        menuOpen_Recents->addAction(actionrecent3);
        menuOpen_Recents->addAction(actionrecent4);
        menuHelp->addAction(actionGithub);
        menuSetting->addAction(actionRecursive_Traversal);
        menuSetting->addSeparator();
        menuSetting->addAction(actionIssue_Numbering);
        menuSetting->addAction(actionDesc_Numbering);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGithub->setText(QCoreApplication::translate("MainWindow", "Github", nullptr));
        actionExecute->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
#if QT_CONFIG(shortcut)
        actionExecute->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionOpen_and_run->setText(QCoreApplication::translate("MainWindow", "Open and Run", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_and_run->setShortcut(QCoreApplication::translate("MainWindow", "Shift+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove_Comments->setText(QCoreApplication::translate("MainWindow", "Remove Comments", nullptr));
        actionRecursive_Traversal->setText(QCoreApplication::translate("MainWindow", "Recursive Traversal", nullptr));
        actionrecent1->setText(QCoreApplication::translate("MainWindow", "recent1", nullptr));
        actionrecent2->setText(QCoreApplication::translate("MainWindow", "recent2", nullptr));
        actionrecent3->setText(QCoreApplication::translate("MainWindow", "recent3", nullptr));
        actionrecent4->setText(QCoreApplication::translate("MainWindow", "recent4", nullptr));
        actionIssue_Numbering->setText(QCoreApplication::translate("MainWindow", "Issue Numbering", nullptr));
#if QT_CONFIG(shortcut)
        actionIssue_Numbering->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDesc_Numbering->setText(QCoreApplication::translate("MainWindow", "Desc Numbering", nullptr));
#if QT_CONFIG(shortcut)
        actionDesc_Numbering->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Project_Path->setText(QCoreApplication::translate("MainWindow", "Open Project Path", nullptr));
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
#if QT_CONFIG(shortcut)
        actionRefresh->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        extensionLbl->setText(QCoreApplication::translate("MainWindow", "Extension", nullptr));
        pathLbl->setText(QCoreApplication::translate("MainWindow", "Project Path", nullptr));
        authorLbl->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        separatorLbl->setText(QCoreApplication::translate("MainWindow", "Separator", nullptr));
        emailLbl->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        telepLbl->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        supDivLbl->setText(QCoreApplication::translate("MainWindow", "Sup Div Line", nullptr));
        subDivLbl->setText(QCoreApplication::translate("MainWindow", "Sub Div Line", nullptr));
        githubLbl->setText(QCoreApplication::translate("MainWindow", "Github Account", nullptr));
        teamLbl->setText(QCoreApplication::translate("MainWindow", "Team", nullptr));
        memoLbl->setText(QCoreApplication::translate("MainWindow", "Memo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QCoreApplication::translate("MainWindow", "Global", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flagTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flagTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = flagTblWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = flagTblWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = flagTblWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = flagTblWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = flagTblWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = flagTblWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = flagTblWidget->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = flagTblWidget->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = flagTblWidget->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = flagTblWidget->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = flagTblWidget->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = flagTblWidget->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = flagTblWidget->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "14", nullptr));

        const bool __sortingEnabled = flagTblWidget->isSortingEnabled();
        flagTblWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem15 = flagTblWidget->item(0, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = flagTblWidget->item(0, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = flagTblWidget->item(1, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Last_Edited", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = flagTblWidget->item(1, 1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = flagTblWidget->item(2, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Desc", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = flagTblWidget->item(2, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = flagTblWidget->item(3, 0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = flagTblWidget->item(3, 1);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = flagTblWidget->item(4, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Sup_Div_Line", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = flagTblWidget->item(4, 1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = flagTblWidget->item(5, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Sub_Div_Line", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = flagTblWidget->item(5, 1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = flagTblWidget->item(6, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = flagTblWidget->item(6, 1);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = flagTblWidget->item(7, 0);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = flagTblWidget->item(7, 1);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = flagTblWidget->item(8, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Github_Account", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = flagTblWidget->item(8, 1);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = flagTblWidget->item(9, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "Ref_URLs", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = flagTblWidget->item(9, 1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = flagTblWidget->item(10, 0);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "Created_Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = flagTblWidget->item(10, 1);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = flagTblWidget->item(11, 0);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "Team", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = flagTblWidget->item(11, 1);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = flagTblWidget->item(12, 0);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "Memo", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = flagTblWidget->item(12, 1);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        flagTblWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(FlagTab), QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = descTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = descTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        descAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        descRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        descSortBtn->setText(QCoreApplication::translate("MainWindow", "Sort By File Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DescTab), QCoreApplication::translate("MainWindow", "Desc", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = issueTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = issueTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "Issue", nullptr));
        issueAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        issueRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        issueSortBtn->setText(QCoreApplication::translate("MainWindow", "Sort By File Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(IssueTab), QCoreApplication::translate("MainWindow", "Issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = referenceTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = referenceTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "URLs", nullptr));
        addReferenceBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        rmReferenceBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        referenceSortBtn->setText(QCoreApplication::translate("MainWindow", "Sort By File Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(referenceTab), QCoreApplication::translate("MainWindow", "Reference", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = excludeTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "File Name to exclude", nullptr));
        addExcludeBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        rmExcludeBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        sortExcludeBtn->setText(QCoreApplication::translate("MainWindow", "Sort By File Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(excludeTab), QCoreApplication::translate("MainWindow", "Exclude", nullptr));
#if QT_CONFIG(tooltip)
        previewTextEdit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Check the comments to add</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        copyBtn->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        executeBtn->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PreviewTab), QCoreApplication::translate("MainWindow", "Preview", nullptr));
        menuFiel->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_Recents->setTitle(QCoreApplication::translate("MainWindow", "Open Recents", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
