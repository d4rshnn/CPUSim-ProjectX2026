#include "Cache.h"
#include<iostream>

Cache::Cache()
{
    ramAccesses = 0;
}

bool Cache::contains(
    const std::deque<std::string>& cache,
    const std::string& block) const
{
    for (const auto& item : cache)
    {
        if (item == block)
        {
            return true;
        }
    }

    return false;
}

void Cache::insertIntoL3(const std::string& block)
{
    if (contains(l3, block))
    {
        return;
    }

    if ((int)l3.size() >= 512)
    {
        l3.pop_front();
    }

    l3.push_back(block);
}

void Cache::insertIntoL2(const std::string& block)
{
    if (contains(l2, block))
    {
        return;
    }

    if ((int)l2.size() >= 128)
    {
        std::string evicted = l2.front();
        l2.pop_front();

        insertIntoL3(evicted);
    }

    l2.push_back(block);
}

void Cache::insertIntoL1(const std::string& block)
{
    if (contains(l1, block))
    {
        return;
    }

    if ((int)l1.size() >= 32)
    {
        std::string evicted = l1.front();
        l1.pop_front();

        insertIntoL2(evicted);
    }

    l1.push_back(block);
}

int Cache::accessBlock(const std::string& block)
{
    // L1 HIT
    if (contains(l1, block))
    {
        return 4;
    }

    // L2 HIT
    if (contains(l2, block))
    {
        insertIntoL1(block);
        return 12;
    }

    // L3 HIT
    if (contains(l3, block))
    {
        insertIntoL1(block);
        return 40;
    }

    // RAM ACCESS
    ramAccesses++;

    insertIntoL1(block);

    return 200;
}

int Cache::getRamAccesses() const
{
    return ramAccesses;
}

const std::deque<std::string>& Cache::getL1() const
{
    return l1;
}

const std::deque<std::string>& Cache::getL2() const
{
    return l2;
}

const std::deque<std::string>& Cache::getL3() const
{
    return l3;
}
void Cache::printCacheState() const
{
    std::cout << "L1: [";

    for (const auto& block : l1)
    {
        std::cout << block << " ";
    }

    std::cout << "]\n";

    std::cout << "L2: [";

    for (const auto& block : l2)
    {
        std::cout << block << " ";
    }

    std::cout << "]\n";

    std::cout << "L3: [";

    for (const auto& block : l3)
    {
        std::cout << block << " ";
    }

    std::cout << "]\n";
}