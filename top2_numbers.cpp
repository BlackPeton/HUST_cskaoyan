/*=======================================
  输入一个四行五列的矩阵，找出每列最大的两个数
  对于每组数据，按照样例输出的格式将每列最大的两个
  数输出，如果最大的两个数中的一个数在这一列中有多
  个相同的值，则行值取行值小的那一个。输出时要保留
  原矩阵的行列顺序，即在原矩阵中行值小的，在输出矩
  阵中的行值依然小。

  样例：
  1  2  4  9  8
  -1 4  9  8  8
  12 9  8  7  0
  7  8  9  7  0
  输出为：
  12 9 9 9 8 
  7  8 9 8 8 
=========================================*/



#include<iostream>
using namespace std;

int main(){
    int matrix[4][5];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        int min = matrix[0][i], pos = 0;
        for(int j = 0; j < 4; j++){
            if(matrix[j][i] < min){
                min = matrix[j][i];
                pos = j;
            }
        } //找出最小元素及其位置
        for(int k = pos; k < 4 - 1; k++)
            matrix[k][i] = matrix[k + 1][i]; //后移
        matrix[3][i] = min;
        min = matrix[0][i], pos = 0; //重置最小元素及其位置
        for(int l = 0; l < 3; l++){
            if(matrix[l][i] < min){
                min = matrix[l][i];
                pos = l;
            }
        } //找出第二小元素及其位置
        for(int m = pos; m < 3 - 1; m++)
            matrix[m][i] = matrix[m + 1][i]; //后移
        matrix[2][i] = min;
    }
    for(int i = 0; i < 5; i++)
        cout << matrix[0][i] << ' ';
    cout << endl;
    for(int i = 0; i < 5; i++)
        cout << matrix[1][i] << ' ';
    cout << endl;
    return 0;
}