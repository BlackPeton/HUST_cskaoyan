/*======================
  建立一个升序链表并遍历输出
======================*/



#include<iostream>
using namespace std;

typedef struct LNode{
    int num;
    LNode *next;
}LNode, *LList;

LList CreateLList(){
    LNode *l = new LNode;
    l->num = 0;
    l->next = NULL;
    return l;
} //创建一个空链表

void Insert(LList L, int n){
    LNode *p = L->next, *pre = L; //p、pre分别指示当前结点和前一个结点
    while(p){
        if(n > p->num){
            pre = p;
            p = p->next;
        }
        else break;
    }
    LNode *q = new LNode;
    q->num = n;
    pre->next = q, q->next = p;
}

void Print(LList L){
    LNode *p = L->next;
    while(p){
        cout<<p->num<<' ';
        p = p->next;
    }
}

int main(){
    int n, number;
    LList list = CreateLList();
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>number;
        Insert(list, number);
    }
    Print(list);
    delete list;
    return 0;
}