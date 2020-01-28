//
// Created by Zeno on 2020/1/28.
//

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int> leastSet;
        vector<int> leastVector;

        if(k < 1 || input.size() < k)
        {
            return leastVector;
        }

        vector<int>::iterator it_vector = input.begin();
        for(; it_vector != input.end(); ++it_vector)
        {
            if(leastSet.size() < k)
            {
                leastSet.insert(*it_vector);
            }
            else
            {
                multiset<int>::iterator greatest = leastSet.end();
                greatest--;
                if(*greatest < *it_vector)
                {
                    continue;
                }
                else
                {
                    leastSet.erase(greatest);
                    leastSet.insert(*it_vector);
                }
            }
        }

        for(auto it_set : leastSet)
        {
            leastVector.push_back(it_set);
        }
        return leastVector;
    }
};