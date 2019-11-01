//
// Created by Zeno on 2019/11/6.
//

#include <iostream>
#include <typeinfo>
using   namespace std;

template <class T>
void swapArgs(T& a,T& b){
   T temp;

    cout<<typeid(temp).name()<<endl;
   temp = a;
   a = b;
   b = temp;
}

template <typename T>
T add(T a,T b){
    return a+b;
}
int main(){
    //int ia = 5,ib = 7;
    //double da = 3.14,db = 1.618;
    //float sa = 3.11,sb = 2.22;
    //swapArgs(ia,ib);
    //cout<<ia<<' '<<ib<<endl;
    //swapArgs(da,db);
    //cout<<da<<' '<<db<<endl;
    //swapArgs(sa,sb);
    //cout<<sa<<' '<<sb<<endl;
    cout << add<int>(2.0,5.1)<<endl;
    return 0;
}
