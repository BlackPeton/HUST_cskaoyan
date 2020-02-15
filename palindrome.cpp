#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        bool flag = true;
        int n = str.length() - 1; 
        for(int i = 0; i < n; i++){
            if(str[i] != str[n - i]){
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"Yes!"<<endl;
        else
            cout<<"No!"<<endl;
    }
    return 0;
}