/*====================================
  输入一个字符串，然后对每个字符进行奇校验，最
  后输出校验后的二进制数(如输入“3”，输出为“10
  110011”)
  题目的意思即为输入为字符形式，对每个字符的七
  位ASCII码进行奇校验，在最高位填充校验码，最
  后输出八位二进制数
====================================*/



#include<iostream>
using namespace std;

int bin[8]; //存储二进制数
void PrintcheckedValue(char cha){
    int deci = cha - '\0'; //将字符转化为十进制数
    int i, rem;
    int flag = 0;
    for(i = 7; i >= 0; i--){
        rem = deci % 2, deci /= 2;
        bin[i] = rem;
        if(deci == 0)
            break;
    } //将字符对应的十进制数转化为二进制
    for(int j = 0; j < i; j++)
        bin[j] = 0; //剩余位填0
    for(int j = 0; j < 8; j++){
        if(bin[j] == 1)
            flag++;
    } //统计“1”的数量
    if(flag % 2) //奇数个“1”
        bin[0] = 0;
    else
        bin[0] = 1;
    for(int j = 0; j < 8; j++)
        cout << bin[j];
    cout << endl;
}

int main(){
    char ch[100];
    int i = 0;
    cin >> ch;
    while(ch[i]){
        PrintcheckedValue(ch[i]);
        i++;
    }
    return 0;
}