//
// Created by Zeno on 2019/11/14.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int size;
    cin>>size;
    vector<int> num(size);
    for(auto& i : num){
        cin>>i;
    }
    int result = num[0];
    int sum1 = 0,sum2 = 0;
    for(int i =0;i<num.size();i++){
        sum2 = sum1>=0?sum1+num[i]:num[i];
        if(result < sum2)
            result = sum2;
        if(sum2<0)
            sum2 = 0;
        sum1 = sum2;
    }
    cout<<result<<endl;
    return 0;
}
