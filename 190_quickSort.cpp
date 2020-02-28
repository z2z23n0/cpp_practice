//
// Created by Zeno on 2020/2/27.
//
#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

//三数取中法: 保证每次的划分均衡
int getMid(vector<int>& a, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (a[mid] > a[left])
    {
        if (a[mid] < a[right])
            return mid;
        else
        {
            // mid > left, right
            if (a[left] > a[right])
                return left;
            else
                return right;
        }
    }
    else
    {
        // mid <= left
        if (a[left] < a[right])
            return left;
        else
        {
            //left >= right, mid
            if (a[mid] > a[right])
                return mid;
            else
                return right;
        }
    }
}

//快排的一次排序：确定基准值的位置
int PartSort(vector<int>& a, int left, int right)
{
    //三数取中
    int mid = getMid(a, left, right);
    swap(a[mid], a[left]);

    int key = a[left];
    int start = left;
    //寻找大小元素交换
    while (left < right)
    {
        // 先从右边找小于key的值
        while (left < right && a[right] >= key)
            --right;
        //从左边找大于key的值
        while (left < right && a[left] <= key)
            ++left;

        swap(a[left], a[right]);
    }

    //key的位置确定: left right相遇的位置
    swap(a[start], a[left]);
    return left;
}

int PartSort3(vector<int>& data, int left, int right);

void quickSortNoR(vector<int>& data, int left, int right)
{
    stack<int> st;
    if (left < right)
    {
        st.push(right);
        st.push(left);
    }
    while (!st.empty())
    {
        int begin = st.top();
        st.pop();
        int end = st.top();
        st.pop();
        //划分当前区间
        int mid = PartSort(data, begin, end);
        //划分左右子区间
        if (begin < mid - 1)
        {
            //StackPush(&st, mid - 1);
            //StackPush(&st, begin);
            st.push(mid - 1);
            st.push(begin);
        }
        if (mid + 1 < end)
        {
            //StackPush(&st, end);
            //StackPush(&st, mid + 1);
            st.push(end);
            st.push(mid + 1);
        }
    }

}

//前后指针
int PartSort3(vector<int>& data, int left, int right)
{
    int mid = getMid(data, left, right);
    swap(data[mid], data[left]);

    //最后一个小于key的位置
    int prev = left;
    //下一个小于key的位置
    int cur = left + 1;
    int key = data[left];
    while (cur <= right)
    {
        // 如果下一个小于key的位置于上一个小于key的位置不连续
        // 说明中间有大于key的值，进行交换，大-->向后移动， 小 <---向前移动
        if (data[cur] < key && ++prev != cur)
        {
            swap(data[prev], data[cur]);
        }
        ++cur;
    }
    swap(data[prev], data[left]);
    return prev;
}

int main()
{
    srand(time(NULL));
    vector<int> data;
    for(int i = 0; i < 100; ++i)
    {
        data.push_back(rand() % 100);
    }
    quickSortNoR(data, 0, data.size() - 1);
    for(auto num : data)
    {
        cout << num << ' ';
    }
    return 0;
}