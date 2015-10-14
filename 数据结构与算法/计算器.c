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
    double data;
    struct ele *next;
}stack;

void last(char str[]);
stack * InitStack(stack *top);
int StackEmpty(stack *top);
stack *create_node();
stack *push_stack(stack *top ,double a);
stack *pop_stack(stack *top ,double *operate);
char compare(char a , char b);
int judge(char i);
double Operate(double a, char operate ,double b);
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



stack *push_stack(stack *top ,double a)  //入栈
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

stack *pop_stack(stack *top ,double *operate)  //出栈
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
    return pre[i][j]; //得出优先级大小
}

int judge(char i)  //判断是 数字 还是 符号
{
    int j;
    char s[7] = {'+','-','*','/','(',')','#'};
    if('0' <= i && i <= '9')
    return false; //0
    for(j = 0; j < 7; j++)
    {
        if(s[j] == i)
        return true;
    }
    if(i == '.')
    return 3;

    return 2; //2 为出错
    
}


double Operation(double a, char operate ,double b) //两数进行计算
{
    double i ,j; 
    double result;
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
    int i = 0 , flag ,stat = 0; //flag 0为数字 1为 运算符
    stack *top_cha = NULL; //运算符栈
    stack *top_num = NULL; //数字栈
    double sum = 0;
    double op = 10;
    char com;   //比较
    double operate ,a ,b ,result; //operate保存操作符 a,b保存操作数 result保存最后结果
    int j; //辅佐扫描字符串为数字
    top_cha = push_stack(top_cha ,'#');
    top_num = InitStack(top_num);
    while(str[i] != '#' || (top_cha -> data) != '#')
    {
        if(str[i] == ' ')
        {
            i++;
            continue;
        }
        flag = judge(str[i]); //判断是字符数字 还是 运算符
        if(flag == 0) //是数字的话
        {
            j = i;
            while(1)
            {
                if(stat == 0)
                {
                    if(judge(str[j]) == false)
                    sum = sum * 10 + (str[j] - '0');
                    
                }
                if(judge(str[j]) == true)
                {
                    i = j - 1;
                    break;
                }
                if(judge(str[j]) == 3)
                {
                    stat = 1;
                    j++;
                }
                if(stat == 1)
                {
                    sum = sum + (str[j] - '0')/op;
                    op = op * 10;
                }
                j++;
            }
            top_num = push_stack(top_num , sum);
            stat = 0;
            sum = 0;
            op = 10;
        }
        if(flag == 1)//是字符的话
        {
            com = compare(top_cha -> data ,str[i]); //比较栈顶的运算符和即将放入的运算符这两个的优先级
            switch(com)
            {
                case '<'://栈顶运算符小
                top_cha = push_stack(top_cha ,str[i]);
                break;
                case '='://运算符优先级一样
                top_cha = pop_stack(top_cha,&operate);
                break;
                case '>'://栈顶运算符大
                top_cha = pop_stack(top_cha ,&operate);
                top_num = pop_stack(top_num ,&b); 
                top_num = pop_stack(top_num ,&a);
                top_num = push_stack(top_num ,Operation(a,operate,b));
                i--;
                break;
            }
        }
        if(flag != true && flag != false)
        {
            printf("input error\n");
            exit(0);
        }
        i++;
    }
    result = top_num -> data; //存放结果
    printf("->%lf\n",result);
}

int main(void)
{
    printf("Instruction : Please add at the end # ;\n");
    printf("example: 2+3#\n");
    while(1)
    {
        menu();
    }
    return 0;
}
