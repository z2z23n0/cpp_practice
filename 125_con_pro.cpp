//description:使用信号量实现生产者与消费者模型

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

#define MAX_QUEUE 5
class RingQueue
{ 
  public:
    RingQueue(int maxq = MAX_QUEUE):
      _capacity(maxq),
      _array(maxq),
      _pos_read(0),
      _pos_write(0)
    {
      sem_init(&_sem_data, 0, 0);//数据资源计数器
      sem_init(&_sem_space, 0 , maxq);//空闲空间计数器
      sem_init(&_sem_lock, 0 , 1);//锁的初始化
    }

    ~RingQueue()
    { 
      sem_destory(&_sem_data);
      sem_destory(&_sem_space);
      sem_destory(&_sem_lock);
    }

    bool Push(int& data)
    { 
      sem_wait(&_sem_space);//没有空闲空间则直接阻塞，并且空闲空间计数-1

      sem_wait(&_sem_lock);//加锁，保护入队操作
      _array[_pos_write] = data;
      _pos_write = (_pos_write + 1) % _capacity;
      sem_post(&_sem_lock);//解锁

      sem_post(&_sem_data);//数据资源计数+1，唤醒消费者
      return true;
    }

    bool Pop(int* data)
    { 
      sem_wait(&_sem_data);//通过资源计数判断是否能获取资源

      sem_wait(&_sem_lock);
      *data = _array[_pos_read];
      sem_post(&_sem_lock);
      
      sem_post(&_sem_space);
      return true;
    }

  private:
    vector<int> _array;
    int _capacity;
    int _pos_write;
    int _pos_read;
    sem_t _sem_space;
    sem_t _sem_data;
    sem_t _sem_lock;
}

int main(){ 

  return 0;
}
