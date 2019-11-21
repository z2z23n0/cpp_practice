//
// Created by Zeno on 2019/11/21.
//

#include <iostream>
using namespace std;

int main(){
    try{
        float a;
        a = 5;
        throw a;
    }
    catch (int& e){
        cout<<e;
    }
    catch (float& e){
        cout<<e;
    }
    return 0;
}
