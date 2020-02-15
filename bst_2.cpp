/*=====================================
  输入一系列整数，建立二叉排序树，并进行前序，
  中序，后序遍历
=====================================*/



#include<iostream>
using namespace std;

typedef struct treeNode{
    int num;
    treeNode *lchild, *rchild;
}*BST; //不同于bst.cpp，此处采用链表结构
void Insert(BST &T, int n){
    if(T == NULL){
        treeNode *t = new treeNode;
        t->num = n;
        t->lchild = t->rchild = NULL;
        T = t;
        return;
    }
    if(n == T->num){
        return;
    }
    else if(n > T->num){
        Insert(T->rchild, n);
    }
    else{
        Insert(T->lchild, n);
    }
} //递归插入结点
BST CreateBST(int N){
    BST T = NULL;
    int n;
    for(int i = 0; i < N; i++){
        cin>>n;
        Insert(T, n);
    }
    return T;
}
void preOrder(BST T){
    if(T == NULL){
        return;
    }
    cout<<T->num<<' ';
    preOrder(T->lchild);
    preOrder(T->rchild);
} //前序遍历
void inOrder(BST T){
    if(T == NULL){
        return;
    }
    inOrder(T->lchild);
    cout<<T->num<<' ';
    inOrder(T->rchild);
} //中序遍历
void postOrder(BST T){
    if(T == NULL){
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout<<T->num<<' ';
} //后序遍历

int main(){
    int N;
    cin>>N;
    BST T = CreateBST(N);
    preOrder(T);
    cout<<endl;
    inOrder(T);
    cout<<endl;
    postOrder(T);
    delete T;
    return 0;
}