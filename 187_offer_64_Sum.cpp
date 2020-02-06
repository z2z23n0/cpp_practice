//
// Created by Zeno on 2020/2/23.
//

class Solution {
public:
    Solution()
    {
        ++m_n;
        m_sum += m_n;
    }
    static void Reset()
    {
        m_n = 0;
        m_sum = 0;
    }
    static unsigned int GetSum()
    {
        return m_sum;
    }
    int Sum_Solution(int n) {
        Reset();

        Solution* temp = new Solution[n];
        delete[] temp;
        temp = nullptr;

        return GetSum();
    }
private:
    static unsigned int m_n;
    static unsigned int m_sum;
};
unsigned int Solution::m_n = 0;
unsigned int Solution::m_sum = 0;