/*************************************************************************
	> File Name: 4.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月22日 星期日 17时37分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//二叉树的二叉线索存储结构定义
typedef enum{Link ,Thread}PoinerTag; //Link==0表示指向左右孩子指针
                                 //Thread==1表示指向前驱或后继的线索

typedef struct Node
{
    char data;
    struct Node *Lchild ,*Rchild;
    PoinerTag Ltag;
    PoinerTag Rtag;
}BiNode ,*BiTree;

BiTree create_Tree();
void InThreading(BiTree T);
BiTree pre ;//全局变量,始终指向刚刚访问过的节点
int main()
{
    BiTree T;
    T = create_Tree();
    InThreading(T);
}

BiTree create_Tree()
{
    char c;
    char ch;
    BiTree T;
    c = getchar();
    do{
        ch = fgetc(stdin);
    }while(ch != '\n' && ch != EOF);
    
    if(c == '#')
    T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiNode));
        T -> data = c;
        T -> Lchild = create_Tree();
        T -> Rchild = create_Tree();
    }
}

//中序遍历进行中序线索化
void InThreading(BiTree T)
{
    if(T == NULL)
    return;
    InThreading(T -> Lchild); //递归左子树线索化
    if(!(T -> Lchild)) //没有左孩子 执行
    {
        T -> Ltag = Thread; //前驱线索
        T -> Lchild = pre; //左孩子指针指向前驱
    }
    if(!(pre -> Rchild)) //前驱没有有孩子
    {
        pre -> Rtag = Thread; //后继线索
        pre -> Rchild = T; //前驱右孩子指针指向后继
   }
    pre = T;
    InThreading(T -> Rchild);
}
