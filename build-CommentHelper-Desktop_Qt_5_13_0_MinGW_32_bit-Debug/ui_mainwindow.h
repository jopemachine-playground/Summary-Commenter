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
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_12;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame;
    QWidget *layoutWidget;
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
    QWidget *FlagTab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *flagTabL1;
    QTableWidget *flagTblWidget;
    QHBoxLayout *flagTabL2;
    QPushButton *flagAddBtn;
    QPushButton *flagRemoveBtn;
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
    QWidget *PreviewTab;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *previewTextEdit;
    QMenuBar *menuBar;
    QMenu *menuFiel;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(698, 448);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_12 = new QHBoxLayout(centralWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
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
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 11, 281, 136));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ExtensionL = new QHBoxLayout();
        ExtensionL->setSpacing(6);
        ExtensionL->setObjectName(QString::fromUtf8("ExtensionL"));
        extensionLbl = new QLabel(layoutWidget);
        extensionLbl->setObjectName(QString::fromUtf8("extensionLbl"));

        ExtensionL->addWidget(extensionLbl);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ExtensionL->addItem(spacer1);

        extensionEdit = new QLineEdit(layoutWidget);
        extensionEdit->setObjectName(QString::fromUtf8("extensionEdit"));

        ExtensionL->addWidget(extensionEdit);


        verticalLayout->addLayout(ExtensionL);

        PathL = new QHBoxLayout();
        PathL->setSpacing(6);
        PathL->setObjectName(QString::fromUtf8("PathL"));
        pathLbl = new QLabel(layoutWidget);
        pathLbl->setObjectName(QString::fromUtf8("pathLbl"));

        PathL->addWidget(pathLbl);

        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PathL->addItem(spacer2);

        pathEdit = new QLineEdit(layoutWidget);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));

        PathL->addWidget(pathEdit);


        verticalLayout->addLayout(PathL);

        AuthorL = new QHBoxLayout();
        AuthorL->setSpacing(6);
        AuthorL->setObjectName(QString::fromUtf8("AuthorL"));
        authorLbl = new QLabel(layoutWidget);
        authorLbl->setObjectName(QString::fromUtf8("authorLbl"));

        AuthorL->addWidget(authorLbl);

        spacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AuthorL->addItem(spacer3);

        authorEdit = new QLineEdit(layoutWidget);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));

        AuthorL->addWidget(authorEdit);


        verticalLayout->addLayout(AuthorL);

        SeparatorL = new QHBoxLayout();
        SeparatorL->setSpacing(6);
        SeparatorL->setObjectName(QString::fromUtf8("SeparatorL"));
        separatorLbl = new QLabel(layoutWidget);
        separatorLbl->setObjectName(QString::fromUtf8("separatorLbl"));

        SeparatorL->addWidget(separatorLbl);

        spacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SeparatorL->addItem(spacer4);

        separatorEdit = new QLineEdit(layoutWidget);
        separatorEdit->setObjectName(QString::fromUtf8("separatorEdit"));

        SeparatorL->addWidget(separatorEdit);


        verticalLayout->addLayout(SeparatorL);


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

        flagTabL2 = new QHBoxLayout();
        flagTabL2->setSpacing(6);
        flagTabL2->setObjectName(QString::fromUtf8("flagTabL2"));
        flagAddBtn = new QPushButton(FlagTab);
        flagAddBtn->setObjectName(QString::fromUtf8("flagAddBtn"));

        flagTabL2->addWidget(flagAddBtn);

        flagRemoveBtn = new QPushButton(FlagTab);
        flagRemoveBtn->setObjectName(QString::fromUtf8("flagRemoveBtn"));

        flagTabL2->addWidget(flagRemoveBtn);


        flagTabL1->addLayout(flagTabL2);


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
        PreviewTab = new QWidget();
        PreviewTab->setObjectName(QString::fromUtf8("PreviewTab"));
        horizontalLayout = new QHBoxLayout(PreviewTab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previewTextEdit = new QPlainTextEdit(PreviewTab);
        previewTextEdit->setObjectName(QString::fromUtf8("previewTextEdit"));

        horizontalLayout->addWidget(previewTextEdit);

        tabWidget->addTab(PreviewTab, QString());

        horizontalLayout_12->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 698, 21));
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
        menuFiel->addAction(actionSave);
        menuFiel->addAction(actionSave_as);
        menuFiel->addSeparator();
        menuFiel->addAction(actionExecute);
        menuFiel->addAction(actionExit);
        menuHelp->addAction(actionGithub);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGithub->setText(QCoreApplication::translate("MainWindow", "Github", nullptr));
        actionExecute->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
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
        extensionLbl->setText(QCoreApplication::translate("MainWindow", "Extension", nullptr));
        pathLbl->setText(QCoreApplication::translate("MainWindow", "Project Path", nullptr));
        authorLbl->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        separatorLbl->setText(QCoreApplication::translate("MainWindow", "Separator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QCoreApplication::translate("MainWindow", "Global", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flagTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flagTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        flagAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        flagRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(FlagTab), QCoreApplication::translate("MainWindow", "Flag", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = descTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Desc", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = descTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Content", nullptr));
        descAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        descRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DescTab), QCoreApplication::translate("MainWindow", "Desc", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = issueTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = issueTblWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Content", nullptr));
        issueAddBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        issueRemoveBtn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(IssueTab), QCoreApplication::translate("MainWindow", "Issue", nullptr));
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
