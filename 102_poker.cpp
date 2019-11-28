//
// Created by Zeno on 2019/11/28.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        //王炸最大，直接输出
        if(line.find("joker JOKER") != -1)
            cout<<"joker JOKER"<<endl;
        else{
            int dash = line.find('-');
            //分开两手牌
            string card1 = line.substr(0,dash);
            string card2 = line.substr(dash+1);
            //获取空格的次数，牌数为c+1
            int c1 = count(card1.begin(),card1.end(),' ');
            int c2 = count(card2.begin(),card2.end(),' ');
            //拿到第一张牌
            string first1 = card1.substr(0,card1.find(' '));
            string first2 = card2.substr(0,card2.find(' '));
            string str = "345678910JQKA2jokerJOKER";
            if(c1 == c2){
                //只要牌数相等，则第一张牌大的即为大
                if(str.find(first1) > str.find(first2))
                    cout<< card1 << endl;
                else
                    cout<<card2<<endl;
            }
            else{
                //牌数不相同，说明类型不同，只有炸弹可以和其它牌比较，别的类型都是错误的
                if(c1 == 3)
                    cout<< card1 <<endl;
                else if(c2 == 3)
                    cout << card2 << endl;
                else
                    cout<< "ERROR" << endl;
            }
        }
    }
    return 0;
}
