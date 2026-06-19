#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task
{
public:
    std::string id;
    int burstTime;
    int remainingBurst;

    std::vector<std::string> memoryBlocks;
    int currentMemoryIndex;

    Task(
        const std::string& taskId,
        int burst,
        const std::vector<std::string>& memBlocks
    );

    std::string getNextMemoryRequest();

    bool isFinished() const;
};

#endif