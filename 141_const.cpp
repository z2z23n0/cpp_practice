//
// Created by Zeno on 2020/1/13.
//

#include <iostream>
using namespace std;

class A
{
public:
    void test(int a) const;
    int a;
    void test(int a) const
    {

    }
};

const int* fun(int a)
{

}

int main()
{
    int a;
    a = 10;
    int* c;
    const int* b = &a;
    return 0;
}
