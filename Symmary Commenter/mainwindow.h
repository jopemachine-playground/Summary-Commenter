#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// ==============================+===============================================================
// Import

#include <stack>
#include <queue>
#include <memory>
#include <memory.h>

#include <QMainWindow>
#include <QDateTime>

#include <QMimeData>
#include <QDragEnterEvent>

// ==============================+===============================================================
// Forward declare

namespace Ui {
class MainWindow;
}

QT_FORWARD_DECLARE_CLASS( QLineEdit );
QT_FORWARD_DECLARE_CLASS( QTableWidget );
QT_FORWARD_DECLARE_CLASS( QTableWidgetItem );
QT_FORWARD_DECLARE_CLASS( QFile );
QT_FORWARD_DECLARE_CLASS( QFileDialog );
QT_FORWARD_DECLARE_CLASS( QTextStream );

// ==============================+===============================================================

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
    REFURLS,
    CREATEDDATE,
    TEAM,
    MEMO
};

typedef struct{
    QString filePath;
    QString fileName;
    QDateTime lastModified;
    QDateTime created;
} FileInfo;

template<class T>
using s_ptr = std::shared_ptr<T>;

template<class T>
using queue = std::queue<T>;

// ==============================+===============================================================

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void ShowMessageBox(const QString&, const QString&);

    bool Open();

    void OpenRecent(const int);

    void Run();

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

    void on_actionRemove_Comments_triggered();

    void on_actionrecent1_triggered();

    void on_actionrecent2_triggered();

    void on_actionrecent3_triggered();

    void on_actionrecent4_triggered();

    void on_descSortBtn_clicked();

    void on_issueSortBtn_clicked();

    void on_referenceSortBtn_clicked();

    void on_addExcludeBtn_clicked();

    void on_rmExcludeBtn_clicked();

    void on_sortExcludeBtn_clicked();

    void on_actionOpen_Project_Path_triggered();

    void on_actionRefresh_triggered();

    void on_actionSave_md_triggered();

    void on_actionRemove_Comments_From_All_File_triggered();

    void on_actionOpen_setting_file_triggered();

private:

    // member vars
    Ui::MainWindow*                                 ui;
    QString                                         selectedFile;
    QFile*                                          chLately;
    std::deque<QString>*                            pathQue;

    // setting table
    void                        setTable            (QTableWidget*);
    void                        clearTbl            (QTableWidget*);
    void                        sortTbl             (QTableWidget*);
    void                        insertTbl           (QTableWidget*, const QString&, const QString& value = nullptr);
    void                        setShortCut         ();

    // setting table's dragging event
    void                        dragEnterEvent      (QDragEnterEvent *e) override;
    void                        dropEvent           (QDropEvent *e) override;

    // handle tables
    QTableWidgetItem*           searchTable         (QTableWidget* tbl, const QString& key);
    void                        insertItem          (QTableWidget* tbl, bool keyEditable, const QString& key, const QString& value);
    void                        removeSelectedItems (QTableWidget* tbl);

    // file save and load
    void                        setCHSFile          (const QString& path);
    void                        saveCHSFile         (const QString& path);
    void                        addGlobalVars       (const QString& key, const QString& value);
    void                        setSettingFlags     (const QString& flagName, bool flag);
    void                        makeMDForm          (QTextStream& ts, const QTableWidget* tbl, const QString& tblName);
    void                        openRecentPathsFile ();

    // directory traversal recursively and get all file info (except link file)
    s_ptr<queue<FileInfo>>      getAllTargetFiles   (const QString& dirName);

    // make and prepend comment
    void                        prependComment      (FileInfo fileInfo);
    void                        processFlag         (QTextStream& ts, const QString& key, const QString& value, FlagType flag, bool previewMode, bool keyValueSpace);
    void                        makeComment         (QTextStream& ts, const FileInfo& fileName);
    s_ptr<QString>              makeFromTbl         (QTableWidget* tbl, bool numbering, const FileInfo& fileInfo);

    void                        removeComment       (QStringList& strList);



};

#endif // MAINWINDOW_H
