//
// Created by Zeno on 2019/11/17.
//

#include <iostream>
#include <string>
using namespace std;

string getSafeLevel(string pwd){
    size_t count_num = 0;
    size_t count_Letter = 0;
    size_t count_letter = 0;
    size_t count_sign = 0;
    int score = 0;
    for(auto& i : pwd){
        if(i>='0'&&i<='9')
            count_num++;
        else if(i>='a'&&i<='z')
            count_letter++;
        else if(i>='A'&&i<='Z')
            count_Letter++;
        else if((i>=0x21 && i<=0x2F)||
                (i>=0x3A && i<=0x40)||
                (i>=0x5B && i<=0x60)||
                (i>=0x7B && i<=0x7E))
            count_sign++;
    }
    //计算密码长度得分
    if(pwd.size()<=4)
        score+=5;
    else if(pwd.size()<=7)
        score+=10;
    else if(pwd.size()>=8)
        score+=25;
    //计算密码字母得分
    if(count_Letter > 0 && count_letter == 0)
        score+=10;
    else if(count_letter > 0 && count_Letter == 0)
        score+=10;
    else if(count_Letter>0&&count_letter>0)
        score+=20;
    //计算密码数字得分
    if(count_num == 1)
        score+=10;
    else if(count_num > 1)
        score+=20;
    //计算密码符号得分
    if(count_sign == 1)
        score+=10;
    else if(count_sign>1)
        score+=25;
    //计算奖励得分
    if((count_Letter > 0)&&(count_letter>0)&&(count_num>0)&&(count_sign>0))
        score+=5;
    else if(((count_Letter+count_letter)>0)&&(count_num>0)&&(count_sign>0))
        score+=3;
    else if(((count_Letter+count_letter)>0)&&(count_num)>0)
        score+=2;
    //输出评分
    if(score>=90)
        return "VERY_SECURE";
    else if(score>=80)
        return "SECURE";
    else if(score>=70)
        return "VERY_STRONG";
    else if(score>=60)
        return "STRONG";
    else if(score>=50)
        return "AVERAGE";
    else if(score>=25)
        return "WEAK";
    else if(score>=0)
        return "VERY_WEAK";
}
int main(){
    string password;
    cin>>password;
    cout<<getSafeLevel(password)<<endl;
    return 0;
}
