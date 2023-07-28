/*
题目：
假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。
规定每个舞曲能有一对跳舞者。若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。
现要求写一个程序，模拟上述舞伴配对问题。

输入：
第一行两个正整数，表示男士人数m和女士人数n，1<=m,n<=1000；
第二行一个正整数，表示舞曲的数目k，k<=1000。

输出：
共k行，每行两个数，之间用一个空格隔开，表示配对舞伴的序号，男士在前，女士在后。

输入输出样例：

输入
2 4
6

输出
1 1
2 2
1 3
2 4
1 1
2 2
*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAXSIZE 1500

typedef int ElementType;

typedef struct Queue
{
    int front;  //头指针
    int rear;   //尾指针
    int *pBase; //存储空间的基地址
} Queue;


void init_queue(Queue *Q)
{
    Q->pBase = (ElementType *)malloc(MAXSIZE*sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
}

bool is_full(Queue *Q)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)
		return true;
	else
		return false;
}


bool is_empty(Queue *Q)
{
    if(Q->front == Q->rear)
		return true;
	else
		return false;
}

bool enter_queue(Queue *Q, ElementType val)
{
    if(is_full(Q))
        return false;
    else
    {
        Q->pBase[Q->rear] = val;    //ps[i] 里的中括号，C语言处理成运算符，ps[i] 等价于 *(ps+i)
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return true;
    }
}

int length_queue(Queue *Q)
{
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

void match(Queue *Q1, Queue *Q2, int num)
{
    int front1 = Q1->front;
    int front2 = Q2->front;

    for(int i=0; i<num; i++)
    {
        printf("%d ",Q1->pBase[front1]);
        printf("%d\n",Q2->pBase[front2]);
        front1 = (front1+1)%length_queue(Q1);
        front2 = (front2+1)%length_queue(Q2);
    }
}

void main()
{
    Queue Q1;
    Queue Q2;

    init_queue(&Q1);
    init_queue(&Q2);

    int num_m;
    int num_w;
    int num;
    scanf("%d", &num_m);
    scanf("%d", &num_w);
    scanf("%d", &num);

    for(int i=1; i<=num_m; i++)
    {
        enter_queue(&Q1, i);
    }
    for(int j=1; j<=num_w; j++)
    {
        enter_queue(&Q2, j);
    }

    match(&Q1, &Q2, num);
}