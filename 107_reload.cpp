//
// Created by Zeno on 2019/12/4.
//
#include <iostream>
#include <cstring>

using namespace std;

bool compare(int a,int b){
    cout<<"compare_int_int"<<endl;
    return a > b;
}
bool compare(double a, double b){
    cout<<"compare_double_double"<<endl;
    return a > b;
}
bool compare(const char* a, const char* b){
    cout<<"compare_char*_char*"<<endl;
    return strcmp(a,b) > 0;
}
int main(){
    compare(10,20);
    compare(10.0,20.0);
    compare("aaa","bbb");
    return 0;
}

#ifdef __cplusplus
extern "C"{
#endif
    int sum(int a, int b){
        return a+b;
    }
#ifdef __cplusplus
}
#endif
