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