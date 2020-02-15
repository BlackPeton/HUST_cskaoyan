/*======================================
  给定两个整数A和B，其表示形式是：从个位开始，每
  三位数用逗号","隔开。 现在请计算A+B的结果，并
  以正常形式输出。
=======================================*/



#include<iostream>
using namespace std;

int convert(char num[]){
    int sum = 0;
    int i = 0;
    bool flag = true; //默认为正数
    if(num[0] == '-'){
        i++;
        flag = false;
    } //第一位为'-'，为负数
    while(num[i]){
        if(num[i] == ','){
            i++; continue;
        }
        int n = num[i] - '0';
        sum = sum * 10 + n;
        i++;
    }
    if(flag)
        return sum;
    else
        return -sum;
}

int main(){
    char A[10], B[10];
    cin >> A >> B;
    int a = convert(A);
    int b = convert(B);
    cout << a + b <<endl;
    return 0;
}