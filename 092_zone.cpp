//
// Created by Zeno on 2019/11/24.
//

#include <iostream>
using namespace std;
int g_data1 = 10;
int g_data2 = 0;
int g_data3;

static int g_data4 = 11;
static int g_data5 = 0;
static int g_data6;

int main(){
    int a = 12;
    int b = 0;
    int c;

    static int e = 13;
    static int f = 0;
    static int g;
    cout<<c<<' '<<g;
    return 0;
}
