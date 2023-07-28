/*
题目: 移除链表元素
描述：
给你一个链表的头节点 head 和一个整数val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点
输入：
输入链表和val，列表中的节点数目在范围 [0, 10^4] 内，1 <= Node.val <= 50，0 <= val <= 50
-1表示链表结束符
输出：
输出移除元素的链表

输入样例
1 2 6 3 4 5 6 -1 6 
输出样例
1 2 3 4 5
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

LinkList function(Lnode *L, ElementType val)
{
    Lnode *p = L->next;
    while(p->data == val)
    {
        if(p->next != NULL)
        {
            L->next = p->next;
            p = L->next;
        }
        else
        {
            L->next = NULL;
            return L;
        }
    }

    if(is_Empty(L))
        return L;
    else
    {
        while(p->next && p)
        {
            Lnode *temp = p->next;
            if(temp->data == val)
            {
                p->next = temp->next;
            }
            else
                p = p->next;
        } 
    }
    return L;
}

void main()
{
    Lnode *L = init_list();

    ElementType n;
    ElementType val;
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L, n);
        scanf("%d", &n);
    }

    scanf("%d", &val);
    L =function(L,val);
    traverse_list(L);
}