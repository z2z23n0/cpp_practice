//
// Created by Zeno on 2020/1/23.
//

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool ret = false;
        if(pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
        {
            return ret;
        }

        stack<int> s;
        vector<int>::iterator pNextPush = pushV.begin();
        vector<int>::iterator pNextPop = popV.begin();

        while(pNextPop < popV.end())
        {
            while(s.empty() || s.top() != *pNextPop)
            {
                if(pNextPush == pushV.end())
                {
                    break;
                }

                s.push(*pNextPush);
                pNextPush++;
            }

            if(s.top() != *pNextPop)
            {
                break;
            }

            s.pop();
            pNextPop++;
        }
        if(s.empty() && pNextPush == pushV.end() && pNextPop == popV.end())
        {
            ret = true;
        }
        return ret;
    }
};