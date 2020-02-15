#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    string str;
    getline(cin, str);
    int p = 0; //设置指针指示当前在字符串中的位置
    int len = 0; //记录单词长度
    while(str[p] != '\0')
    {
        if(str[p] == '.') //到达字符串末尾，输出最后一个单词长度
            cout<<len<<' ';
        if(str[p] != ' ') //当前字符不为空格，单词长度+1
            len++;
        if(str[p] == ' ') //当前字符为空格，判断一个单词结束，输出len并重置为0
            cout<<len<<' ', len = 0;
        p++;
    }
    return 0;
}
