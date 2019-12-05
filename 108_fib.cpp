//
// Created by Zeno on 2019/12/5.
//

//数组：保存状态的值
//int* fi = new int[n+1];
//初始化
//fi[0] = 0;
//fi[1] = fi[2] = 1;
if(n == 0)
    return 0;
if(n == 1 || n == 2)
    return 1;
int fn = 0;
int fn1 = 1,fn2 = 0;
//fn1就是fn - 1
//fn2就是fn - 2

//转移方程：F(i) = F(i - 1) + F(i-2)
//for(int i = 3;i <= n;++i){
//    fi[i] = fi[i - 1] + fi[i - 2];
//}
for(int i = 3;i <= n;++i){
    fn = fn1+fn2;
    fn2 = fn1;
    fn1 = fn;
}
return fn;
