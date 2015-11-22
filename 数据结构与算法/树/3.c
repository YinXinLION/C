/*************************************************************************
	> File Name: 3.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月22日 星期日 17时14分10秒
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

int main(void)
{
    BiTree T;
    T = create_BTree();
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
}
