//
// Created by Zeno on 2020/1/10.
//

//测试用例：
//1. 长度为n的数组里包含一个或多个重复的数字
//2. 数组中不包含重复的数字
//3. 输入空指针或数组无元素
//4. 不符合长度为n+1的数组中数字都在1~n

int countRange(const int* numbers, int length, int start, int end)//统计数组中共有几个元素的数值在start~end范围内
{
    if (numbers == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= start && numbers[i] <= end) {
            ++count;
        }
        return count;
    }
}

int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)//处理测试用例3的情况
    {
        return -1;
    }

    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int middle = ((end - start) / 2) + start;
        int count = countRange(numbers, length, start, middle);
        if(end == start)
        {
            if(count > 1)
            {
                return start;
            }
            else
            {
                break;
            }
        }
        if(count > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}


