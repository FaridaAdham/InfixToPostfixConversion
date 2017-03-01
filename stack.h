#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct
{
    char items[30];
    int top;
} stack;

typedef struct
{
    float num[30];
    int top;
} stack1;

void initialize(stack *s);
int isempty(stack *s);
int isfull(stack *s);
void push(stack *s,char value);
char pop(stack *s);
char top(stack *s);

void initialize1(stack1 *s);
int isempty1(stack1 *s);
int isfull1(stack1 *s);
void push1(stack1 *s,float value);
float pop1(stack1 *s);
float top1(stack1 *s);

#endif // STACK_H_INCLUDED
