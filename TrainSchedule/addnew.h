#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>
#include <QMessageBox>
#include "train.h"

namespace Ui {
class addNew;
}

/*!
    \brief Класс реализующий интерфейс окна для добавления новой строки по форме в базу данных TrainBD

    Данный реализует интерфейс окна для добавления новой строки по форме в базу данных TrainBD
    В классе реализованы валидаторы для пункта назначения и номера поезда
    с помощью класса QRegExpValidator и метода setValidator()
*/
class addNew : public QDialog
{
    Q_OBJECT

public:
    explicit addNew(QWidget *parent = 0);
    ~addNew();

    //!\brief Экземпляр структуры TRAIN, необходимый для передачи запроса на добавление в mainWindow
    TRAIN *train;

private slots:
    /*!
      \brief Функция обрабатывающая нажание на кнопку "создать"

      Функция считывает данные с полей о номере поезда, времени отправления и месте назначения,
      записывает их в структуру TRAIN. Если пользователь ничего не ввел в одно из полей,
      выведется предупреждение с помощью QMessageBox
    */
    void on_BCreate_clicked();

private:
    //! \brief Для работы с графическим интерфейсом
    Ui::addNew *ui;
    //! \brief Экземпляр класса QMessageBox для предупреждения о некорректном вводе
    QMessageBox *a;
};

#endif // ADDNEW_H
