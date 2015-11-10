/*************************************************************************
	> File Name: 1.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月10日 星期二 19时05分03秒
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
void Inorder(BiTree T);
void Lastorder(BiTree T);
BiTree Find_element(BiTree T,char value);//二叉查找树的查找元素
int main()
{
    char c;
    BiTree T;
    BiTree F;
    T = create_BTree();
    printf("先序遍历为:");
    Preorder(T);
    printf("\n");
    printf("中序遍历为:");
    Inorder(T);
    printf("\n");
    printf("后序遍历为:");
    Lastorder(T);
    printf("\n");
    printf("要查找的元素:(must be serachTree)");
    scanf("%c",&c);
    F = Find_element(T,c);//查找
    if(!F)
    printf("未找到.\n");
    else
    printf("找到了!元素是%c.\n",F -> element);
}

BiTree create_BTree()
{
    char c;
    int ch;
    BiTree T;
    c = getchar();
    do{
         ch = fgetc(stdin);
    } while (ch != '\n' && ch != EOF);
    if(c == '#')
    {
        T = NULL;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T -> element = c;
        T -> Lchild = create_BTree();
        T -> Rchild = create_BTree();

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

//中序递归遍历二叉树
void Inorder(BiTree T)
{
    if(T == NULL)
    return ;
    else
    {
        Inorder(T -> Lchild);//访左
        printf("%c ",T -> element);//访根
        Inorder(T -> Rchild);//访右
    }
}

//后序递归遍历二叉树
void Lastorder(BiTree T)
{
    if(T == NULL)
    return ;
    else
    {
        Lastorder(T -> Lchild);
        Lastorder(T -> Rchild);
        printf("%c ",T -> element);
    }
}


