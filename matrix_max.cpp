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