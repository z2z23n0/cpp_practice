//
// Created by Zeno on 2019/11/21.
//

#include <iostream>
#include <map>
using namespace std;

map<int,int> m;
void contribute_map(size_t year){
    if((year%4==0&&year%100!=0)||year%400==0){
        m[2] = 29;
    }else{
        m[2] = 28;
    }
    m[1] = 31;
    m[3] = 31;
    m[5] = 31;
    m[7] = 31;
    m[8] = 31;
    m[10] = 31;
    m[12] = 31;
    m[4] = 30;
    m[6] = 30;
    m[9] = 30;
    m[11] = 30;
}
size_t count_date(size_t year,size_t month,size_t day){
    size_t count = 0;
    contribute_map(year);
    if(month == 1)
        return day;
    for(int i = 1;i <= month - 1;i++){
        count += m[i];
    }
    return count+day;
}
int main(){
    size_t year,month,day;
    while(cin>>year>>month>>day){
        cout<<count_date(year,month,day)<<endl;
    }
    return 0;
}
