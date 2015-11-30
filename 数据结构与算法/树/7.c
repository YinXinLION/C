/*************************************************************************
	> File Name: 7.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月30日 星期一 21时57分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
        char element;
        struct Node *Lchild;
        struct Node *Rchild;

}BiTNode,*BiTree;

BiTree create_BTree();
void Preorder(BiTree T);
int Change_Tree(BiTree T);

int main(void)
{
    BiTree T;
    T = create_BTree();
    Change_Tree(T);
    Preorder(T);
}

BiTree create_BTree()
{
    char c;
    int ch;
    BiTree T;
    c = getchar();
    do{
        ch = fgetc(stdin);         
    }while(ch != '\n' && ch != EOF);

    if(c == '#')
    T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T -> element = c;
        T -> Lchild = create_BTree(T -> Lchild);
        T -> Rchild = create_BTree(T -> Rchild);            
    }
    return T;
}

//先序递归遍历二叉树
void Preorder(BiTree T)
{
    if(T == NULL)
    return ;
    else
    {
        printf("%c ",T -> element);//访根
        Preorder(T -> Lchild);//访左
        Preorder(T -> Rchild);//访右
    }
}

int Change_Tree(BiTree T)
{
    BiTree M;
    if(T == NULL)
    return 0;

    if(T -> Lchild != NULL && T -> Rchild != NULL)
    {
        M = T -> Lchild;
        T -> Lchild = T -> Rchild;
        T -> Rchild = M;
    }
    Change_Tree(T -> Lchild);
    Change_Tree(T -> Rchild);
}
