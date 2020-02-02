//
// Created by Zeno on 2020/2/2.
//

class Solution
{
private:
    map<char,int> mp;
    queue<int> q;
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        mp[ch]++;
        if(mp[ch] == 1)
            q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && mp[q.front()] > 1)
            q.pop();
        if(q.empty())
            return '#';
        return q.front();
    }

};