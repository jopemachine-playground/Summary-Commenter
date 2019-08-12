#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <queue>
#include <memory>

#include <QMainWindow>
#include <QDateTime>

class QLineEdit;
class QTableWidget;
class QTableWidgetItem;
class QFileDialog;
class QTextStream;

namespace Ui {
class MainWindow;
}

enum FlagType{
    AUTHOR = 0,
    LASTEDITED,
    DESC,
    ISSUE,
    SUPDIV,
    SUBDIV,
    EMAIL,
    TELEP,
    GITHUBACC,
    REFURLS
};

typedef struct{
    QString filePath;
    QString fileName;
    QDateTime lastModified;
} FileInfo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString GetProjPath();
    QString GetTargetExtens();
    QString GetAuthor();
    QString GetSeparator();

    void ShowMessageBox(const QString&, const QString&);


private slots:

    void on_descAddBtn_clicked();

    void on_descRemoveBtn_clicked();

    void on_issueAddBtn_clicked();

    void on_issueRemoveBtn_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExecute_triggered();

    void on_actionGithub_triggered();

    void on_actionSave_as_triggered();

    void on_copyBtn_clicked();

    void on_executeBtn_clicked();

    void on_addReferenceBtn_clicked();

    void on_rmReferenceBtn_clicked();

    void on_actionOpen_and_run_triggered();

    void on_actionAdd_Setting_triggered();

    void on_actionOpen_Recents_triggered();

private:

    Ui::MainWindow *ui;

    std::queue<QString> *confQueue;

    QFileDialog* fileOpenDialog;

    QString selectedFile;

    // setting Table
    void setIssueTable();
    void setDescTable();
    void setFlagTable();
    void setReferenceTable();
    void clearTbl(QTableWidget* table);

    // handle tables
    QTableWidgetItem* searchTable(QTableWidget* table, const QString& key);
    void insertItem(QTableWidget* widget, bool keyEditable, const QString& key, const QString& value);

    // file save and load
    void setCHSFile(std::queue<QString>& config);
    void saveCHSFile(const QString& path);
    void addGlobalVars(const QString& key, const QString& value);

    // directory traversal recursively and get all file info (except link file)
    std::shared_ptr<std::queue<FileInfo>> getAllTargetFiles(const QString& dirName);

    // make and prepend comment
    void prependComment(FileInfo fileInfo);
    void processFlag(QTextStream& ts, const QString& key, const QString& value, FlagType flag, bool keyValueSpace);
    void makeComment(QTextStream& ts, const FileInfo& fileName);


};

#endif // MAINWINDOW_H
