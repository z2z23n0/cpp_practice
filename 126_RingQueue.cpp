//
// Created by Zeno on 2020/1/8.
//

#include <iostream>
#include <vector>
#include <semaphore.h>

using namespace std;

class RingQueue
{
    vector<int> m_array;//数组
    int m_capacity;//数组的节点数量
    int m_pos_write;//写指针当前位置，写入数据后，写指针向后移动
    int m_pos_read;//读指针当前位置，读取数据后，读指针向后移动
    sem_t m_sem_pro;//空闲空间计数器，有多少个空闲空间，就可以生产多少个数据
    sem_t m_sem_con;//数据资源计数器，有多少个数据资源，就可以获取多少个数据——用于实现同步
    sem_t m_sem_lock;//实现安全的锁——用于实现互斥
};
