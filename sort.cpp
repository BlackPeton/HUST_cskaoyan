/*=======================
  对输入的n个数进行排序并输出
=======================*/



#include<iostream>
using namespace std;

int main(){
    int data[100] = {0};
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data[i];
    }
    for(int i = 0; i < n; i++){
        int flag = 0; //指示该趟排序中有无元素交换，0为未交换
        for(int j = 0; j < n - i - 1; j++){
            if(data[j] > data[j + 1]){
                int temp = data[j];
                data[j] = data[j + 1], data[j + 1] = temp;
                flag = 1; //标记此趟排序已有元素交换
            }
        }
        if(flag == 0)
            break;
    } //冒泡排序
    for(int i = 0; i < n; i++){
        cout<<data[i]<<' ';
    }
    return 0;
}