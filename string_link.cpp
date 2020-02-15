#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    string str;
    str = str1 + str2;
    cout<<str1 + str2;
    return 0;
}


/*int main(){
    int i = 1, j = 1; //i、j分别记录两字符串的长度
    char *str1, *str2, *str;
    char a;
    while(true){
        cin.get(a);
        if(a == ' ')
            break;
        else{
            str = new char [i];
            str = str1;
            *(str + i - 1) = a;
            str1 = new char [i];
            str1 = str;
            i++;
        }
    }
    str = new char [i];
    str = str1;
    str1 = new char [i];
    str1 = str;
    *(str1 + i - 1) = '\0'; //结束字符串1
    while(true){
        cin.get(a);
        if(a == '\n')
            break;
        else{
            str = new char[j];
            str = str2;
            *(str + j - 1) = a;
            str2 = new char[j];
            str2 = str;
            j++;
        }
    }
    str = new char [j];
    str = str2;
    str2 = new char [j];
    str2 = str;
    *(str2 + j - 1) = '\0'; //结束字符串2
    str = new char [i + j - 1];
    str = str1;
    str1 = new char [i + j -1]; //分配存储空间，合并字符串
    str1 = str;
    for(int k = 0; k <= j; k++, i++){
        *(str1 + i - 1) = *(str2 + k);
    }
    cout<<str1;
    delete str1;
    delete str2;
    delete str;
    return 0;
}*/