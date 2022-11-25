#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <QString>


/*!
    \brief Структура реализующая хранение маршрута и создание запросов в базу данных TrainBD

    Данная структура реализует интерфейс хранения маршрута и создания запросов в базу данных TrainBD
*/
struct TRAIN{
private:
    //!\brief номер поезда
    std::string trainNumber;

    //!\brief место назначения
    std::string destination;

    //!\brief время отправления
    std::string time;

    //!\brief переменная для хранения запроса на добавление структуры в базу данных TrainBD
    QString queryToI;
public:
    /*!
        \brief Конструктор по умолчанию для структуры TRAIN
    */
    TRAIN() {}
    /*!
        \brief Конструктор с параметрами для структуры TRAIN
        \param trainNumber Номер поезда
        \param destination Пункт назначения
        \param time Время отправления
    */
    TRAIN(std::string trainNumber, std::string destination, std::string time) {
        this->trainNumber = trainNumber;
        this->destination = destination;
        this->time = time;
    }
    /*!
        \brief Геттер для получения запроса на добавление в базу данных TrainDB
        \return Запрос в виде SQL запроса с подставленными значениями trainNumber, destination и time
    */
    QString getQueryToInsert() {
        return queryToI;
    }
    /*!
        \brief Сеттер для создания запроса на добавление в базу данных TrainDB
        В переменную queryToI записывает запрос в виде INSERT INTO TrainDB (TrainNumber, Destination, DepartureTime) VALUES (...);
    */
    void setQueryToInsert() {
       std::string s = "INSERT INTO TrainDB (TrainNumber, Destination, DepartureTime) VALUES (";
       s += trainNumber;
       s += ", '";
       s += destination;
       s += "'";
       s += ", ";
       s += "'";
       s += time;
       s += "');";
       queryToI = QString::fromStdString(s);
    }
    /*!
        \brief Геттер для получения номера поезда
        \return Номер поезда содержится в переменной trainNumber
    */
    std::string getTrainNumber() {
        return trainNumber;
    }
    /*!
        \brief Сеттер для установки номера поезда
    */
    void setTrainNumber(std::string trainNumber) {
        this->trainNumber = trainNumber;
    }
    /*!
        \brief Геттер для получения места назначения
        \return Место назначения содержится в переменной destination
    */
    std::string getDestination() {
        return destination;
    }
    /*!
        \brief Сеттер для установки места назначения
        \param destination - место назначения
    */
    void setDestination(std::string destination) {
        this->destination = destination;
    }
    /*!
        \brief Геттер для получения времени отправления
        \return Время отправления содержится в переменной time
    */
    std::string getTime() {
        return time;
    }
    /*!
        \brief Сеттер для установки времени отправления
        \param time - врмея отправления
    */
    void setTime(std::string time) {
        this->time = time;
    }
};

#endif // TRAIN_H
