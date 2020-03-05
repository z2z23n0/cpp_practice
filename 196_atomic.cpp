//
// Created by Zeno on 2020/3/9.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <list>

using namespace std;

std::atomic_bool isReady = false;
std::atomic_int count = 0;

void task()
{
    while (!isReady)
    {
        std::this_thread::yield(); // 线程出让当前CPU时间片，等待下一次调度
    }

    for (int i = 0; i < 100; ++i)
    {
        count++;
    }

}

int main()
{
    list<std::thread> tlist;
    for (int i = 0; i < 10; ++i)
    {
        tlist.push_back(std::thread(task));
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
    isReady = true;

    for (std::thread &t : tlist)
    {
        t.join();
    }
    cout << "count = " << count << endl;

    return 0;
}
