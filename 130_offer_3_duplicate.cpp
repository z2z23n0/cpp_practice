//
// Created by Zeno on 2020/1/9.
//

//测试用例：
// 1. 包含一个或多个重复数字
// 2. 不包含重复数字
// 3. 空指针
// 4. 长度为n的数组中包含0~n-1之外的数字
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0) //解决测试用例3
    {
        return false;
    }
    for (int i = 0; i < length; ++i) //解决测试用例4
        {
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }
    for (int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            //swap numbers[i] and numbers[numbers[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
}
