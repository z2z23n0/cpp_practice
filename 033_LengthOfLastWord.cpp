//
// Created by Zeno on 2019/11/8.
//

#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string s){
    int last_space_index = s.rfind(' ');
    int ret = s.size() - last_space_index - 1;
    return ret;
}

int main(){

    return 0;
}
