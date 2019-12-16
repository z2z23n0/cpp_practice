//
// Created by Zeno on 2019/12/16.
//

#include <iostream>
#include <cstring>
using namespace std;

//思路：创建一个新的字符串保存结果  (因为不能做到在原字符串上进行修改所以放弃)
//思路：遍历字符串，遇到空格时
//时间复杂度O(n),空间复杂度O(n)
//测试用例：空字符串、连续空格、全是空格
void replaceSpace(char* str,int length){
    char tmp[1024];
    for(int i = 0,j = 0; i <= length; i++,j++){
        //遍历str
        if(str[i] != ' '){
            //如果不为空格，接在tmp末尾
            //strcat(tmp,str[i]);
            tmp[j] = str[i];
        }else{
            //如果是空格，末尾添加"%20"
            //strcat(tmp,"%20");
            tmp[j] = '%';
            tmp[++j] = '2';
            tmp[++j] = '0';
        }
    }
    for(int i = 0;i < length; i++){
        str[i] = tmp[i];
    }
}
int main(){
    char* str = "We Are Happy!";
    replaceSpace(str,strlen(str));
    printf("%s",str);
    return 0;
}
