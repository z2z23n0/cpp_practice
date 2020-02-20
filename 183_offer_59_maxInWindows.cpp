//
// Created by Zeno on 2020/2/21.
//

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;

        if(num.size() >= size && size >= 1)
        {
            deque<int> index;

            for(int i = 0; i < size; ++i)
            {
                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();

                index.push_back(i);
            }

            for(int i = size; i < num.size(); ++i)
            {
                ret.push_back(num[index.front()]);

                while(!index.empty() && num[i] >= num[index.back()])
                    index.pop_back();

                if(!index.empty() && index.front() <= i - size)
                    index.pop_front();

                index.push_back(i);
            }
            ret.push_back(num[index.front()]);
        }

        return ret;
    }
};