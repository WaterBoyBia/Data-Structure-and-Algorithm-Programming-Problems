/*
题目: 合并两个链表
描述：
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

输入：
3 <= list1.length <= 10^4
1 <= a <= b < list1.length - 1
1 <= list2.length <= 10^4
-1作为链表结束符

输出：
输出链表

输入样例
0 1 2 3 4 5 -1 
3 
4 
1000000 1000001 1000002 -1 

输出样例
0 1 2 1000000 1000001 1000002 5
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
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

void traverse_list(Lnode *L)
{
    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

void insert(Lnode *L1, Lnode *L2, int start, int end)
{
    int cet;
    Lnode *p1 = L1->next;
    Lnode *p2 = L1->next;

    for(cet=0; cet < start-1; cet++)
    {
        p1 = p1->next;
    }
    for(cet=0; cet < end; cet++)
    {
        p2 = p2->next;
    }
    p1->next = L2->next;
    Lnode *temp = L2;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = p2->next;
}

void main()
{
    Lnode *L1 = init_list();
    Lnode *L2 = init_list();

    int start;
    int end;

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L1, n);
        scanf("%d", &n);
    }
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L2, n);
        scanf("%d", &n);
    }

    insert(L1, L2, start, end);
    traverse_list(L1);
}