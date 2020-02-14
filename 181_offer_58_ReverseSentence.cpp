//
// Created by Zeno on 2020/2/14.
//

class Solution {
public:
    void ReverseWord(string& str, int start, int end)
    {
        while(start < end)
            swap(str[start++], str[end--]);
    }
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return str;

        ReverseWord(str, 0, str.size() - 1);

        int start = 0, end = 0, index = 0;
        while(index < str.size())
        {
            while(index < str.size() && str[index] == ' ')
                index++;

            start = end = index;
            while(index < str.size() && str[index] != ' ')
            {
                index++;
            }
            end = index - 1;
            ReverseWord(str, start, end);
        }
        return str;
    }
};