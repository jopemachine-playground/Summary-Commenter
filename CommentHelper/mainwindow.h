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

    void on_flagAddBtn_clicked();

    void on_flagRemoveBtn_clicked();

    void on_descAddBtn_clicked();

    void on_descRemoveBtn_clicked();

    void on_issueAddBtn_clicked();

    void on_issueRemoveBtn_clicked();

private:

    Ui::MainWindow *ui;

    QLineEdit* projPathEdit;
    QLineEdit* targetExtensEdit;
    QLineEdit* authorEdit;
    QLineEdit* separatorEdit;

    void InsertItem(QTableWidget& widget, const QString& key, const QString& value);

};

#endif // MAINWINDOW_H
