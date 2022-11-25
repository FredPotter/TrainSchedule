#include "searchwindow.h"
#include "ui_searchwindow.h"


searchWindow::searchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchWindow)
{
    ui->setupUi(this);

    QRegExpValidator* rxr = new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я-' ]*"), this); // Установка валидатора для места назначения.
    ui->TEDestination2->setValidator(rxr);

    destin = "";

    s = new QMessageBox(this);
}

searchWindow::~searchWindow()
{
    delete ui;
}


void searchWindow::on_BCreate_clicked()
{
    if(ui->TEDestination2->text() != "") {
    destin = ui->TEDestination2->text();
    this->close();
    } else {
        s->warning(this, "Warning", "Вы оставили пустые поля");
    }
}
