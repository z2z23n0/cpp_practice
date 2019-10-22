//
// Created by Zeno on 2019/10/28.
//

#include <iostream>
using namespace std;
class Date{
public:
    void Display(){
        cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    void SetDate(int year,int month,int day){
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};
