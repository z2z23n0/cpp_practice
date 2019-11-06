//
// Created by Zeno on 2019/11/7.
//

#include <stdio.h>
#include <stdlib.h>
void ShellSort(int* a,int n){
    int gap = n;
    int i;
    while(gap > 1) {
        gap = gap / 3 + 1;
        for (i = 0; i < n - gap; i++) {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0 && a[end] > tmp) {
                a[end + gap] = a[end];
                end -= gap;
            }
            a[end + gap] = tmp;
        }
    }
}
int arr_sum(int* a,int n){
    int sum = 0;
    for(int i = n;i<n*2;++i){
        //printf("%d",a[i]);
        sum+=a[i];
    }
    return sum;
}
void PrintArray(int* a,int n){
    int i;
    for(i = 0;i < n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int n;
    int* arr;
    int ret;
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*3*n);
    for(int i = 0;i<3*n;++i){
        scanf("%d",&arr[i]);
    }
    ShellSort(arr,3*n);
    //PrintArray(arr,3*n);
    //printf("%d %d",arr[n],arr[n*2]);
    ret = arr_sum(arr,n);
    printf("%d",ret);
    return 0;
}
