#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnew.h"
#include "searchwindow.h"
#include "train.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./trainDB.db");
    if(db.open()) {
        qDebug("trainDB is open");
    } else {
        qDebug("trainDB isn't open");
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE TrainDB (TrainNumber INTEGER, Destination TEXT, DepartureTime TEXT );");
    model = new QSqlTableModel(this, db);
    model->setTable("TrainDB");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_way_triggered()
{
    qDebug("add a new way window is open");
    addNew addWindow;
    addWindow.setModal(true);
    addWindow.exec();
    if (addWindow.train->getQueryToInsert() != "") {
    query->exec(addWindow.train->getQueryToInsert());
    model->select();
    }
}

void MainWindow::on_find_way_triggered()
{
    qDebug("search a way window is open");
    searchWindow sWindow;
    sWindow.setModal(true);
    sWindow.exec();
    std::cout << sWindow.destin.toStdString() << std::endl;
    if (sWindow.destin != "") {
    model->setFilter("Destination='" + sWindow.destin + "'");
    ui->close_search->setEnabled(true);
    }
}

void MainWindow::on_delete_row_triggered()
{
    model->removeRow(row);
    model->select();
    row = -1;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::on_close_search_triggered()
{
    model->setFilter("");
    ui->close_search->setEnabled(false);
}
