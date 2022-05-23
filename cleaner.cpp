#include "cleaner.h"

Cleaner::Cleaner(): T(0), DataBase("database_name") {}

int Cleaner::Clean() {return 0;}

int Cleaner::Loop_Clean() {return 0;}

void Cleaner::Set_time (int t) {}

void Cleaner::Set_database(std::string db) {}

void Cleaner::Sleep() {}

int Cleaner::Daemon_work()
{
    return workingStatus;
}



