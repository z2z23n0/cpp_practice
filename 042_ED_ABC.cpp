//
// Created by Zeno on 2019/11/11.
//

#include <iostream>
using namespace std;
int main(){
    int formular1,formular2,formular3,formular4;
    int a,b,c;
    cin>>formular1;
    cin>>formular2;
    cin>>formular3;
    cin>>formular4;
    if(((formular1+formular3)%2 == 0) && ((formular1+formular3)/2>=0)){
        a = (formular1+formular3)/2;
        if(((formular2+formular4)%2 == 0) && (formular2+formular4)/2>=0){
            b = (formular2+formular4)/2;
            if(formular4 - b >= 0){
                c = formular4-b;
                cout<<a<<' '<<b<<' '<<c<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
