//
// Created by Zeno on 2019/12/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //从右上角找起，数比target大则向左，数比target小则向下
    //测试用例：array == empty
    //找得到、找不到
    bool Find(int target, vector<vector<int>> array){
        if(array.empty()){
            //数组为空直接返回false
            return false;
        }
        for(int i = 0;i < array.size();++i){
            //竖向遍历每一列
            for(int j = array[i].size() - 1; j >= 0; j--){
                //横向遍历每一行
                if(array[i][j] == target){
                    //找到就返回true
                    return true;
                }else if(array[i][j] > target){
                    //数比target大，继续向左横向遍历
                    continue;
                }else if(array[i][j] < target){
                    //数比target小，向下遍历
                    break;
                }
            }
        }
        return false;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> vt = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{6,7,8,9,10}};
    cout << sol.Find(100,vt)<<endl;
    return 0;
}
