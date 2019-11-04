//
// Created by Zeno on 2019/11/7.
//

#include <stdio.h>
using namespace std;
char* del_str(char* destination,const char* source){
    if(destination == NULL || source == NULL){
        return destination;
    }
    int i;
    for(int i = 0;destination[i]!='\0';++i){
        int j = 0;
        for(;source[j]!='\0';++j){
            if(destination[i]!=source[j]){
                continue;
            }
            break;
        }
        if(source[j] != '\0'){
            for(int k = i;destination[k]!='\0';++k){
                destination[k] = destination[k+1];
            }
            --i;
        }
    }
    //if(destination[i+1] == '\0'){
    //    printf("%s\n",destination);
    //}
    return destination;
}
int main(){
    char des[1024];
    char sour[1024];
    //scanf("%s\n",des);
    //scanf("%s\n",sour);
    gets(des);
    gets(sour);
    char* des_new = del_str(des,sour);
    printf("%s",des_new);
    return 0;
}
