#include "Simulator.h"

#include <iostream>

Simulator::Simulator(int quantum)
    : scheduler(quantum)
{
    totalCycles = 0;
    completedTasks = 0;
    totalLatency = 0;
}

void Simulator::addTask(
    const std::string& id,
    int burst,
    const std::vector<std::string>& memoryBlocks)
{
    tasks.push_back(
        std::make_unique<Task>(
            id,
            burst,
            memoryBlocks
        )
    );

    scheduler.addTask(tasks.back().get());
}

void Simulator::run()
{
    while (scheduler.hasTasks())
    {
        Task* currentTask = scheduler.getNextTask();

        if (currentTask == nullptr)
        {
            break;
        }

        int quantum = scheduler.getQuantum();

        for (int i = 0; i < quantum; i++)
        {
            if (currentTask->isFinished())
            {
                break;
            }

            totalCycles++;

            std::string block =
                currentTask->getNextMemoryRequest();

            int latency =
                cache.accessBlock(block);

            totalLatency += latency;

            std::cout
                << "\nCycle "
                << totalCycles
                << "\nRunning: "
                << currentTask->id
                << "\nRequesting: "
                << block
                << "\nLatency: "
                << latency
                << "\n";

            cache.printCacheState();

            std::cout
                << "--------------------\n";

            currentTask->remainingBurst--;
        }

        if (currentTask->isFinished())
        {
            completedTasks++;
        }
        else
        {
            scheduler.requeueTask(currentTask);
        }
    }
}

void Simulator::printResults() const
{
    std::cout << "\n=== Final Results ===\n";

    std::cout
        << "Total Cycles: "
        << totalCycles
        << "\n";

    std::cout
        << "Tasks Completed: "
        << completedTasks
        << "\n";

    std::cout
        << "RAM Accesses: "
        << cache.getRamAccesses()
        << "\n";

    std::cout
        << "Total Latency: "
        << totalLatency
        << "\n";
}