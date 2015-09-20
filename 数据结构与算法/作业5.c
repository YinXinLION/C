/*************************************************************************
	> File Name: 5.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年09月20日 星期日 22时37分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element{
    int data;
    struct Element *next;
}node;


node *createlink();
node *createnode();
void find_del(node *s);
int main()
{
    node *head ,*s;
    head = createlink();
    s = head -> next -> next;
    printf("%d\n",s -> data);

    find_del(s);

}

node *createnode()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head -> next = NULL;
    return head ;
}

node *createlink()
{
    node *head,*p,*q;
    int i;
    head = p = createnode();
    head -> data = 0; 
    for(i = 1; i <5 ;i++)
    {
        q = createnode();
        q -> data = i;
        p -> next = q;
        p = q;
    }
    p -> next = head;
    return head;
}

void find_del(node *s)
{   
    node *p,*q;
    p = s;
    while(1)
    {
        if(p -> next -> next == s)
        {
            break;
        }
        else
        p = p -> next;
    }
    printf("%d\n",p -> next -> data);
    q = p -> next;
    p -> next = q -> next;
    free(q);
}
