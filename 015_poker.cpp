//
// Created by Zeno on 2019/10/30.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

enum {
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS,
    JOKER
};

//华为代码规范：
//全局变量 g_
//局部静态变量 s_
//成员变量 m_
class Poker{
    char m_type;
    int m_point;
public:
    void makePoker(char type,int point){
        m_type = type;
        if(m_type == JOKER){
            m_point += 13;
        }
        m_point = point;
    }
    void outputPoker(){
        char* type[5] = {"黑桃","红桃","梅花","方块",""};
        char* point[16] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K","大王","小王"};
        printf("%s%s",type[m_type],point[m_point]);
    }

    bool cmppoker(Poker tmp){
        return (m_point < tmp.m_point) ||
               (m_point == tmp.m_point && m_type> tmp.m_type);
    }
    bool isEff(){
        if(m_type == JOKER && m_point == 14 || m_point == 15){
            return true;
        }
        if((unsigned char)m_type > 3 ||
                (unsigned int)m_point - 1 > 13) {
            return false;
        }
        return true;
    }
};
class Player{
    Poker m_HandCard[18];
    int m_size;
public:
    Player(){//构造函数
        m_size = 0;
    }
    void getCard(Poker newCard){
        int i;
        for(i = m_size;i > 0 && m_HandCard[i-1].cmppoker(newCard);--i){
            m_HandCard[i] = m_HandCard[i - 1];
        }
        m_HandCard[i] = newCard;
        m_size++;
    }

    void showCard(){
        for(auto& i : m_HandCard){
            i.outputPoker();
            putchar(' ');
        }
        putchar('\n');
    }
};
void PokerTest(){
    srand((unsigned)time(NULL));
    Player p1;
    Poker tmp;
    int i;
    for(i = 0;i < 18;++i){
        tmp.makePoker(rand() % 4,rand() % 13 + 1);
        p1.getCard(tmp);
    }
    p1.showCard();
}
int randnum(Poker* cardHeap){
    int tmp = rand() % 54;
    while (true){
        if(cardHeap[rand() % 54].isEff()){
            return tmp;
        } else{
            ++tmp;
            if(tmp == 54){
                tmp = 0;
            }
        }
    }
}
int main(){
    Poker tmp[54];
    int j = 0;
    Player ayi;
    Player laoye;
    Player miao17;
    for(auto& i : tmp){
       i.makePoker(j / 13,j % 13 + 1);
       ++j;
    }
    srand((unsigned)time(NULL));

    int delcard;
    int i;
    for(i = 0;i < 18;++i){
        delcard = randnum(tmp);
        ayi.getCard(tmp[delcard]);
        tmp[delcard].makePoker(-1,-1);

        delcard = randnum(tmp);
        laoye.getCard(tmp[delcard]);
        tmp[delcard].makePoker(-1,-1);

        delcard = randnum(tmp);
        miao17.getCard(tmp[delcard]);
        tmp[delcard].makePoker(-1,-1);
    }
    ayi.showCard();
    laoye.showCard();
    miao17.showCard();
    return 0;
}
