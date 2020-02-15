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