#include <iostream>
#include "daemon.h"

void Daemon::Start() {}

int Daemon::Monitoring()
{
    workingStatus = Daemon_work();
    std::cout << workingStatus;
    return workingStatus;
}
