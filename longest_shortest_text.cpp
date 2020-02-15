#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str;
    vector<string> vec; //使用vector容器来存储输入的字符串
    while(getline(cin, str)){ //注意字符串中可能存在空格
        vec.push_back(str);
    }
    int n = vec.size();
    int maxlen = 0, minlen = 1001;
    for(int i = 0; i < n; i++){
        if(vec[i].length() > maxlen)
            maxlen = vec[i].length();
        if(vec[i].length() < minlen)
            minlen = vec[i].length();
    } //确定最大、最小字符串长度
    vector<int> max, min;
    for(int i = 0; i < n; i++){
        if(vec[i].length() == maxlen)
            max.push_back(i);
        if(vec[i].length() == minlen)
            min.push_back(i);
    } //统计最长和最短的字符串
    for(int i = 0; i < min.size(); i++){
        int pos = min[i];
        cout<<vec[pos]<<endl;
    }
    for(int i = 0; i < max.size(); i++){
        int pos = max[i];
        cout<<vec[pos]<<endl;
    }
    return 0;
}