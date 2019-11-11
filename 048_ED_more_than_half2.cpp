//
// Created by Zeno on 2019/11/12.
//

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int ret = numbers[0];
        int times = 1;
        for(int i = 1;i < numbers.size();++i){
            if(times == 0){
                ret = numbers[i];
                times = 1;
            }else if(numbers[i] == ret){
                times++;
            }else{
                times--;
            }
        }
        int count = 0;
        for(int i = 0;i<numbers.size();++i){
            if(numbers[i] == ret)
                count++;
        }
        return (count > numbers.size()/2)?ret:0;
    }
};