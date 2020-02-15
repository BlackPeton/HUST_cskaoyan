#include<iostream>

using namespace std;

#define  MAXSIZE 100
typedef struct treeNode{
    int data;
    int lchild, rchild, father;
}BST;
int pos = 0; //插入点指针，若插入结点，其在整个结构数组中的位置为pos
void Initi(BST T[]){
    for(int i = 0; i < MAXSIZE; i++){
        T[i].data = 0;
        T[i].lchild = T[i].rchild = T[i].father = -1;
    }
} //初始化结构数组
void Insert(BST T[], int num){
    if(T[0].data == 0){
        T[0].data = num;
    } //空树，插入根结点
    else{
        T[pos].data = num;
        T[pos].lchild = T[pos].rchild = -1; //取出结构数组中的一个元素并初始化
        int loc = 0;
        while(true){
            if(num > T[loc].data){
                if(T[loc].rchild != -1)
                    loc = T[loc].rchild;
                else{
                    T[loc].rchild = pos, T[pos].father = loc; break;
                }
            } //向右到尽头并插入
            else{
                if(T[loc].lchild != -1)
                    loc = T[loc].lchild;
                else{
                    T[loc].lchild = pos, T[pos].father = loc; break;
                }
            } //向左到尽头并插入
        }//从根结点开始搜索插入位置
    }
    pos++; //完成插入，插入点后移
}
void createBST(int N, BST T[]){
    int num;
    for(int i = 0; i < N; i++){
        cin>>num;
        Insert(T, num);
    }
}

int main(){
    BST tree[MAXSIZE];
    Initi(tree);
    int N;
    cin>>N;
    createBST(N, tree);
    for(int i = 0; i < N; i++){
        if(i == 0){
            cout<<-1<<endl;
        }
        else{
            cout<<tree[tree[i].father].data<<endl;
        }
    }
    return 0;
}

/******************
*一个改进思路：按顺序*
*一次性将结点输入存入*
*结构数组，再构建二叉*
*排序树*************
*******************/