//
// Created by Zeno on 2019/11/6.
//

#include <cstddef>

#ifndef CPP_PROJECT_024_SEQLIST_H
#define CPP_PROJECT_024_SEQLIST_H

#endif //CPP_PROJECT_024_SEQLIST_H

#pragma once


template <class T>
class SeqList{
    T* m_data;
    size_t m_size;
    size_t m_capacity;

    void checkCapacity();
public:
    SeqList(size_t capacity = 10):
        m_data(new T[capacity]),
        m_size(0),
        m_capacity(capacity)
    {

    }
    void push_back(const T& src);
    void pop_back();
    int size();
    ~SeqList();
};
