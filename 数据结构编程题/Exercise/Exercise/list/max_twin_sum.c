/*
题目: 链表最大孪生和
描述：
在一个大小为 n 且 n 为 偶数的链表中，对于 0 <= i <= (n / 2) - 1 的 i
第 i 个节点（下标从 0 开始）的孪生节点为第 (n-1-i) 个节点 。
比方说，n = 4 那么节点 0 是节点 3 的孪生节点，节点 1 是节点 2 的孪生节点。
这是长度为 n = 4 的链表中所有的孪生节点。
孪生和定义为一个节点和它孪生节点两者值之和。
给你一个长度为偶数的链表的头节点 head ，请你返回链表的最大孪生和。

输入：
输入链表的节点数目是 [2, 10^5] 中的偶数。
1 <= Node.val <= 10^5
-1是链表结束符
输出：
输出孪生和

输入样例
5 4 2 1 -1
输出样例
6
*/

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElementType;

typedef struct Lnode{
    ElementType data;   //存储的数据
    struct Lnode *next; //指向节点的指针类型
} Lnode, *LinkList;

LinkList init_list()
{
    Lnode *L;
    L= (Lnode *)malloc(sizeof(Lnode));   //不存放数据的头节点;  
    L->next = NULL; 
    return L;
}

void tail_insert(Lnode *L, ElementType val)
{
    Lnode *p = NULL;
    p = L;
    while(p->next != NULL) 
    {
        p = p->next;
    }
    Lnode *newLode = (Lnode *)malloc(sizeof(Lnode));
    newLode->data = val;
    p->next = newLode; //让原来的表末元素指向现在的表末元素
    newLode->next = NULL;
}

int length_list(Lnode *L)
{
    int len = 0;    //列表长度

    Lnode *p = L->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

int twin_sum(Lnode *L, int len)
{
    int i;
    int j;
    int sum = 0;
    Lnode *p1 = L->next;
    Lnode *p2 = L;
    for(i=0; i<len/2; i++)
    {
        p2 = L;
        for(j=0; j<len-i; j++)
        {
            p2 = p2->next;
        }
        if(p1->data + p2->data >= sum)
            sum = p1->data+p2->data;
        p1 = p1->next;
    }

    return sum;
}

void main()
{
    Lnode *L = init_list();

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L, n);
        scanf("%d", &n);
    }

    printf("%d", twin_sum(L, length_list(L)));
}