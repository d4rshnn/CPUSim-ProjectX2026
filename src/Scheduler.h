#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include "Task.h"

class Scheduler
{
private:
    std::queue<Task*> readyQueue;
    int quantum;

public:
    Scheduler(int q);

    void addTask(Task* task);

    Task* getNextTask();

    void requeueTask(Task* task);

    bool hasTasks() const;

    int getQuantum() const;
};

#endif