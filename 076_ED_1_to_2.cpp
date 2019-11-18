//
// Created by Zeno on 2019/11/18.
//

#include <iostream>
#include <math.h>
using namespace std;


int main(){
    int num;
    cin>>num;
    int res = -1;
    int pri_1,pri_2;
    for(int i = 1;i <= num/2;i++){
        int flag_1 = 0;
        int flag_2 = 0;
        for(int j = 2;j <= sqrt(i);j++){
            if(i%j == 0) {
                flag_1 = 1;
                break;
            }
        }
        if(flag_1 == 1)
            continue;
        for (int j = 2;j <= sqrt(num-i);j++){
            if((num-i)%j == 0) {
                flag_2 = 1;
                break;
            }
        }
        if(flag_2 == 1)
            continue;
        if((res==-1)||(res>(num-i-i))) {
            res = num - i - i;
            pri_1 = i;
            pri_2 = num - i;
        }
    }
    cout<<pri_1<<endl;
    cout<<pri_2<<endl;
    return 0;
}
