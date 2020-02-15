#include<iostream>
#include<string>
using namespace std;

int main(){
    //string str1, str2;
    char str1[10], str2[10];
    cin >> str1 >> str2;
    cout << str1 << str2 << endl;
    cout << *str1 <<  *str2 << endl;
    return 0;
}