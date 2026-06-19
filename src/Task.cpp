#include "Task.h"

Task::Task(
    const std::string& taskId,
    int burst,
    const std::vector<std::string>& memBlocks)
{
    id = taskId;
    burstTime = burst;
    remainingBurst = burst;

    memoryBlocks = memBlocks;
    currentMemoryIndex = 0;
}

std::string Task::getNextMemoryRequest()
{
    if (memoryBlocks.empty())
    {
        return "";
    }

    std::string block = memoryBlocks[currentMemoryIndex];

    currentMemoryIndex =
        (currentMemoryIndex + 1) % memoryBlocks.size();

    return block;
}

bool Task::isFinished() const
{
    return remainingBurst <= 0;
}