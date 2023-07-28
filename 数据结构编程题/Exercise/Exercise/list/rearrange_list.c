/*
题目: 重排链表
描述：
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
输入：
输入链表的长度范围为 [1, 5 * 10^4]
1 <= node.val <= 1000
-1表示链表结束符
输出：
输出重排链表

输入样例
1 2 3 4 5 -1 

输出样例
1 5 2 4 3
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

void traverse_list(Lnode *L)
{
    Lnode *p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d ", p->data);
    }
}

LinkList rearrange(Lnode *L, int len)
{
    int i;
    int j;
    int val;

    Lnode *p = L->next;

    Lnode *result = L;

    int times = 1;  //确定每一次是哪个组合

    if(len%2 == 1)
    {
        for(i=0; i<(len-1)/2; i++)
        {
            p = L->next;
            for(j=0; j<len-times; j++)
            {
                p = p->next;
            }
            result->next = p;
            result = result->next;

            p = L->next;
            for(j=0; j<len-(len-times); j++)
            {
                p = p->next;
            }
            result->next = p;
            result = result->next;

            times++;
        }
            
    }
    if(len%2 == 0)
    {
        for(i=0; i<(len-2)/2; i++)
        {
            p = L->next;
            for(j=0; j<len-times; j++)
            {
                p = p->next;
            }
            result->next = p;
            result = result->next;

            p = L->next;
            for(j=0; j<len-(len-times); j++)
            {
                p = p->next;
            }
            result->next = p;
            result = result->next;

            times++;
        }

        p = p->next;
        result->next = p;

    }
    
    return result;
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

    int len = length_list(L);
    traverse_list(rearrange(L, len));
}