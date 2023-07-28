/*
题目: 找出游戏的获胜者
描述：
共有 n 名小伙伴一起做游戏。小伙伴们围成一圈，按 顺时针顺序 从 1 到 n 编号。
确切地说，从第 i 名小伙伴顺时针移动一位会到达第 (i+1) 名小伙伴的位置，其中 1 <= i < n 
从第 n 名小伙伴顺时针移动一位会回到第 1 名小伙伴的位置。
游戏遵循如下规则：
从第 1 名小伙伴所在位置开始 。
沿着顺时针方向数 k 名小伙伴，计数时需要包含起始时的那位小伙伴。逐个绕圈进行计数，一些小伙伴可能会被数过不止一次。
你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。
如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 顺时针下一位 小伙伴 开始，回到步骤 2 继续执行
否则，圈子中最后一名小伙伴赢得游戏。
给你参与游戏的小伙伴总数 n ，和一个整数 k ，返回游戏的获胜者。

输入：
输入为两个整数，n和k(1≤k≤n≤500)

输出：
输出游戏的获胜者

输入输出样例：

输入
5 2

输出
3
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAXSIZE 500

typedef int ElementType;

typedef struct Queue
{
    ElementType front;  //头指针
    ElementType rear;   //尾指针
    ElementType *pBase; //存储空间的基地址
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

void find_winner(Queue *Q, int k, int n)
{
    int status[n];
    int j;
    int step = 0;   //记录走的步长
    for(j=0; j<n; j++)
    {
        status[j] = 1;
    }

    int p = k-1;
    status[p] = 0;
    for(j=0; j<n-2; j++)
    {
        step = 0;
        while(step != k)
        {
            p = (p+1)%n;
            if(status[p] == 1)
                step++;
        }
        status[p] = 0;
    }

    for(j=0; j<n; j++)
    {
        if(status[j] == 1)
        {
            printf("%d", j+1);
            break;
        }
    }
}

void main()
{
    Queue Q;
    init_queue(&Q);

    int n;
    int k;
    int i;

    scanf("%d",&n);
    scanf("%d",&k);

    for(i=0; i<n; i++)
    {
        enter_queue(&Q, i);
    }

    find_winner(&Q, k, n);

}