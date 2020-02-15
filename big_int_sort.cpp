/*==============================
  对N个长度最长可达到1000的数进行排序
==============================*/



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.length() != b.length())
        return a.length() < b.length(); //a、b不等长时，短的更小
    else
        return a < b;
} //比较函数

int main(){
    int N;
    string str[100];
    while(cin>>N){
        for(int i = 0; i < N; i++){
            cin>>str[i];
        }
        sort(str, str + N, cmp); //排序
        for(int i = 0; i < N; i++){
            cout<<str[i]<<endl;
        }
    }
    return 0;
}