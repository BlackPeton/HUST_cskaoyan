/*==========================================
  输入一系列整数，将其中最大的数挑出(如果有多个，则挑
  出一个即可)，并将剩下的数进行排序，如果无剩余的数，
  则输出-1。
==========================================*/



#include<iostream>
using namespace std;

int main(){
    int data[1000] = {0};
    int n, max, pos; //max和pos分别表示最大值及其在数组中的位置
    max = INT_MIN;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data[i];
        if(data[i] > max){
            max = data[i], pos = i;
        }
    }
    for(int i = pos; i < n - 1; i++){
        data[i] = data[i + 1];
    } //去除最大值，将其后的元素前移
    for(int i = 0; i < n - 1; i++){
        int flag = 0;
        for(int j = 0; j < n - i - 2; j++){
            if(data[j] > data[j + 1]){
                int temp = data[j];
                data[j] = data[j + 1], data[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag ==0)
            break;
    }
    cout<<max<<endl;
    if(n == 1)
        cout<<-1;
    else{
        for(int i = 0; i < n - 1; i++){
            cout<<data[i]<<' ';
        }
    }
    return 0;
}