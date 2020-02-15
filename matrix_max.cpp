/*====================================
  编写一个程序输入一个m*n的矩阵存储并输出，并
  且求出每行的最大值和每行的总和。 要求把每行
  总和放入每行最大值的位置，如果有多个最大值，
  取下标值最小的那一个作为最大值。 最后将结果
  矩阵输出。
====================================*/



#include<iostream>
using namespace std;

int main(){
    int matrix[100][100];
    int row, col;
    cin >>row>>col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>matrix[i][j];
        }
    }
    int max, sum, pos;
    for(int i = 0; i < row; i++){
        max = INT_MIN, sum = 0;
        for(int j = 0; j < col; j++){
            sum += matrix[i][j];
            if(matrix[i][j] > max){
                max = matrix[i][j];
                pos = j;
            }
        }
        matrix[i][pos] = sum;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<matrix[i][j];
            if(j == col - 1)
                cout<<endl;
            else
                cout<<' ';
        }
    }
    return 0;
}