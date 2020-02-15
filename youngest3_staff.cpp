#include<iostream>
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