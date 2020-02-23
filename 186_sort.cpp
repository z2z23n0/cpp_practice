//
// Created by Zeno on 2020/2/23.
//
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void insertion_sort(vector<T>& data)
{
    int i , j;
    T tmp;
    for(i = 1; i < data.size(); i++)
    {
        tmp = data[i];
        for(j = i; j > 0 && data[j - 1] > tmp; --j)
        {
            data[j] = data[j - 1];
        }
        data[j] = tmp;
    }
}

template<typename T>
void shell_sort(vector<T>& data)
{
    for(int gap = data.size() / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < data.size(); i++)
        {
            T temp = data[i];
            int j;
            for(j = i; j >= gap && data[j - gap] > temp; j -= gap)
            {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

template<typename T>
void bubble_sort(vector<T>& data)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 0; i < data.size() - 1; ++i)
        {
            if(data[i] > data[i + 1])
            {
                swap(data[i], data[i + 1]);
                flag = true;
            }
        }
    }
}

int main()
{
    vector<int> data;
    data.push_back(6);
    data.push_back(5);
    data.push_back(3);
    data.push_back(1);
    data.push_back(8);
    data.push_back(7);
    data.push_back(2);
    data.push_back(4);

    bubble_sort(data);
    for(auto num : data)
    {
        cout << num << ' ';
    }
    return 0;
}