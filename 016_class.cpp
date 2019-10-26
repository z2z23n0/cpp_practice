//
// Created by Zeno on 2019/10/30.
//

#include <iostream>
using namespace std;
class Test2{
public:
    int b;
    Test2(int i){
        b = i;
    }
};
class Test{
public:
    const int i;
    int& ri;
    Test2 t2;
    Test(int& a) : i(3),ri(a),t2(3)
    {
    }
};
int main(){
    int i = 8;
    int j = 9;
    Test2 a(i);
    Test2 b = a;
    Test2 c(j);
    c = b;
    cout<<c.b<<endl;
    return 0;
}
