/*************************************************************************
	> File Name: 2.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年10月13日 星期二 08时47分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct ele
{
    char data;
    struct ele *next;
}node;

node *create_node();
void push_stack(node **top ,char data);
void pop_stack(node **top,char *c );
int judge_brackets(node *top ,char str[]);
void menu();
void Initstack(node **s );
void push_stack_all(node **s,char str[]);
void Start(char str[]);
void print(node *s);


node *create_node()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head -> next = NULL;
    return head;
}

void push_stack(node **top ,char data)
{
    node *p;
    p = create_node();
    p -> data = data;
    if(*top == NULL)
    {
        *top = p;
        return ;
    }
    p -> next = *top;
    *top = p;
}

void push_stack_all(node **s,char str[])
{
    int i = 0;
    while(1)
    {
        if(str[i] == '\0')
        break;
        push_stack(s ,str[i]);
        i++;
    }
}

void in_queue(node **head ,char c ,node **tail)
{
    node *p;
    p = create_node();
    if(head == NULL)
    p = *head = *tail;
    else
    {
        (*head) -> next = p;
        (*head) = p;
    }
}

void out_queue(node **head ,node **tail ,char *c)
{
    node *p;
    p    = *tail;
    *c   = p -> data;  
    (*tail) = (*tail) -> next;
    free(p);
}


void pop_stack(node **top ,char *c)
{
    node *p;
    p  = *top;
    *c = (*top) -> data;
    (*top) = (*top) -> next;
    free(p);
}

int judge_brackets(node *top ,char str[])
{
    char c;
    int i = 0;
    while(1)
    {
        switch(str[i])
        {
            case '(':
                   push_stack(&top ,str[i]);
                   break;
            case ')':
            if(top  == NULL)
            return false;
            else
            pop_stack(&top,&c);
        }           
        i++;
        if(str[i] == '\0')
        break;
    }
    if(top  == NULL)
    return true;
    else
    return false;
}

void Start(char str[])
{
    char c ,a;  // a在'('(左括号)后头
    node *s = NULL,*s1 = NULL ,*s2 = NULL;
    push_stack_all(&s ,str);   //入栈
    while(s != NULL)
    {
        while(1)   //将s放入s1
        {
            if(s == NULL)
            break;
            pop_stack(&s ,&c);
            if(c == '(')
            break;
            push_stack(&s1 ,c);
        }   

        if(s == NULL)
        break;

        pop_stack(&s1 ,&a);

        while(1)
        {
            push_stack(&s2 ,a);
            pop_stack(&s1 ,&c);
            if(c == ')')
            break;
            push_stack(&s2 ,c); 
        }

        while(s2 != NULL)
        {
            pop_stack(&s2 ,&c);
            push_stack(&s ,c);
        }
        if(s == NULL)
        break;
    }


    while(s1->next != NULL)
    {
        pop_stack(&s1 ,&c);
        if(c == 'B')
        {
            push_stack(&s ,'b');
            push_stack(&s ,'a');
        }
        else if(c == 'A')
        {
            push_stack(&s ,'d');
            push_stack(&s ,'c');
        }
        else
        push_stack(&s ,c);
    }
    

    while(s != NULL)
    {
        pop_stack(&s ,&c);
        if(c == 'B')
        {
            push_stack(&s1 ,'b');
            push_stack(&s1 ,'a');
        }
        else if(c == 'A')
        {
            push_stack(&s1 ,'d');
            push_stack(&s1 ,'c');
        }
        else
        push_stack(&s1 ,c);
    }
    print(s1); 
    printf("\n");
}

void print(node *s)
{
    node *p;
    p = s;
    while(1)
    {
        printf("%c",p->data);
        p = p->next;
        if(p == NULL)
        break;
    }
}

void menu()
{
    node *S = NULL ,*tail;
    int flag;
    char str[40];
    printf("---------------king language--------------\n");
    scanf("%s",str);
    flag = judge_brackets(S ,str);
    if(flag == false)
    {
        printf("input language error\n");
        exit(0);
    }
    if(S == NULL)
    Start(str);
    
}

int main(void)
{
    menu();
    return 0;
}
