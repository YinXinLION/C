/*************************************************************************
	> File Name: yuesefu.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月17日 星期四 18时10分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct people{
    int id;
    int number;
    struct people *next;
};

void print(struct people * head);
struct people *create_link(int n);
struct people *create_node();
void input_number(struct people *head,int n);
void JosephusOperate(struct people *tail);


int main(void)
{
    struct people *tail;
    int n,q;
    printf("多少个人?\n");
    scanf("%d",&n);
    fflush(stdin);
    tail = create_link(n); //创建循环链表
    print(tail);
    printf("每隔几个人?\n");
    scanf("%d",&q);
    fflush(stdin);
    input_number(tail ,q);//放NUMBER值
    JosephusOperate(tail);//执行
}

struct people *create_node()
{
    struct people *head;
    head = (struct people *)malloc(sizeof(struct people));
    head -> next = NULL;
    return head;
}

struct people *create_link(int n)
{
    int i;
    struct people *head,*p,*tail;
    head = tail = NULL;

    for(i = 0;i < n  ;i++)
    {
        if(head == NULL)
        {
            head = tail = create_node();
            head -> id = i;
        }
        else 
        {
            p = create_node();
            p -> id = i;
            p -> next = tail -> next;
            tail -> next = p;
            tail = p;
        }
    }
    tail -> next = head;
    return tail;

}

void print(struct people * tail)
{
    struct people * p;
    p = tail ;
    while(p != NULL)
    {
        printf("%d",p->id);
        p = p -> next;
        if(p == tail)
        break;
    }
    printf("\n");
}


void input_number(struct people *tail,int n)
{
    struct people *p = tail;
    while(p != NULL)
    {
        p -> number = n;
        p = p -> next;
        if(p == tail)
        break;
    }
}

void JosephusOperate(struct people *tail)
{
    int n,i;
    struct people *p ,*q;
    p = tail;
    while(1)
    {
        n = p -> next -> number;
        for(i = 0; i < n -1; i++)
        {
            p = p -> next;
        }
        q = p -> next;
        printf("%d\n",q->id);
        p -> next = q -> next;
        free(q);
        
        if(p -> next == p)
        break;
    }
    printf("%d\n",p -> id);

}
