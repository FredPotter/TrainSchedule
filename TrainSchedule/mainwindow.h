#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <string>
#include <iostream>

namespace Ui {

class MainWindow;
}
/*!
    \brief Класс реализующий интерфейс главного окна

    Данный класс реализует интерфейс главного окна,
    создает соединение с базой данных с помощью QSqlDatabase,
    QSqlQuery.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
      \brief Функция обрабатывающая нажатие на кнопку "добавить новый путь"

      После нажатия на кнопку открывается addNew, там создается объект TRAIN,
      заполняется данными, а после в mainWindow проверяется есть ли созданный запрос,
      если его нет, то ничего не происходит, а если есть, то отправляется запрос в базу данных.
    */
    void on_add_way_triggered();

    /*!
      \brief Функция обрабатывающая нажатие на кнопку "найти пути"

      После нажатия на кнопку открывается searchWindow, там создается строка destin,
      заполняется данными, а после в mainWindow проверяется заполнена ли строка destin,
      если нет, то ничего не происходит, а если да, то на таблицу устанавливается фильтр по колонке
      Destination
    */
    void on_find_way_triggered();

    /*!
      \brief Функция обрабатывающая нажатие на кнопку "удалить строку"

      После нажатия удаляется строка выбранная пользователем
    */
    void on_delete_row_triggered();
    /*!
      \brief Функция обрабатывающая нажатие на таблицу

      для отслеживания на какую строку щелкнул пользователь для её дальнейшего удаления
    */
    void on_tableView_clicked(const QModelIndex &index);

    /*!
      \brief Функция обрабатывающая нажатие на кнопку "убрать фильтр поиска"

      После нажатия на кнопку фильтр поиска возвращается в позицию "по умолчанию"
    */
    void on_close_search_triggered();

private:
    //! \brief Для работы с графическим интерфейсом
    Ui::MainWindow *ui;
    //! \brief Для соединения с базой данных
    QSqlDatabase db;
    //! \brief Для выполнения запросов в базу данных
    QSqlQuery *query;
    //! \brief Для работы с таблицей в графическом виде.
    QSqlTableModel *model;
    //! \brief Для отслеживания номера строки на которую нажимает пользователь, для полседующего удаления
    int row; // Номер активной строки.
};

#endif // MAINWINDOW_H
