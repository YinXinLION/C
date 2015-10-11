/*************************************************************************
    > File Name: 1.c
    > Author:YinXin 
    > Mail:yinxin19950816@gmail.com 
    > Created Time: 2015年10月09日 星期五 17时56分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0


typedef struct ele
{
    int data;
    struct ele *next;
}stack;


void last(char str[]);
stack * InitStack(stack *top);
int StackEmpty(stack *top);
stack *create_node();
stack *push_stack(stack *top ,int a);
stack *pop_stack(stack *top ,int *operate);
char compare(char a , char b);
int judge(char i);
int Operate(int a, char operate ,int b);
void menu();



stack * InitStack(stack *top) //初始化栈
{
    top = create_node();
    top -> data = 0;
    top -> next = NULL;
    return top;
}

int StackEmpty(stack *top) //判断是否为空栈
{
    if(top == NULL)
    return true;
    else
    return false;
}

stack *create_node() //创建节点
{
    stack *head;
    head = (stack *)malloc(sizeof(stack));
    head -> next = NULL;
    return head;
}



stack *push_stack(stack *top ,int a)  //入栈
{
    stack *p;
    p = create_node();
    p -> data = a;

    if(top == NULL)
    {
        top = p;
        return top;
    }
    p -> next = top;
    top = p;
    return top;
}

stack *pop_stack(stack *top ,int *operate)  //出栈
{
    stack *p;
    *operate = top -> data;
    p = top;
    top = top -> next;
    free(p);
    return top;
}


char compare(char a , char b)  //规则表 
{
    int i ,j;
    int lev;  //b的等级
    char pre[][7]={ //运算符之间的优先级
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'}, 
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='},
    };
    switch(a)
    {
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;

    }
    switch(b)
    {
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
    }
    return pre[i][j];
}

int judge(char i)  //判断是 数字 还是 符号
{
    if('0' <= i && i <= '9')
    return 0;
    else
    return 1;
}


int Operation(int a, char operate ,int b) //两数进行计算
{
    int i ,j ,result;
    i = a;
    j = b;

    switch(operate)
    {
        case '+': result = i + j; break;
        case '-': result = i - j; break;
        case '*': result = i * j; break;
        case '/': result = i / j; break;
    }
    return result;
}

void menu() //菜单 输入
{
    char str[40];
    printf("---------------calcuate--------------\n");
    fgets(str,40,stdin);
    last(str);
}

void last(char str[])
{
    int i = 0 , flag; //flag 0为数字 1为 运算符
    stack *top_cha = NULL; 
    stack *top_num = NULL ;
    int sum = 0;
    char com;   //比较
    int operate ,a ,b ,result;
    int j;
    top_cha = push_stack(top_cha ,'#');
    while(str[i] != '#' || (top_cha -> data) != '#')
    {
        if(str[i] == ' ')
        {
            i++;
            continue;
        }
        flag = judge(str[i]);
        if(flag == 0)
        {
            j = i;
            while(1)
            {
                if(judge(str[j]) == 1)
                break;
                else
                sum = sum * 10 + (str[j] - '0');
                j++;
                i = j- 1;
            }
            top_num = push_stack(top_num , sum);
            sum = 0;
        }
        if(flag == 1)
        {
            com = compare(top_cha -> data ,str[i]);
            switch(com)
            {
                case '<':
                top_cha = push_stack(top_cha ,str[i]);
                break;
                case '=':
                top_cha = pop_stack(top_cha,&operate);
                break;
                case '>':
                top_cha = pop_stack(top_cha ,&operate);
                top_num = pop_stack(top_num ,&b); 
                top_num = pop_stack(top_num ,&a);
                top_num = push_stack(top_num ,Operation(a,operate,b));
                i--;
                break;
            }
        }
        i++;
    }
    
    result = top_num -> data;
    printf("%d",result);
}

int main(void)
{
    menu();
    return 0;
}
