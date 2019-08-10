#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(WIN_TITLE);

    projPathEdit = ui->pathEdit;
    targetExtensEdit = ui->extensionEdit;
    authorEdit = ui->authorEdit;
    separatorEdit = ui->separatorEdit;

    projPathEdit->setText("C:\\");
    targetExtensEdit->setText("cpp, h");
    authorEdit->setText("jopemachine");
    separatorEdit->setText("//");

    ui->flagTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->flagTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->descTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->descTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->issueTblWidget->horizontalHeader()->setStretchLastSection(true);
    ui->issueTblWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

}

void MainWindow::InsertItem(QTableWidget& tbl, const QString& key, const QString& value){

    int row = tbl.rowCount();
    tbl.insertRow(row);

    auto keyColumn = new QTableWidgetItem(key);
    auto valueColumn = new QTableWidgetItem(value);

    tbl.setItem(row, 0, keyColumn);
    tbl.setItem(row, 1, valueColumn);

}

QString MainWindow::GetProjPath(){
    return projPathEdit->text();
}

QString MainWindow::GetSeparator(){
    return separatorEdit->text();
}

QString MainWindow::GetAuthor(){
    return authorEdit->text();
}

QString MainWindow::GetTargetExtens(){
    return targetExtensEdit->text();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_flagAddBtn_clicked()
{

}

void MainWindow::on_flagRemoveBtn_clicked()
{
    ui->flagTblWidget->removeRow(ui->flagTblWidget->currentRow());
}

void MainWindow::on_descAddBtn_clicked()
{

}

void MainWindow::on_descRemoveBtn_clicked()
{
    ui->descTblWidget->removeRow(ui->descTblWidget->currentRow());
}

void MainWindow::on_issueAddBtn_clicked()
{

}

void MainWindow::on_issueRemoveBtn_clicked()
{
    ui->issueTblWidget->removeRow(ui->issueTblWidget->currentRow());
}
