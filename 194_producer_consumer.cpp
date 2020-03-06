//
// Created by Zeno on 2020/3/8.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue> // C++ STL所有的容器都不是线程安全

using namespace std;

// 生产者生产一个物品，通知消费者消费一个；消费完了，消费者再通知消费者进行生产

std::mutex mtx; // 定义互斥锁，做线程间的互斥操作
std::condition_variable cv; // 定义条件变量，做线程间的同步通信操作

class Queue
{
public:
    void put(int val) // 生产物品
    {
        //lock_guard<std::mutex> guard(mtx);
        unique_lock<std::mutex> lck(mtx);
        while (!que.empty())
        {
            // que不为空，生产者应该通知消费者去消费，消费完了，再继续生产
            // 生产者线程进入等待状态，并且把mtx互斥锁释放掉
            cv.wait(lck);
        }
        que.push(val);

        cv.notify_all(); // 通知其它所有的线程，我生产了一个物品，你们赶紧消费吧
        // 其它线程得到该通知，就会从等待状态进入阻塞状态，但是还需要获取互斥锁才能继续进行
        cout << "生产者 生产：" << val << "号物品" << endl;
    }

    int get() //消费物品
    {
        //lock_guard<std::mutex> guard(mtx);
        unique_lock<std::mutex> lck(mtx);
        while(que.empty())
        {
            // 消费者线程发现que是空的，通知生产者线程先生产物品
            // 进入等待状态，把互斥锁mutex释放
            cv.wait(lck);
        }
        int val = que.front();
        que.pop();
        cv.notify_all(); // 通知其它线程，我消费完了，赶紧生产吧
        cout << "消费者 消费：" << val << "号物品" << endl;
        return val;
    }

private:
    queue<int> que;
};

void producer(Queue* que) // 生产者线程
{
    for(int i = 1; i <= 10; ++i)
    {
        que->put(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(Queue* que) // 消费者线程
{
    for(int i = 1; i <= 10; ++i)
    {
        que->get();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    Queue que; //两个线程共享的队列

    std::thread t1(producer, &que);
    std::thread t2(consumer, &que);

    t1.join();
    t2.join();

    return 0;
}
