#include "Simulator.h"

#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    Simulator simulator(3);

    std::ifstream file("input/input_task2.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to open input file\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string word;
        std::string taskId;

        int burst = 0;

        std::vector<std::string> memoryBlocks;

        ss >> word; // TASK

        ss >> taskId;

        ss >> word; // BURST

        ss >> burst;

        ss >> word; // MEM

        std::string block;

        while (ss >> block)
        {
            memoryBlocks.push_back(block);
        }

        simulator.addTask(
            taskId,
            burst,
            memoryBlocks
        );
    }

    file.close();

    simulator.run();

    simulator.printResults();

    return 0;
}