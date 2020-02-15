/*=========================
  输入一个N维矩阵，判断是否对称
=========================*/



#include<iostream>
using namespace std;

int main(){
    int matrix[100][100];
    int N;
    bool flag = true;
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matrix[i][j] != matrix[j][i]){
                flag = false;
                break;
            }
        }
    }
    if(flag)
        cout<<"Yes!";
    else
        cout<<"No!";
    return 0;
}