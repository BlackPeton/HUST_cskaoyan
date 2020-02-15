/*==========================================
  守形数是这样一种整数，它的平方的低位部分等于它本身。 
  比如25的平方是625，低位部分是25，因此25是一个守形
  数。 编一个程序，判断N是否为守形数。
==========================================*/



#include<iostream>
using namespace std;

bool isNum_of_guards(int n){
    int exp = n * n;
    int mod = exp;
    while(true){
        if(mod >= 1000 && mod < 10000){
            mod = mod % 1000;
            if(mod == n)
                return 1;
        }
        else if(mod >= 100 && mod < 1000){
            mod = mod % 100;
            if(mod == n)
                return 1;
        }
        else if(mod >= 10 && mod < 100){
            mod = mod % 10;
            if(mod == n)
                return 1;
        }
        else
            return 0;
        }
}

int main(){
    int num;
    cin>>num;
    if(isNum_of_guards(num))
        cout<<"Yes!";
    else
        cout<<"No!";
    return 0;
}