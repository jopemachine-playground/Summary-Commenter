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
    QAction *actionAdd_Setting;
    QAction *actionOpen_Recents;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
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
    QSpacerItem *spacer7_2;
    QTextEdit *supDivEdit;
    QHBoxLayout *SubDivLineL;
    QLabel *subDivLbl;
    QSpacerItem *spacer7_3;
    QTextEdit *subDivEdit;
    QFrame *line;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *GithubL;
    QLabel *githubLbl;
    QSpacerItem *spacer1_4;
    QLineEdit *githubEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ReferenceL;
    QLabel *referenceLbl;
    QTextEdit *textEdit;
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
    QWidget *IssueTab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *issueTabL;
    QTableWidget *issueTblWidget;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *issueAddBtn;
    QPushButton *issueRemoveBtn;
    QWidget *referenceTab;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *referenceTbl;
    QHBoxLayout *ReferenceL_2;
    QPushButton *addReferenceBtn;
    QPushButton *rmReferenceBtn;
    QWidget *PreviewTab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *previewTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *copyBtn;
    QPushButton *executeBtn;
    QMenuBar *menuBar;
    QMenu *menuFiel;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 450);
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
        actionAdd_Setting = new QAction(MainWindow);
        actionAdd_Setting->setObjectName(QString::fromUtf8("actionAdd_Setting"));
        actionOpen_Recents = new QAction(MainWindow);
        actionOpen_Recents->setObjectName(QString::fromUtf8("actionOpen_Recents"));
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
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
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

        spacer7_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SupDivLineL->addItem(spacer7_2);

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

        spacer7_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SubDivLineL->addItem(spacer7_3);

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

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
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


        verticalLayout_8->addLayout(GithubL);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        ReferenceL = new QHBoxLayout();
        ReferenceL->setSpacing(6);
        ReferenceL->setObjectName(QString::fromUtf8("ReferenceL"));
        referenceLbl = new QLabel(frame);
        referenceLbl->setObjectName(QString::fromUtf8("referenceLbl"));

        ReferenceL->addWidget(referenceLbl);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        ReferenceL->addWidget(textEdit);


        verticalLayout_8->addLayout(ReferenceL);


        horizontalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout_4->addLayout(horizontalLayout_2);


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
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        descTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
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
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        issueTblWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
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


        verticalLayout_9->addLayout(ReferenceL_2);


        verticalLayout_10->addLayout(verticalLayout_9);

        tabWidget->addTab(referenceTab, QString());
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
        menuBar->setGeometry(QRect(0, 0, 650, 21));
        menuFiel = new QMenu(menuBar);
        menuFiel->setObjectName(QString::fromUtf8("menuFiel"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFiel->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFiel->addAction(actionOpen);
        menuFiel->addAction(actionOpen_Recents);
        menuFiel->addAction(actionAdd_Setting);
        menuFiel->addSeparator();
        menuFiel->addAction(actionSave);
        menuFiel->addAction(actionSave_as);
        menuFiel->addSeparator();
        menuFiel->addAction(actionExecute);
        menuFiel->addAction(actionOpen_and_run);
        menuFiel->addSeparator();
        menuFiel->addAction(actionExit);
        menuHelp->addAction(actionGithub);

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
        actionAdd_Setting->setText(QCoreApplication::translate("MainWindow", "Add Setting", nullptr));
        actionOpen_Recents->setText(QCoreApplication::translate("MainWindow", "Open Recents", nullptr));
        extensionLbl->setText(QCoreApplication::translate("MainWindow", "Extension", nullptr));
        pathLbl->setText(QCoreApplication::translate("MainWindow", "Project Path", nullptr));
        authorLbl->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        separatorLbl->setText(QCoreApplication::translate("MainWindow", "Separator", nullptr));
        emailLbl->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        telepLbl->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        supDivLbl->setText(QCoreApplication::translate("MainWindow", "Sup Div Line", nullptr));
        subDivLbl->setText(QCoreApplication::translate("MainWindow", "Sub Div Line", nullptr));
        githubLbl->setText(QCoreApplication::translate("MainWindow", "Github Account", nullptr));
        referenceLbl->setText(QCoreApplication::translate("MainWindow", "Memo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QCoreApplication::translate("MainWindow", "Global", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flagTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flagTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(FlagTab), QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = descTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = descTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        descAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        descRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DescTab), QCoreApplication::translate("MainWindow", "Desc", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = issueTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "File Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = issueTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Issue", nullptr));
        issueAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        issueRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(IssueTab), QCoreApplication::translate("MainWindow", "Issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = referenceTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = referenceTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "URLs", nullptr));
        addReferenceBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        rmReferenceBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(referenceTab), QCoreApplication::translate("MainWindow", "Reference", nullptr));
        copyBtn->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        executeBtn->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PreviewTab), QCoreApplication::translate("MainWindow", "Preview", nullptr));
        menuFiel->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
