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