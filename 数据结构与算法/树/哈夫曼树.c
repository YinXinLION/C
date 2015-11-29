/*************************************************************************
	> File Name: 5.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年11月22日 星期日 21时57分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//哈弗曼树的静态三叉链表
#define N 30
#define M 2*N-1
typedef struct{
    int weight;
    int parent ,Lchild ,Rchild;
}HTnode; //0号单元不使用

HTnode ht[M+1];
typedef char *HuffmanCode;

void CrtHuffmanTree(int w[] ,int n);
void select_tree(HTnode ht[] ,int n ,int *s1 ,int *s2);
void CrtHuffmanCode_function(HuffmanCode hc[] ,int n);
void decode(HuffmanCode hc[] ,int n);
void Print_Tree(int n , int heigh);

int main(void)
{
    int n=3;
    int i;
    int w[4] = {1,1,2,3};
    int ch;
    int heigh = 0;
    HuffmanCode hc[N+1]; 
    printf("输入几个");
    scanf("%d",&n); 
    do{
        ch = fgetc(stdin);     
    } while (ch != '\n' && ch != EOF);
    for(i = 0; i < n; i++ )
    {
        scanf("%d",w+i+1);
    }
    CrtHuffmanTree(w ,n);
    for(i = 1; i <2 * n ;i++)
    printf("weight:%d  parent:%d  Lchild:%d  Rchild:%d \n",ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
    CrtHuffmanCode_function(hc,n);
    for(i = 1; i <= n;i++)
    printf("%s\n",hc[i]);
    decode(hc , n);
    Print_Tree(2 * n - 1 ,heigh);
}
//ht:哈弗曼树 w:构造哈弗曼树节点的权值 n:构造哈弗曼树节点的个
void CrtHuffmanTree(int w[] ,int n)
{
    int m = 2 * n - 1;
    int s1 ,s2;
    int i;
    for(i = 1; i <= n; i++) 
    {
        ht[i].weight = w[i];
        ht[i].parent = ht[i].Lchild = ht[i].Rchild = 0;
    }//初始化前n个元素成为根节点
   
    for(i = n + 1; i <= m; i++)
    {
       ht[i].weight = ht[i].parent = ht[i].Lchild = ht[i].Rchild = 0;
    } //初始化后n-1个空元素
   
    for(i = n + 1;i <= m ;i++) //从第n+1个元素开始构造新节点
    {
        select_tree(ht ,i-1 ,&s1 ,&s2);
        //在ht的前i-1项中选双亲为0且权值最小的两节点s1 ,s2
        ht[i].weight = ht[s1].weight + ht[s2].weight;//建新节点,赋权值
        ht[i].Lchild = s1;//赋新节点左,右孩子指针
        ht[i].Rchild = s2;
        ht[s1].parent = i;//改s1 ,s2的双亲指针
        ht[s2].parent = i;
    }
}

void select_tree(HTnode ht[] ,int n ,int *s1 ,int *s2)
{
    int i ;
    int x1 ,x2;
    int t;
    for(i = 1; i <= n; i++)
    {
        if(ht[i].parent == 0)
        {
            x1 = i;
            break;
        }
    }   
    for(i = 1; i <= n ; i++)
    {
        if(ht[x1].weight > ht[i].weight && (ht[i].parent == 0 ))
        x1 = i;
    }   
    for(i = 1; i <= n ; i++)
    {
        if(ht[i].parent == 0 &&(i != x1))
        {
            x2 = i;
            break;
        }
    }
    for(i = 1;i <= n; i++)
    {
        if(ht[x2].weight > ht[i].weight && (ht[i].parent == 0)&&(i != x1))
        x2 = i;
    }
    *s1 = x1;
    *s2 = x2;
}

void CrtHuffmanCode_function(HuffmanCode hc[] ,int n)
{
    int i ,p;
    char *cd;
    int start ,c;
    cd = (char *)malloc(n * sizeof(char)); //临时编码数组
    cd[n - 1] = '\0';//从后向前逐位求编码,首先放编码结束符
    for(i = 1;i <= n; i++) //从每个叶子开始,求相应的哈弗曼编码
    {
        start = n - 1;
        c = i;
        p = ht[i].parent;//c为当前结点,p为其双亲
        while(p != 0)
        {
            --start;
            if(ht[p].Lchild == c) //是双亲左孩子为0
            cd[start] = '0'; 
            else //是双亲右孩子为1
            cd[start] = '1';
            c = p;
            p = ht[c].parent;
        }
        hc[i] = (char *)malloc((n - start) * sizeof(char));//动态申请编码串空间 带'\0'
        strcpy(hc[i],&cd[start]); //放入hc中
    }
}

void decode(HuffmanCode hc[] ,int n)
{
    int i ,j ,m;
    for(i = 1;i <= n;i++)
    {
        printf("%s : ",hc[i]);
        j = 2 * n - 1;
        m = 0;
        while(hc[i][m] != '\0')
        {
            if(hc[i][m] == '0')
            j = ht[j].Lchild;
            else
            j = ht[j].Rchild;
            m++;
        }
        printf("weight = %d\n",ht[j].weight);
    }
}

void Print_Tree(int root , int heigh)
{
    int i;
    if(root == 0)
    return ;
    Print_Tree(ht[root].Rchild , heigh + 1);
    for( i = 0;i < heigh ;i++)
    printf("   ");
    printf("%d\n",ht[root].weight);
    Print_Tree(ht[root].Lchild,heigh + 1);
}

