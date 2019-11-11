//
// Created by Zeno on 2019/11/12.
//

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());
        int middle = numbers[numbers.size()/2];
        int count = 0;
        for(int i = 0;i < numbers.size();++i){
            if(numbers[i] == middle)
                ++count;
        }
        return (count > numbers.size()/2)?middle:0;
    }
};