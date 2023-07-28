/*
题目: 删除排序链表中的重复元素
描述:
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回已排序的链表 
输入:
输入已排序的链表，链表中节点数目在范围 [0, 300] 内，-100 <= Node.val <= 100，题目数据保证链表已经按升序排列
-1表示链表结束符
输出:
输出已排序的链表

输入样例
1 1 2 3 3 -1

输出样例
1 2 3
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
    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }    
}

bool is_Empty(Lnode *L)
{
    if(L->next == NULL)
        return true;
    else
        return false;
}

void function(Lnode *L)
{
    Lnode *p = L->next;

    if(is_Empty(L))
        return;
    else
    {
        while(p->next && p)
    {
        Lnode *temp = p->next;
        if(p->data == temp->data)
        {
            p->next = temp->next;
        }
        else
            p = p->next;
    } 
    }
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

    function(L);
    traverse_list(L);
}