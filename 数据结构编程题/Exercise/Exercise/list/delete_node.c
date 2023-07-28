/*
题目: 删除链表的倒数第 N 个结点
描述：
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
输入：
输入链表和要删除的n ，链表中结点的数目为 sz，
1 <= sz <= 30，0 <= Node.val <= 100，1 <= n <= sz
-1表示链表结束符
输出：
输出链表

输入样例
1 2 3 4 5 -1
2
输出样例
1 2 3 5
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
    int len;    //列表长度

    Lnode *p = L->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
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

void delete(Lnode *L, int t)
{
    Lnode *p = L;
    int len = length_list(L);
    for(int i=0; i<len-t; i++)
    {
        p = p->next;
    }
    p->next = p->next->next;

}

void main()
{
    Lnode *L = init_list();
    int t;

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L, n);
        scanf("%d", &n);
    }
    scanf("%d", &t);

    delete(L, t);
    traverse_list(L);
}