#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <queue>
#include <QMainWindow>

class QLineEdit;
class QTableWidget;
class QTableWidgetItem;
class QFileDialog;

namespace Ui {
class MainWindow;
}

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

private:

    Ui::MainWindow *ui;

    std::queue<QString> *confQueue;

    QLineEdit* projPathEdit;
    QLineEdit* targetExtensEdit;
    QLineEdit* authorEdit;
    QLineEdit* separatorEdit;

    QFileDialog* fileOpenDialog;

    QString selectedFile;

    void setIssueTable();

    void setDescTable();

    void setFlagTable();

    void setCHSFile(std::queue<QString>& config);

    void saveCHSFile(const QString& path);

    QTableWidgetItem* searchTable(QTableWidget* table, const QString& key);

    void processFlag(QString& str, const QString& key, const QString& value, int row, int col);

    void insertItem(QTableWidget* widget, bool keyEditable, const QString& key, const QString& value);

    void addGlobalVars(const QString& key, const QString& value);

};

#endif // MAINWINDOW_H
