#include "stack.h"

void initialize(stack *s)
{
    s->top=0;
}
int isempty(stack *s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}
int isfull(stack *s)
{
    if(s->top==100)
        return 1;
    else
        return 0;
}

void push(stack *s,char value)
{
    s->items[s->top]=value;
    s->top++;
}
char pop(stack *s)
{
    char val;
    s->top--;
    val=s->items[s->top];
    return val;
}
char top(stack *s)
{
    char x=pop(s);
    push(s,x);
    return x;
}

void initialize1(stack1 *s)
{
    s->top=0;
}
int isempty1(stack1 *s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}
int isfull1(stack1 *s)
{
    if(s->top==100)
        return 1;
    else
        return 0;
}

void push1(stack1 *s,float value)
{
    s->num[s->top]=value;
    s->top++;
}

float pop1(stack1 *s)
{
    float val;
    s->top--;
    val=s->num[s->top];
    return val;
}

float top1(stack1 *s)
{
    float x=pop1(s);
    push(s,x);
    return x;
}
