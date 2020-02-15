#include<iostream>
/*==================================
  职工有职工号，姓名，年龄.输入n个职工的信
  息，找出3个年龄最小的职工打印出来。
  若有相同的关键字，则按照“年龄>工号>姓名”
  且由小到大的顺序排序
  职工号(整数)，姓名(字符串，长度不超过10)，
  年龄(整数，1～100)
===================================*/



#include<string>
#include<algorithm>
using namespace std;

struct Staff{
    string name;
    int number, age;
};

bool cmp(Staff a, Staff b){
    if(a.age != b.age)
        return a.age < b.age;
    else if(a.number != b.number)
        return a.number < b.number;
    else
        return a.name < b.name;
}

int main(){
    int N;
    Staff sta[30];
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> sta[i].number >> sta[i].name >> sta[i].age;
    sort(sta, sta + N, cmp);
    for(int i = 0; i < 3; i++)
        cout << sta[i].number << ' ' << sta[i].name << ' ' << sta[i].age << endl;
    return 0;
}