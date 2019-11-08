#ifndef CLIANER_CLEANER_H
#define CLIANER_CLEANER_H

#include <iostream>
#include "daemon.h"

class Cleaner: Daemon
{
public:
    Cleaner(); //при создании объекта класса период и база данных получают значения по умолчанию

    int Clean(); //Выполнить чистку 1 раз
    int Loop_Clean();//Работать в фоновом режиме, выполнять чистки раз в период (запустить демона методом Daemon.Start())

    void Set_time (int t); //указать другой период
    void Set_database (std::string db); //указать другую базу данных

    time_t Get_time() {return T;}
    std::string Get_database() {return DataBase;}

    int T;
    std::string DataBase;

    void Sleep();

private:

    int Daemon_work() override; //бесконечный цикл из Clean() и Sleep() - почистил/уснул
};

#endif //CLIANER_CLEANER_H
