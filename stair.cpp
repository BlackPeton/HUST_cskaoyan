#include<iostream>
using namespace std;

int main(){
    long methods[90];
    methods[0] = 1, methods[1] = 2;
    for(int i = 2; i < 90; i++){
        methods[i] = methods[i - 2] + methods[i - 1];
    }
    int N;
    while(cin>>N){
        cout<<methods[N - 1];
    }
    return 0;
}

/*
设有N级楼梯，则到达第N级有两种方式：
 1、从第N-1级跨一步
 2、从第N-2级跨两步
则到达第N级总方式数=到达第N-1级方式数+到达第N-2级方式数
此即为一个斐波那契数列
*/