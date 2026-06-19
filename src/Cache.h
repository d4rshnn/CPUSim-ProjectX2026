#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <deque>

class Cache
{
private:
    std::deque<std::string> l1;
    std::deque<std::string> l2;
    std::deque<std::string> l3;

    int ramAccesses;

    bool contains(
        const std::deque<std::string>& cache,
        const std::string& block
    ) const;

    void insertIntoL1(const std::string& block);
    void insertIntoL2(const std::string& block);
    void insertIntoL3(const std::string& block);

public:
void printCacheState() const;
    Cache();

    int accessBlock(const std::string& block);

    int getRamAccesses() const;

    const std::deque<std::string>& getL1() const;
    const std::deque<std::string>& getL2() const;
    const std::deque<std::string>& getL3() const;
};

#endif