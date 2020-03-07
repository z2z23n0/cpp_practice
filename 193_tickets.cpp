//
// Created by Zeno on 2020/3/7.
//

// 模拟车站三个窗口卖票的程序

#include <iostream>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

int count = 100; // 车站有一百张票，由三个窗口一起卖票
std::mutex mtx; // 全局的一把互斥锁

// 模拟卖票的线程函数
void sellTicket(int index)
{
    while(count > 0)
    {
        //mtx.lock();
        {
            lock_guard<std::mutex> lock(mtx);
            //unique_lock<std::mutex> lock(mtx);
            if (count > 0) {
                // 临界区代码段 应保持原子操作，线程间护持操作
                cout << "窗口" << index << "卖出第" << count << "张票" << endl;
                //cout << count << endl;
                count--;
            }
        }
        //mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main()
{
    list<std::thread> tlist;
    for(int i = 1; i <=3; ++i)
    {
        tlist.push_back(std::thread(sellTicket, i));
    }

    for(std::thread &t : tlist)
    {
        t.join();
    }

    cout << "所有窗口卖票结束" << endl;

    return 0;
}
