/*
题目：合并两个有序链表
描述：
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

输入：
输入两个顺序表l1，l2，l1和l2均按非递减顺序排列，两个链表的节点数目范围是 [0, 50]，-100 <= Node.val <= 100
-1表示链表结束符

输出：
输出合并后的顺序表

输入输出样例：
输入 
1 2 4 -1
1 3 4 -1
输出 
1 1 2 3 4 4
*/

#include<stdio.h>
#include <stdlib.h>
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
    Lnode *p = L->next;
    while(p->next)
    {

        printf("%d ", p->data);
        p = p->next;
    }    
    printf("%d", p->data);
}

LinkList merge(Lnode *L1, Lnode *L2)
{
    if(!L1->next)
        return L2;
    if(!L2->next)
        return L1;

    L1 = L1->next;
    L2 = L2->next;
    Lnode *headNode = init_list();
    if(L1->data <= L2->data)
    {
        headNode->next = L1;
        L1 = L1->next;
    }  
    else
    {
        headNode->next = L2;
        L2 = L2->next;
    }

    Lnode *p = headNode->next;
    while(L1 && L2)
    {
        if(L1->data <= L2->data)
        {
            p->next = L1;
            L1 = L1->next;
        } 
        else
        {
            p->next = L2;
            L2 = L2->next;
        }  
        p = p->next;
    }

    if(L1)
    {
        p->next = L1;
    }
    if(L2)
    {
        p->next = L2;
    }

    return headNode;
}

void main()
{
    Lnode *L1 = init_list();
    Lnode *L2 = init_list();

    ElementType n1;
    scanf("%d", &n1);
    while(n1 != -1)
    {
        tail_insert(L1, n1);
        scanf("%d", &n1);
    }
    ElementType n2;

    scanf("%d", &n2);
    while(n2 != -1)
    {
        tail_insert(L2, n2);
        scanf("%d", &n2);
    }

    Lnode *L = merge(L1, L2);
    traverse_list(L);
}


