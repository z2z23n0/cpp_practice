//
// Created by Zeno on 2020/3/15.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    vector<int> v;
    srand(time(nullptr));
    for (int i = 0; i < 20; ++i)
    {
        v.push_back(rand() % 100 + 1);
    }

    return 0;
}
