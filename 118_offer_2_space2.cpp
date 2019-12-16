//
// Created by Zeno on 2019/12/16.
//

#include <iostream>

using namespace std;

//思路：先遍历一遍字符串，数出字符串中空格的个数和总长度
//再利用双指针倒序遍历字符串完成插入
//测试用例：空字符串、全空格、连续空格
void replaceSpace(char *str, int length) {
    if (str == NULL || length <= 0) {
        return;
    }
    int oldLength = 0, newLength = 0, countSpace = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            oldLength++;
        } else {
            oldLength++;
            countSpace++;
        }
    }
    newLength = oldLength + countSpace * 2;
    if (newLength > length) {
        //如果计算后的长度大于总长度就无法插入
        return;
    }
    int newPtr = newLength, oldPtr = oldLength;
    for (; oldPtr >= 0, newPtr>oldPtr; --newPtr, --oldPtr) {
        if (str[oldPtr] != ' ') {
            str[newPtr] = str[oldPtr];
        } else {
            str[newPtr] = '0';
            str[--newPtr] = '2';
            str[--newPtr] = '%';
        }
    }
    //while(oldPtr>=0&&newPtr>oldPtr){
    //    if(str[oldPtr] == ' '){
    //        str[newPtr--] = '0';
    //        str[newPtr--] = '2';
    //        str[newPtr--] = '%';
    //    }else{
    //        str[newPtr--] = str[oldPtr];
    //    }
    //    oldPtr--;
    //}
}

int main() {
    char *str = "We Are Happy!";
    replaceSpace(str, 20);
    printf("%s", str);
    return 0;
}
