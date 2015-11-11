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
    int element;
    struct Node *Lchild;
    struct Node *Rchild;
}BiTNode,*BiTree;


BiTree create_BTree();
void Preorder(BiTree T);
void Inorder(BiTree T);
void Lastorder(BiTree T);
BiTree Find_element(BiTree T,int value);//二叉查找树的查找元素
BiTree Find_Max(BiTree T);
BiTree Find_Max1(BiTree T);
BiTree Find_Min(BiTree T);
void Preorder(BiTree T);
BiTree Insert(BiTree T,int value);


int main()
{
    char c;
    BiTree T;
    BiTree F;
    T = create_BTree();
    printf("要查找的元素:(must be serachTree)");
    scanf("%c",&c);
    F = Find_element(T,c);//查找
    if(!F)
    printf("未找到.\n");
    else
    printf("找到了!元素是%d.\n",F -> element);

    F = Find_Max(T);
    printf("最大数是:%c\n",F -> element);
    F = Find_Max1(T);
    printf("最大数是:%c\n",F -> element);
    F = Find_Min(T);
    printf("最大数是:%c\n",F -> element);

    T = Insert(T , '5');
    printf("先序遍历为:");
    Preorder(T);
    printf("\n");
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



BiTree Find_element(BiTree T,int value)//二叉查找树的查找元素
{
    if(T == NULL)
    return NULL;
    if(value > (T -> element))
    Find_element(T -> Rchild,value);
    else if(value < (T -> element))
    Find_element(T -> Lchild,value);
    else 
    return T;
}

BiTree Find_Max(BiTree T)
{
    if(T != NULL)
    while(T -> Rchild != NULL)
    T = T -> Rchild;
    return T;
}

BiTree Find_Max1(BiTree T)
{
    if(T == NULL)
    return NULL;
    else if(T -> Rchild == NULL)
    return T;
    else 
    return Find_Max1(T->Rchild);
}

BiTree Find_Min(BiTree T)
{
    if(T == NULL)
    return NULL;
    else if(T -> Lchild == NULL)
    return T;
    else 
    return Find_Min(T -> Lchild);
}

//插入二叉树
BiTree Insert(BiTree T,int value)
{
    if(T == NULL)
    {
        //crreate and return a one-node tree
        T = (BiTree)malloc(sizeof(BiTNode));
        if(T == NULL)
        printf("无法创建!error!");
        else
        {
            T -> element = value;
            T -> Lchild = T -> Rchild = NULL;
        }
    }
    else if(value < (T -> element))
    T -> Lchild = Insert(T -> Lchild , value);
    else if(value > (T -> element))
    T -> Rchild = Insert(T -> Rchild , value);
    //如果value在树中不会创建
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
