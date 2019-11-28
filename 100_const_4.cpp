//
// Created by Zeno on 2019/11/27.
//

#include <iostream>
using namespace std;

int main(){
    //int a = 10;
    //const int *p = &a; //const int* 《= int* 正确
    //int* q = p; //int* 《= const int* 错误
    //int a = 10;
    //int* const p = &a; //int* 《= int* 正确
    //int* q = p; //int* 《= int* 正确
    //int a = 10;
    //int* const p = &a; //int* 《= int* 正确
    //int* const q = p; //int* 《= int* 正确
    //int a = 10;
    //int* const p = &a;//int* 《= int* 正确
    //const int* q = p;//const int* 《= int* 正确
    //int a = 10;
    //int* p = &a;
    //const int **q = &p; // const int** 《= int** 错误
    //int a = 10;
    //int* p = &a;
    //int* const *q = &p;  //int* const * 《= int** 正确
    //int a = 10;
    //int* p = &a;
    //int** const q = &p; //int** 《= int* const * 错误
    //int a = 10;
    //const int* p = &a;
    //int* const* q = &p; //int* const* 《= const int** 错误
    int a = 10;
    const int& b = 20;
    int&& c = 30;
    printf("%d,%d",b,c);

    c = 35;
    printf("%d,%d",b,c);

    return 0;
}
