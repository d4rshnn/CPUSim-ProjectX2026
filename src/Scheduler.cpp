#include "Scheduler.h"

Scheduler::Scheduler(int q)
{
    quantum = q;
}

void Scheduler::addTask(Task* task)
{
    readyQueue.push(task);
}

Task* Scheduler::getNextTask()
{
    if (readyQueue.empty())
    {
        return nullptr;
    }

    Task* task = readyQueue.front();
    readyQueue.pop();

    return task;
}

void Scheduler::requeueTask(Task* task)
{
    readyQueue.push(task);
}

bool Scheduler::hasTasks() const
{
    return !readyQueue.empty();
}

int Scheduler::getQuantum() const
{
    return quantum;
}