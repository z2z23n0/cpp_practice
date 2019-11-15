//
// Created by Zeno on 2019/11/14.
//

#include <iostream>
using namespace std;

namespace zyz{
template<class T>
class ListNode{
public:
    T m_val;
    ListNode* m_prev;
    ListNode* m_next;
    ListNode(const T& val = T()) :
        m_prev(nullptr),
        m_next(nullptr),
        m_val(val)
    {

    }
};
template <class T>
class list{
    ListNode<T>* m_head;
    void creatHead(){
        m_head = new ListNode<T>;
        m_head->m_next = m_head->m_prev = m_head;
    }
public:
    class iterator{
    public:
        ListNode<T>* m_pos;
        iterator(const ListNode<T> *val = nullptr):
            m_pos(val)
        {

        }
        T& operator*(){
            return m_pos->m_val;
        }
        T*operator->(){
            return &m_pos->m_val;
        }
        iterator operator++(){
            m_pos = m_pos->m_next;
            return this;
        }
        iterator operator++(int){
            iterator tmp = *this;
            m_pos = m_pos->m_next;
            return tmp;
        }
        iterator operator--(){
            m_pos = m_pos->m_prev;
            return this;
        }
        iterator operator--(int){
            iterator tmp = *this;
            m_pos = m_pos->m_prev;
            return tmp;
        }
        bool operator==(const iterator& ci) const{
            return m_pos == ci.m_pos;
        }
        bool operator!=(const iterator& ci) const{
            return m_pos != ci.m_pos;
        }
    };
    list(){
        creatHead();
    }
    list(int n,const T& val = T()){
        creatHead();
        int i;
        for(i = 0;i < n;i++){
            push_back(end(),val);
        }
    }
    void push_back(const T& val){
        insert(end(),val);
    }
    iterator insert(iterator pos,const T& val){
        ListNode<T> cur = new ListNode<T>;
        ListNode<T>* npos = pos.m_pos;
        cur.m_val = val;
        cur.m_prev = npos->m_prev;
        cur.m_prev->m_next = cur;
        cur.m_next = npos;
        npos->m_prev = cur;
        return cur;
    }
    iterator begin(){
        return m_head->m_next;
    }
    iterator end(){
        return m_head;
    }
};
}

int main(){
    zyz::list<int> l(4,5);
    for(auto& i : l){
        cout<<i<<' ';
    }
    return 0;
}
