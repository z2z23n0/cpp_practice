//
// Created by Zeno on 2019/10/28.
//

#include <iostream>
using namespace std;
class A{
public:
    void PrintA(){
        cout<<this->_a<<endl;
    }
    void Show(){
        cout<<"Show()"<<endl;
    }

private:
    int _a;
};
//当this为NULL时不能解引用
int main(){
    A* p = NULL;
    //p->PrintA();
    p->Show();
    return 0;
}
