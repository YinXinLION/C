/*************************************************************************
	> File Name: 1.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月30日 星期一 21时27分17秒
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
int  judge_degree_2(BiTree T);
int main(void)
{
    BiTree T;
    int sum;
    T = create_BTree();
    sum = judge_degree_2(T);
    printf("度为2的节点有%d个\n",sum);
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

int  judge_degree_2(BiTree T)
{
    int s;
    if(T == NULL)
    {
        return 0;
    }
    if(T -> Lchild != NULL && T -> Rchild != NULL)
    s = 1;
    else 
    s = 0;
    return s + judge_degree_2(T -> Lchild) + judge_degree_2(T -> Rchild);


}
