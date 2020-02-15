#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Student{
    //char name[100];
    string name;
    int age, grade;
};

bool cmp(Student a, Student b){
    if(a.grade != b.grade)
        return a.grade < b.grade;
    else if(a.name != b.name)
        return a.name < b.name;
    else
        return a.age < b.age;
} //两字符串比较时，string类型可直接比较，字符数组则需使用strcmp()函数比较

int main(){
    Student Stu[1000];
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Stu[i].name >> Stu[i].age >> Stu[i].grade;
    }
    sort(Stu, Stu + N, cmp);
    for(int i = 0; i < N; i++){
        cout << Stu[i].name << ' ' << Stu[i].age << ' ' << Stu[i].grade << endl;
    }
    return 0;
}