#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    /*int n;
    cin>>n;
    int *sign = new int [n]; //动态数组sign用以存储每个ip地址的判断值
    for(int i = 0; i < n; i++)
    {
        string ip;
        cin>>ip;
        sign[i] = 1; //默认ip地址合法
        int sum = 0; //存储当前地址段的值
        int p = 0; //指针
        while(ip[p] != '\0')
        {
            if(ip[p] != '.')
            {
                sum = sum * 10 + (ip[p] - '0');
                if(sum < 0 || sum > 255)
                    sign[i] = 0;
            }
            else
                sum = 0;
            p++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(sign[i] == 1)
            cout<<"Yes!"<<endl;
        else
            cout<<"No!"<<endl;
    }*/
    string ip;
    int s = 1;
    cin>>ip;
    int sum = 0;
    int p = 0; //指针
        while(ip[p] != '\0')
        {
            if(ip[p] != '.')
            {
                sum = sum * 10 + (ip[p] - '0');
                if(sum < 0 || sum > 255)
                    s = 0;
            }
            else
                sum = 0;
            p++;
        }
    if(s == 1)
        cout<<"Yes!"<<endl;
    else
        cout<<"No!"<<endl;
    return 0;
}
