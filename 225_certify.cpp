//
// Created by Zeno on 2020/3/29.
//


#include <stdio.h>
#include <stdlib.h>


int sum(int* array, int length)
{
    int result = 0;
    if(array > &result)
    {
        printf("array is located in ______\n");
    }
    return result;
}

int B[] = {1,2,3};
int main()
{
    int *A = (int*)malloc(0xffffffff);
    int C[] = {1,2,3};
    sum(A,3);
    sum(B,3);
    sum(C,3);
    return 0;
}