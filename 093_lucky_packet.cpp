//
// Created by Zeno on 2019/11/24.
//

#include <iostream>
#include <algorithm>
using namespace std;

int getLuckyPacket(int x[],int n,int pos,int sum,int multi){
    /*
     * getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
     * x[]:袋子中的所有球
     * pos:当前搜索的位置
     * sum:到目前位置的累加和
     * multi:到目前位置的累积值
     */
    int count = 0;
    //循环，搜索以位置i开始所有可能的组合
    for(int i = pos;i < n;i++){
        sum += x[i];
        multi *= x[i];
        if(sum > multi){
            //找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的组合
            count+=1+getLuckyPacket(x,n,i + 1, sum, multi);
        } else if(x[i] == 1){
            //如果不符合要求且当前元素为1，则继续向后搜索
            count += getLuckyPacket(x, n, i + 1, sum, multi);
        }else{
            //如果sum大于multi，则后面就没有符合要求的组合了
            break;
        }
        //要搜索下一个位置前，先恢复sum和multi
        sum -= x[i];
        multi /= x[i];
        //数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
        while(i < n - 1 && x[i] == x[i+1]){
            i++;
        }
    }
    return count;
}
int main(){
    int n;
    while(cin>>n){
        int x[n];
        for(int i = 0;i < n;i++){
            cin>>x[i];
        }
        sort(x, x + n);
        //从第一个位置开始搜索
        cout<<getLuckyPacket(x, n, 0, 0, 1) << endl;
    }
    return 0;
}
