//题目：只用一个辅助栈，实现栈顶向栈底由大到小排序。

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include"SqStack.c"

void sort_stack(SqStack *S, SqStack *sorted_stack)
{
    while(!is_empty(S))
    {
        int val;
        pop_stack(S, &val);

        if(val <= get_top(sorted_stack))
            push_stack(sorted_stack, val);
        else
        {
            int i = 0;  //需要调整的元素的个数
            while(!is_empty(sorted_stack) && get_top(sorted_stack)<val)
            {
                int temp1;
                pop_stack(sorted_stack, &temp1);
                push_stack(S, temp1);
                i++;
            }
            push_stack(sorted_stack, val);
            for(int j=0; j<i; j++)
            {
                int temp2;
                pop_stack(S, &temp2);
                push_stack(sorted_stack, temp2);
            } 
        }
    }
}


void main()
{
    SqStack S;
    SqStack sorted_stack;
    init_stack(&S);
    init_stack(&sorted_stack);

    push_stack(&S, 2);
    push_stack(&S, 1);
    push_stack(&S, 4);
    push_stack(&S, 5);
    push_stack(&S, 7);
    push_stack(&S, 7);
    push_stack(&S, 3);
    push_stack(&S, 4);


    traverse_stack(&S);

    sort_stack(&S, &sorted_stack);

    traverse_stack(&sorted_stack);
}