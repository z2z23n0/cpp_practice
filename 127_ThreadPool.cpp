//
// Created by Zeno on 2020/1/9.
//
#include <iostream>
#include <queue>

using namespace std;

typedef void (*thread_callback)(void* data);

class ThreadTask
{
private:
    void* _data;//用户要处理的数据
    thread_callback _handler;
public:
    void Run()
    {
        _handler(_data);
    }
    ThreadTask(void* data, thread_callback handler);
};//线程池任务类

class ThreadPool
{
private:
    int _max_thr;//最大线程数量
    queue<ThreadTask> _queue;//任务队列
    int _max_queue;//队列的最大节点数量
    //以下成员用于实现线程安全
    pthread_mutex_t _mutex;//互斥锁
    pthread_cond_t _cond_pro;//入队操作的限制
    pthread_cond_t _cond_con;//出队操作的限制
public:
    ThreadPool()
    {
        //完成初始化操作
    }
    ~ThreadPool()
    {
        //销毁资源
    }
    bool AddTask(ThreadTask& tt);//任务入队
    bool Init();//创建大量的线程
private:
    void* thr_start(void* arg);//线程入口函数:不断获取任务，调用任务成员函数Run就可以了
};
