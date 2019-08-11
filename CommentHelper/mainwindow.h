#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QTableWidget;

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

private:

    Ui::MainWindow *ui;

    QLineEdit* projPathEdit;
    QLineEdit* targetExtensEdit;
    QLineEdit* authorEdit;
    QLineEdit* separatorEdit;

    void setIssueTable();

    void setDescTable();

    void setFlagTable();

    void processFlag(QString& str, const QString& key, const QString& value, int row, int col);

    void insertItem(QTableWidget* widget, bool keyEditable, const QString& key, const QString& value);

};

#endif // MAINWINDOW_H
