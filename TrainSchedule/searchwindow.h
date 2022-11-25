#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class searchWindow;
}
/*!
    \brief Класс реализующий интерфейс окна для поиска строк по полю "Destination" в базе данных TrainBD

    Данный реализует интерфейс окна для поиска строк в базе данных TrainBD,
    а также валидатор для пункта назначения
*/
class searchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchWindow(QWidget *parent = 0);
    ~searchWindow();

    //!\brief Поле для хранения места назначения, для дальнейшей передачи в mainWindow
    QString destin;

private slots:
/*!
  \brief Обрабатывает нажатия на кнопку "поиск"

      Функция считывает данные с поля место назначения,
      записывает их в destin. Если пользователь ничего не ввел место назначения,
      выведется предупреждение с помощью QMessageBox
*/
void on_BCreate_clicked();

private:
    //! \brief Для работы с графическим интерфейсом
    Ui::searchWindow *ui;
    //! \brief Экземпляр класса QMessageBox для предупреждения о некорректном вводе
    QMessageBox *s;
};

#endif // SEARCHWINDOW_H
