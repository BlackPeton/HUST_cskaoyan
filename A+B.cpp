#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char A_char[1000], B_char[1000];
int A_int[1000] = {0}, B_int[1000] = {0}, sum[1001];

int main(){
    cin >> A_char >> B_char;
    int len1, len2;
    len1 = strlen(A_char), len2 = strlen(B_char);
    reverse(A_char, A_char + len1);
    reverse(B_char, B_char + len2);
    for(int i = 0; i < len1; i++)
        A_int[i] = A_char[i] - '0';
    for(int i = 0; i < len2; i++)
        B_int[i] = B_char[i] - '0';
    int c = 0; //进位位
    for(int i = 0; i <= len1 || i <= len2; i++){ //此处详解见末尾
        sum[i] = (A_int[i] + B_int[i] + c) % 10; //当前位的值
        c = (A_int[i] + B_int[i] + c) / 10; //当前为的进位值
    }
    int len = len1 > len2 ? len1 : len2; //得到最终和的长度
    for(int i = len; i >= 0; i--){ //逆序输出
        if(i == len && sum[i] == 0) //最高位为0不输出
            continue;
        cout << sum[i];
    }
    cout << endl;
    return 0;
}

/*关于按位加法循环条件的说明：
  这里循环条件中的<=与前面的初始化数组全为0一起保证能正常处理进位
  例如若len1 < len2，len1 <= i <= len2时，A_int[i]实际不是
  数A的有效位，但它们都为0，可与数B的有效位相加实现正常的进位，同
  时也保证了最高位的进位
*/