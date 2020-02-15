/*==============================
  输入一个整数，将其转换成八进制数输出
==============================*/



#include<iostream>
#include<stack>
using namespace std;

int main(){
    int num;
    stack<int> S;
    while(cin>>num){
        int quotient, remainder;
        quotient = num;
        while(quotient / 8 != 0){
            remainder = quotient % 8, quotient /= 8;
            S.push(remainder);
        }
        S.push(quotient % 8); //注意到当num < 8时不进入循环，直接将num入栈；且当除到八进制数最高位时，quotient < 8，不
        while(!S.empty()){    //进入循环，此步骤可将最高位入栈
            int n = S.top();
            cout<<n;
            S.pop();
        }
    }
    return 0;
}

/*此处为了熟悉STL的使用采取了复杂的方法，可以不使用stack而采用数组存储每位数字
  输出时从后往前输出

  更为偷懒的方法：
  C语言在printf中使用%o控制输出八进制数
  C++中使用cout<<oct<<n控制输出八进制数

*/