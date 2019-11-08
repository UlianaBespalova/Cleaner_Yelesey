#ifndef CLIANER_DAEMON_H
#define CLIANER_DAEMON_H

class Daemon
{
public:
     Daemon(): workingStatus(0) {};
    ~Daemon() = default;

    int workingStatus;

private:
    void Start(); //запуск демона (создание дочернего процесса + Monitoring() + Daemon_work())

    int Monitoring(); //следить за дочернним процессом (в зависимости от возвращаемого значения (workingStatus) перезапускать/завершать/записывать ошибки)
    virtual int Daemon_work() {};
};

#endif //CLIANER_DAEMON_H
