//
// Created by Zeno on 2019/11/11.
//

#include <iostream>
using namespace std;

int main(){
    int m;  //要被转换的十进制数字
    int n;  //要转换成的进制
    int arr[32]; //用于存储转换后的每一位
    int count = 0; //用于计数一共转换多少位
    cin>>m;
    cin>>n;
    while(m){
        int tmp = m%n;
        m/=n;
        arr[count] = tmp;
        count++;
    }
    for(int k = count - 1;k>=0;k--){
        if(arr[k]>=10)
            cout<<arr[k]+55;
        else
            cout<<arr[k];
    }
    return 0;
}
