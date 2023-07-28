/*
题目: 反转链表Ⅱ
描述
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回反转后的链表 。

输入：
链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
-1表示链表结束符

输出：
输出链表

输入样例
1 2 3 4 5 -1 2 4 
输出样例
1 4 3 2 5
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

void head_insert(Lnode *L, ElementType val)
{
    Lnode *p = (Lnode *)malloc(sizeof(Lnode));
    p->data = val;
    p->next = L->next;  //先让P指向下一个元素，否则顺序反过来会访问不到
    L->next = p; 
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

LinkList reverse(Lnode *L, int start, int end)
{
    Lnode *left = L;
    Lnode *right = L;
    Lnode *L2 = init_list();
    int n;
    int i;

    for(i=0; i<start-1; i++)
    {
        left = left->next;
    }
    for(i=0; i<end+1; i++)
    {
        right = right->next;
    }

    Lnode *p = left->next;
    for(int j=0; j<end-start+1; j++)
    {
        n = p->data;
        head_insert(L2, n);
        p = p->next;
    }

    left->next = L2->next;
    Lnode *p2 = L2;
    while(p2->next)
    {
        p2 = p2->next;
    }
    p2->next = right;

    return L;
}

void main()
{
    Lnode *L = init_list();

    int start;
    int end;

    ElementType n;
    scanf("%d", &n);
    while(n != -1)
    {
        tail_insert(L, n);
        scanf("%d", &n);
    }
    scanf("%d", &start);
    scanf("%d", &end);

    traverse_list(reverse(L, start, end));
}