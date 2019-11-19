//
// Created by Zeno on 2019/11/19.
//

#include <iostream>
using namespace std;

class TestBase{
public:
    virtual void func(){
        cout<<"I'm Base!"<<endl;
    }
};
class Test : public  TestBase{
    void func(){
        cout<<"I'm test!"<<endl;
    }
};
int main(){

    return 0;
}
