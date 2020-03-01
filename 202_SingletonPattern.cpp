//
// Created by Zeno on 2020/3/11.
//

/*
 * 单例模式：一个类不管创建多少次对象，永远只能得到该类型一个对象的实例*/

#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton* getInstance() // 3. 获取类的唯一实例对象的接口方法
    {
        return &instance;
    }
private:
    static Singleton instance; // 2. 定义一个唯一的类的实例对象
    Singleton() // 1. 构造函数私有化
    {

    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
Singleton Singleton::instance;


int main()
{
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton* p3 = Singleton::getInstance();



    return 0;
}
