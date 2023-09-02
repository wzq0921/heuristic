#pragma once
#include <vector>

class Solution
{
    std::vector<std::vector<int>> routes;
    std::vector<int> remains;

public:
    Solution();
    bool feasible(int index);
    void Ruin();
    void Recreate();
};