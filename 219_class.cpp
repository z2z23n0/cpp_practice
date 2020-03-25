//
// Created by Zeno on 2020/3/23.
//

#include <iostream>
using namespace std;

class thread
{
public:
    thread()
    {
        cout << "thread()" << endl;
    }
};

int main()
{
    thread produce();
    thread a;
    thread *p = new thread();
    thread* p = new thread;
    return 0;
}