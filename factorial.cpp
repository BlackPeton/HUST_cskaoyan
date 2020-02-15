#include<iostream>
using namespace std;

long fractorial(int n){
    long y = 1;
    for(int i = 1; i <= n; i++)
        y *= i;
    return y;
}

int main(){
    int num;
    long y1 = 0, y2 = 0;
    cin>>num;
    for(int i = 1; i <= num; i += 2)
        y1 += fractorial(i);
    for(int i = 2; i <= num; i += 2)
        y2 += fractorial(i);
    cout<<y1<<' '<<y2;
    return 0;
}

/*补充一个看到的很棒的解法：

    链接：https://www.nowcoder.com/questionTerminal/e58c8a55162d49c48115bdfa5da7da56?f=discussion
    来源：牛客网

    #include <iostream>
    using namespace std;
    int main()
    {
        int n ,ans1, ans2, i, j;
        while (cin >> n) {
            ans1 = ans2 = 0, j = 1;
            for (i = 1; i <= n; ++i) {
                j *= i; //j用来保存当前数字i的阶乘
                if (i % 2) ans1 += j; //i为奇数，ans1加上i！
                else ans2 += j; //i为偶数，ans2加上i！
            }
            cout << ans1 << " " << ans2 << endl;
        }
    }

*/