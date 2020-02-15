/*======================================
  给出年分m和一年中的第n天，算出第n天是几月几号
  输出的月份和日期要求两位
  例如：
  输入“2000 3”
  输出“2000-01-03”
=======================================*/



#include<iostream>
using namespace std;

int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
void specificPrint(int n){
    if(n < 10)
        cout << 0 << n;
    else
        cout << n;
}

int main(){
    int y, m, d;
    m = 0;
    cin >> y >> d;
    if(isLeapYear(y)){
        while(d > leap_year[m]){
            d -= leap_year[m];
            m++;
        }
    }
    else{
        while(d > year[m]){
            d -= year[m];
            m++;
        }
    }
    m++;
    cout << y << '-';
    specificPrint(m);
    cout << '-';
    specificPrint(d);
    cout << endl;
    return 0;
}