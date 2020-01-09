//
// Created by Zeno on 2020/1/9.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx;

//线程安全的懒汉式单例模式
class Singleton
{
public:
    static Singleton* getInstance()// 3. 获取类的唯一实例对象的接口方法
    {
        if(instance == nullptr)
        {
            lock_guard<std::mutex> guard(mtx);//锁 + 双重判断
            if(instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
private:
    static Singleton* instance;// 2. 定义一个唯一的类的实例对象
    Singleton() // 1. 构造函数私有化
    {

    }
    Singleton(const Singleton&) = delete;
    Singleton&operator =(const Singleton&) = delete;
};
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton* p3 = Singleton::getInstance();

    return 0;
}
