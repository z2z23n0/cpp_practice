//
// Created by Zeno on 2019/12/7.
//
#include <iostream>
#include <vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array){
    if (array.empty()){
        return -1;
    }
    // F(i)初始化
    int sum = array[0];
    // maxsum初始化
    int maxsum = array[0];
    for (int i = 1; i < array.size(); i++){
        // F(i) = max(F(i-1) + array[i]，array[i])
        sum = (sum > 0) ? sum + array[i] : array[i];
        // maxsum = max( maxsum，F(i))
        maxsum = (sum < maxsum) ? maxsum : sum;
    }
    return maxsum;
}
int main(){
    int n;
    while(cin>>n) {
        vector<int> vt;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            vt.push_back(num);
        }
        cout << FindGreatestSumOfSubArray(vt) << endl;
    }
}

