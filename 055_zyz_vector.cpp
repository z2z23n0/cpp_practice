//
// Created by Zeno on 2019/11/13.
//
#include <iostream>

namespace zyz{
    template <class T>
    class vector{
        T* m_start;
        T* m_finish;
        T* m_endOfStorage;
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        vector():
            m_start(nullptr),
            m_finish(nullptr),
            m_endOfStorage(nullptr)
        {

        }
        vector(int n,const T& val = T()) :
            m_start(nullptr),
            m_finish(nullptr),
            m_endOfStorage(nullptr)
        {
            reserve(n);
            for(int i = 0;i < n;i++){
                m_start[i] = val;
            }
        }
        size_t size(){
            return m_finish - m_start;
        }
        size_t capacity(){
            return m_endOfStorage - m_start;
        }
        void reserve(size_t _size){
            int _capacity = capacity();
            if(_capacity < _size){
                while (_capacity < _size){
                    _capacity = (_capacity==0)?1:2*_capacity;
                }
            }
            T* tmp = new T[_capacity];
            m_endOfStorage = tmp+_capacity;
            int oldsize = size();
            m_finish = tmp + oldsize;
            if(m_start!= nullptr){
                for(int i = 0;i < oldsize;i++){
                    tmp[i] = m_start[i];
                }
                delete[] m_start;
            }
            m_start = tmp;
        }
    };
}
