//
// Created by Zeno on 2020/1/12.
//

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<"Base~";
        fun1();
    }

    virtual void fun1()
    {
        cout<<"Base::func1"<<endl;
    }
};

class Derive:public Base
{
public:
    Derive()
    {
        cout<<"Derive~";
        fun1();
    }

    virtual void fun1()
    {
        cout<<"Derive::fun1"<<endl;
    }
};


int main()
{
   // Base bs;
   // bs.fun1();

   // Derive de;
   // de.fun1();

   // Base bs2;
   // bs2.fun1();

    //Derive* de2 = new Derive;
    //Base* bs3 = new Base;
    //Base* bs3;
    //bs3 = new Derive;
    //bs3 = (Base*)de2;
    //bs3->fun1();

   // Derive de3;
   // Base bs4;
   // bs4 = (Base)de3;
   // bs4.fun1();

    return 0;
}

//121414