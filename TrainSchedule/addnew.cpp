#include "addnew.h"
#include "ui_addnew.h"
#include "train.h"
#include "mainwindow.h"
#include <QDebug>


addNew::addNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNew)
{
    ui->setupUi(this);
    a = new QMessageBox(this);

    QRegExpValidator* rxv = new QRegExpValidator(QRegExp("\\d*"), this); // Установка валидатора для номера поезда.
    ui->TETrainNumber->setValidator(rxv);

    QRegExpValidator* rxr = new QRegExpValidator(QRegExp("[a-zA-Zа-яА-Я-' ]*"), this); // Установка валидатора для места назначения.
    ui->TEDestination->setValidator(rxr);

    train = new TRAIN();
}

addNew::~addNew()
{
    delete ui;
}

void addNew::on_BCreate_clicked()
{
    if ((ui->TETrainNumber->text()!= "") && (ui->TEDestination->text()!= "")) {

    // Ввод номера поезда
    QString trainNum = ui->TETrainNumber->text();
    train->setTrainNumber(trainNum.toStdString());

    // Ввод и проверка времени отправления
    QString time = ui->dateTimeEdit->text();
    train->setTime(time.toStdString());

    // Ввод и проверка места назначения
    QString dest = ui->TEDestination->text();
    train->setDestination(dest.toStdString());

    train->setQueryToInsert();

    this->close();

    } else {
        a->warning(this, "Warning", "Вы оставили пустые поля");
    }
}
