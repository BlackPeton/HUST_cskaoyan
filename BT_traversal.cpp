/*========================================
  给定一棵二叉树的前序遍历和中序遍历，求其后序遍历
========================================*/



//重建二叉树后进行后序遍历输出
#include<iostream>
using namespace std;

typedef struct Node{
    char cha;
    Node *lchild, *rchild;
}*BT; //树结点，用于重建二叉树

char preQue[26], inQue[26]; //前序、中序遍历序列

BT reBuild(int preL, int preH, int inL, int inH){ //参数分别为需要重建的子树在前序、中序序列中的起止位置
    if(preL > preH || inL > inH) //子树不存在，到达尽头
        return NULL;
    Node* root = new Node; //新建当前子树根结点
    root->cha = preQue[preL]; //根结点为前序序列的第一个点
    int pos;
    for(pos = inL; pos <= inH; pos++){
        if(root->cha == inQue[pos])
            break;
    } //找到根结点在中序序列中的位置
    int len = pos - inL; //该根结点的左子树结点数
    root->lchild = reBuild(preL + 1, preL + len, inL, pos - 1); //重建左子树
    root->rchild = reBuild(preL + len + 1, preH, pos + 1, inH); //重建右子树
    return root;
}
void postOrder(BT T){
    if(T->lchild)
        postOrder(T->lchild);
    if(T->rchild)
        postOrder(T->rchild);
    cout << T->cha;
}

int main(){
    while(cin >> preQue >> inQue){
        int l;
        for(l = 0; preQue[l] != '\0'; l++);
        BT T = reBuild(0, l, 0, l);
        postOrder(T);
        cout << endl;
        delete T;
    }
    return 0;
}


/*
//直接得到后序遍历序列，不重建二叉树
#include<iostream>
using namespace std;

char preQue[26], inQue[26], postQue[26];
int p = 0; //插入点在后序序列中的位置

void Post(int preL, int preH, int inL, int inH){
    if(preL > preH || inL > inH) //到达尽头
        return;
    int pos;
    for(pos = inL; pos <= inH; pos++){
        if(preQue[preL] == inQue[pos])
            break;
    } //找到当前根结点在中序序列中的位置
    int len= pos - inL;
    Post(preL + 1, preL + len, inL, pos - 1); //递归处理左子树
    Post(preL + len + 1, preH, pos + 1, inH); //递归处理右子树
    postQue[p++] = preQue[preL]; //将当前根结点存入后序序列
}

int main(){
    while(cin >> preQue >> inQue){
        int l = 0;
        while(preQue[l++]);
        Post(0, l, 0, l);
        for(int i = 0; i <= l; i++)
            cout << postQue[i];
        cout << endl;
        p = 0; //重置插入点位置供下一组输入用
    }
    return 0;
}
*/


/*--------看到的一种使用STL实现的简洁方法
#include<iostream>
#include<string>
using namespace std;

void Post(string str1, string str2){
    if(str1.length() == 0)
            return;
    int len = str2.find(str1[0]); //得到左子树结点数
    Post(str1.substr(1, len), str2.substr(0, len)); //递归处理左子树
    Post(str1.substr(1 + len), str2.substr(len + 1)); //递归处理右子树
    cout<<str1[0];
}

int main(){
    string pre, in;
    while(cin >> pre >> in){
        Post(pre, in);
    }
    return 0;
}
*/