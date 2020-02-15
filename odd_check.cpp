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