/*==================================================
  输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就
  地逆置)
==================================================*/



#include<iostream>
using namespace std;
int main()
{
    int matrix[100][100], N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cin>>matrix[i][j];
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
    return 0;
}