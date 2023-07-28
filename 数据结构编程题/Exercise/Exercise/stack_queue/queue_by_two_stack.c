//题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。队列中的元素为int类型。

/*
核心思想：模拟出队列先进先出的数据结构
假设有两个栈S1和S2，S1模拟栈的数据插入，当需要模拟出队列操作时，S1栈中的A,B,C,D会按照D,C,B,A的顺序进入栈S2。 
只要S2栈不为空，出队列操作就可以通过S2的出栈操作来实现。
若S2栈为空，则继续从S1栈导入数据。
若两个栈都为空，即整个队列为空。
*/

//数据结构定义可以放在另一个文件中，使用C语言include函数的文件包含（相当于复制粘贴）

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include"SqStack.c"

typedef struct Queue
{
    SqStack S1;
    SqStack S2;
} Queue;

bool is_queue_full(Queue *q)
{
    if(is_full(&(q->S1)))
        return true;
    else
        return false;
}

bool push(Queue *q, int val)
{
    if(is_queue_full(q))
        return false;
    else
    {
        push_stack(&(q->S1), val);
    }
}

bool is_queue_empty(Queue *q)
{
    if(is_empty(&(q->S1)))
        return true;
    else
        return false;
}

bool pop(Queue *q, int *val)
{
    if(!is_empty(&(q->S2)))
    {
        pop_stack(&(q->S2), val);
    }
    else {
        while (!is_empty(&(q->S1)))
        {
            pop_stack(&(q->S1), val);
            push_stack(&(q->S2), *val);
        } 
        pop_stack(&(q->S2), val);
    }
}

void main()
{
    Queue q;
    init_stack(&(q.S1));
    init_stack(&(q.S2));
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    int val;
    pop(&q, &val);
    printf("%d\n",val);
    pop(&q, &val);
    printf("%d\n",val);
    push(&q, 4);
    pop(&q, &val);
    printf("%d\n",val);
    pop(&q, &val);
    printf("%d\n",val);
}


 

