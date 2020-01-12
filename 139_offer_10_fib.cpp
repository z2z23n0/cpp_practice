//
// Created by Zeno on 2020/1/12.
//

#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1 || n == 2)
    {
        return 1;
    }

    int fn = 0, fn1 = 1, fn2 = 1;
    for(int i = 2; i < n; i++)
    {
        fn = fn1 + fn2;
        fn1 = fn2;
        fn2 = fn;
    }
    return fn;
}

int main()
{
    cout<<Fibonacci(9)<<endl;
    return 0;
}
