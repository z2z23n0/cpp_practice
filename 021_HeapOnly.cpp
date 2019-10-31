//
// Created by Zeno on 2019/11/6.
//

#include <iostream>
using namespace std;

class HeapOnly{
    int m_a;

    HeapOnly() :
        m_a(0)
        {

        }

public:
    static HeapOnly* createObject();
};
HeapOnly* HeapOnly::createObject() {
    HeapOnly* ho = new HeapOnly;
    return ho;
}
int main(){

    return 0;
}
