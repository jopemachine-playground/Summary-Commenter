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
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_12;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_4;
    QWidget *FlagTab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *DescTab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *IssueTab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *PreviewTab;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
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
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 262, 108));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_7->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_11->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_11->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_11);


        horizontalLayout_13->addWidget(frame);

        tabWidget->addTab(SettingTab, QString());
        FlagTab = new QWidget();
        FlagTab->setObjectName(QString::fromUtf8("FlagTab"));
        horizontalLayout_3 = new QHBoxLayout(FlagTab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(FlagTab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(FlagTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(FlagTab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(FlagTab, QString());
        DescTab = new QWidget();
        DescTab->setObjectName(QString::fromUtf8("DescTab"));
        verticalLayout_4 = new QVBoxLayout(DescTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_2 = new QTableWidget(DescTab);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_3->addWidget(tableWidget_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_3 = new QPushButton(DescTab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(DescTab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        tabWidget->addTab(DescTab, QString());
        IssueTab = new QWidget();
        IssueTab->setObjectName(QString::fromUtf8("IssueTab"));
        horizontalLayout_10 = new QHBoxLayout(IssueTab);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget_3 = new QTableWidget(IssueTab);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));

        verticalLayout_5->addWidget(tableWidget_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_5 = new QPushButton(IssueTab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_8->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(IssueTab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_8->addWidget(pushButton_6);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_5);

        tabWidget->addTab(IssueTab, QString());
        PreviewTab = new QWidget();
        PreviewTab->setObjectName(QString::fromUtf8("PreviewTab"));
        horizontalLayout = new QHBoxLayout(PreviewTab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(PreviewTab);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

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
        menuFiel->addAction(actionExecute);
        menuHelp->addAction(actionGithub);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGithub->setText(QCoreApplication::translate("MainWindow", "Github", nullptr));
        actionExecute->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Extension", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Separator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QCoreApplication::translate("MainWindow", "Global", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(FlagTab), QCoreApplication::translate("MainWindow", "Flag", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DescTab), QCoreApplication::translate("MainWindow", "Desc", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
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
