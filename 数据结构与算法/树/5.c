/*************************************************************************
	> File Name: 5.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月24日 星期二 12时54分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
typedef struct node{
    int data;
    struct node *left ,*right;
}BTNode;

BTNode *Create_Tree(int a[])
{
    BTNode *root ,*c ,*pa ,*p;
    int i;
    root = (BTNode *)malloc(sizeof(BTNode));
    root -> data = a[0];
    root -> left = root -> right = NULL;
    for(i = 1;i < N ;i++)
    {
        p = (BTNode *)malloc(sizeof(BTNode));
        p -> data = a[i];
        p -> left = p -> right = NULL;
        c = root;
        while(c)
        {
            pa = c;
            if(c -> data < p -> data)
            c = c -> right;
            else
            c = c -> left;
        }
        if(pa -> data < p -> data)
        pa -> right = p;
        else
        pa -> left = p;
    }
    return root;
}


void level_tree(BTNode *root)
{
    BTNode **Q;
    BTNode *p;
    int front ,rear;
    Q = (BTNode **)malloc((N+1)*sizeof(BTNode *));
    front = rear = 0;
    Q[++rear] = root;
    while(front - rear)
    {
        p = Q[++front];
        printf("%3d ",p -> data);
        if(p -> left)
        Q[++rear] = p -> left;
        if(p -> right)
        Q[++rear] = p -> right;
    }
    free(Q);
}


void preorder_tree(BTNode *root)
{
    BTNode **s;
    BTNode *p;
    int top;
    s = (BTNode **)malloc(N*sizeof(BTNode *));
    top = -1;
    s[++top] = root;
    while(top != -1)
    {
        p = s[top--];
        printf("%3d ",p->data);
        if(p->right) s[++top] = p -> right;
        if(p -> left) s[++top] = p -> left;
    }
    free(s);
}



int main(void)
{
    int data[N] = {6,2,8,9,1};
    BTNode *root;
    root = Create_Tree(data);
    level_tree(root);
    printf("\n");
    preorder_tree(root);
    return 0;
}













