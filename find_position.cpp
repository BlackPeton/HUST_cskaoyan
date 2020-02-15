/*================================================================
  对给定的一个字符串，找出有重复的字符，并给出其位置
  例如：
  输入“abcaaAB12ab12”
  输出“a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13”
================================================================*/



#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        int len = str.length();
        for(int i = 0; i < len - 1; i++){ //外循环，对当前字符(str[i])之后的字符进行逐个比较
            bool flag = false; //标记当前字符之后是否有相同字符
            if(str[i] == '*')
                continue; //当前字符为*，表示之前已经访问过并输出
            for(int j = i + 1; j < len; j++){ //内循环，遍历当前字符之后的每一个字符(str[j])
                if(str[j] == str[i]){
                    if(!flag){ //两字符相同，flag为false，则先输出比较对象str[i]
                        cout<<str[i]<<':'<<i;
                        flag = true;
                    }
                    cout<<','<<str[j]<<':'<<j;
                    str[j] = '*'; //标记该字符已经比较成功并输出过
                }
            }
            if(flag)
                cout<<endl;
        }
    }
    return 0;
}

/*此处对两层循环中的循环判断条件作出说明：
    len为字符串长度，字符串下标范围为0～len-1

    外循环条件为i < len - 1，仅需进行到len - 2位置处，因为len - 1为最后一个字符，无继续向后判断的必要

    内循环条件为j < len，进行到len - 1位置即最后一个字符处；若此处采用相同的j < len - 1，则若最后一个字符与前面某个字符
    相同，不会被比较
*/