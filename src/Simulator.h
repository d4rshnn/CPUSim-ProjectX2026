#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <memory>

#include "Task.h"
#include "Scheduler.h"
#include "Cache.h"

class Simulator
{
private:
    std::vector<std::unique_ptr<Task>> tasks;

    Scheduler scheduler;
    Cache cache;

    int totalCycles;
    int completedTasks;
    long long totalLatency;

public:
    Simulator(int quantum);

    void addTask(
        const std::string& id,
        int burst,
        const std::vector<std::string>& memoryBlocks
    );

    void run();

    void printResults() const;
};

#endif