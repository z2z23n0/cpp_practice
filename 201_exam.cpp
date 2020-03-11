//
// Created by Zeno on 2020/3/11.
//

#include<iostream>
#include<cstdio>
#include<math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isSingle(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

void printNum(int n)
{
    bool flag = false;
    for(int i = 2; i < n; i++)
    {
        if(isSingle(i))
        {
            printf("%d",i);

            if(!flag)
                flag = true;

            if(i != n - 1)
            {
                printf(" ");
            }
        }
    }
    if(!flag)
        printf("%d",-1);
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if(input.size() == 0)
        return input;

    vector<int> ret;
    sort(input.begin(), input.end());
    for(int i = 0; i < k ; i++)
    {
        ret.push_back(input[i]);
    }
    return ret;
}

#if 0
int main()
{
    int n;
    while(cin>>n)
    {
        printNum(n);
        //printf("\n");
    }
    return 0;
}
#endif

int main()
{
    vector<int> input({1,6,7,84,2,3});

    for(auto num : GetLeastNumbers_Solution(input, 3))
    {
        printf("%d ",num);
    }
    return 0;
}
