/*************************************************************************
	> File Name: 4.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年10月25日 星期日 21时42分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_SIZE 100//存储空间出事分配量
#define STACKINCREMENT 19//存储空间分配增量
#define N 8//棋盘大小
#define true 1
#define false 0
int weight [N][N];//各店的权值
int Board[N][N][8];//按各店权值递升存放待走方向,每点8个

typedef struct //位置
{
    int x;
    int y;
}PosType;

typedef struct //栈的元素
{
    int ord;
    PosType seat;
    int di;
}ElemType;

typedef struct //定义栈
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

SqStack s;

int InitStack() //初始化一个空栈
{
    s.base = (ElemType *)malloc(STACK_SIZE * sizeof(ElemType));
    if(!s.base)
    return 0;
    s.top = s.base;
    s.stacksize = STACK_SIZE;
    return 1;
}

ElemType GetTop() //取得栈顶的值
{
    if(s.top == s.base)
    exit(0);
    return *(s.top-1);
}

void Push(ElemType elem) //将元素压入栈
{
    *s.top++=elem;
}

int Pop(ElemType *elem) //将栈顶值出栈
{
    if(s.top == s.base)
    return false;
    *elem = *--s.top;
    return true;
}

int StackEmpty() //判断栈是否为空
{
    if(s.top == s.base)
    return true;
    else
    return false;
}

void OutputPath() //输出马走过的路径
{
    int i,f,k;
    SqStack s1 = s;
    int path[N][N];
    for(i = 0;s1.top!=s1.base;i++)
    {
        path[(*s1.base).seat.x][(*s1.base).seat.y] = i+1;
        ++s1.base;
    }
    for(f = 0;f < N ;f++)
    {
        printf("\n");
        for(k = 0;k < N;k++)
        printf("\t%d",(path[f][k]));
    }
    printf("\n");
}

int Pass(PosType curpos) //判断当前位置是否合法
{
    SqStack s1 = s;
    if(curpos.x < 0 || curpos.x > (N -1) || curpos.y < 0 || curpos.y >(N-1))
    return 0;
    for(;s1.top!=s1.base;)
    {
        --s1.top;
        if(curpos.x == (*s1.top).seat.x&&curpos.y==(*s1.top).seat.y)
        return 0;
    }
    return 1;
}

PosType NextPos(PosType curpos ,int direction) //8个候选方向
{
    switch(direction)
    {
        case 1:curpos.x += 1;curpos.y -= 2 ;break;
        case 2:curpos.x += 2;curpos.y -= 1 ;break;
        case 3:curpos.x += 2;curpos.y += 1 ;break;
        case 4:curpos.x += 1;curpos.y += 2 ;break;
        case 5:curpos.x -= 1;curpos.y += 2 ;break;
        case 6:curpos.x -= 2;curpos.y += 1 ;break;
        case 7:curpos.x -= 2;curpos.y -= 1 ;break;
        case 8:curpos.x -= 1;curpos.y -= 2 ;break;
    }
    return curpos; //返回新点
}

void setweight() //求各点权值
{
    int i,j,k;
    PosType m;
    ElemType elem;
    for(i = 0 ; i < N;i++)
    {
        for(j = 0; j < N ;j++)
        {
            elem.seat.x = i;
            elem.seat.y = j;
            weight[i][j] = 0;
            for(k = 0; k < 8 ;k++)
            {
                m = NextPos(elem.seat,k+1);
                if(m.x > 0 && m.x <N &&m.y >=0&&m.y < N)
                weight[i][j]++;//(i,j)点有几个方向可以移动
            }
        }
    }
}

void setmap() //各点的8个方向按权值递增排列
{
    int a[8];
    int i,j,k,m,min,s,h;
    PosType n1 ,n2;
    for(i = 0;i < N ;i++)
    {
        for(j = 0;j < N;j++)
        {
            for(h = 0; h < 8;h++)//用数组a[8]记录当前位置的下一个位置的可行路径的条数
            {
                n2.x=i;
                n2.y=j;
                n1=NextPos(n2,h+1);
                if(n1.x>=0&&n1.x<N&&n1.y>=0&&n1.y<N)
                a[h] = weight[n1.x][n1.y];
                else
                a[h] = 0;
            }
            
            for(m = 0;m < 8 ;m++)
            {
                min = 9;
                for(k = 0;k < 8;k++)
                if(min > a[k])
                {
                    min = a[k];
                    Board[i][j][m] = k;
                    s = k;
                }
                a[s] = 9;//选过的设为9
            }
        }
    }
}

int HoresePath(PosType start) //马走过的路径
{
    PosType curpos;
    int horsestep = 0, off;
    ElemType elem;
    curpos = start ;
    do{
        if(Pass(curpos)) //如果当前位置合法
        {
            horsestep++;
            elem.di = 0;
            elem.ord = horsestep;
            elem.seat = curpos;
            Push(elem);
            if(N*N == horsestep)
            return 1;
            off = Board[elem.seat.x][elem.seat.y][elem.di] + 1;
            curpos = NextPos(elem.seat ,off); //取得下一个坐标
        }
        else{
            if(!StackEmpty()) //栈s非空
            {
                while(!StackEmpty()&&elem.di == 8)
                {
                    Pop(&elem);
                    if(!StackEmpty()) //判断,弹出后是否为空
                    {
                        elem = GetTop();
                        horsestep = elem.ord;
                    }
                }
                if(!StackEmpty()&&elem.di < 8)
                {
                    Pop(&elem);
                    off=Board[elem.seat.x][elem.seat.y][++elem.di];
                    curpos = NextPos(elem.seat ,off+1);
                    Push(elem);
                }
            }
        }
    }
    while(!StackEmpty());
    printf("走不通");
    return 0;
}

void main()
{
    PosType start;
    InitStack();
    printf("输入起始位置:(0-7)\nX:");
    scanf("%d",&start.x);
    printf("Y:");
    scanf("%d",&start.y);
    setweight();
    setmap();
    HoresePath(start);
    OutputPath();
}







