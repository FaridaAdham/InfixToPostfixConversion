#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct
{
    char name[30];
    float value;
} variable;


variable v[50];
int counter=0;

float search(char c[10])
{
    int i;
    for(i=0; i<=counter; i++)
        if(strcmp(v[i].name,c)==0)
            return v[i].value;

}

float evaluate(char x,float op1,float op2)
{
    if(x=='+')
        return (op1+op2)*1.0;
    else if (x=='-')
        return (op1-op2)*1.0;
    else if (x=='*')
        return (op1*op2)*1.0;
    else if (x=='/')
        return (op1/op2)*1.0;
}
float evaluatepostfix(char a[30])
{
    stack1 answer;
    initialize1(&answer);

    char *token;
    float op1,op2;
    float value;
    token=strtok(a," ");
    while(token!=NULL)
    {
        if(isdigit(token[0]))
        {
            float y=atof(token);
            push1(&answer,y);
        }
        else if(token[0]=='+' || token[0]=='-' || token[0]=='*' ||token[0]=='/')
        {
            op2=pop1(&answer);
            op1=pop1(&answer);
            value=evaluate(token[0],op1,op2);
            push1(&answer,value);
        }
        else if(isalpha(token[0]))
        {
            float ch;
            ch=search(token);
            push1(&answer,ch);
        }

        token=strtok(NULL," ");

    }
    value=pop1(&answer);
    return value;
}
int priority(char c)
{
    switch(c)
    {
    case'+':
    case'-':
        return 0;
    case'*':
    case'/':
    case'%':
        return 1 ;
    case'(':
        return 2;
    }
}
int check(char c)
{
    if( c=='+' || c=='*' || c=='/' || c=='-' || c=='(' || c==')')
        return 0;
    else
        return 1;
}

int chst[30];
int y=0;

int check_struct(char c[10])
{
    int x;
    char d[10];
    for(x=0; x<counter; x++)
    {
        if(strcmp(v[x].name,c)==0)
        {
            strcpy(d,v[x].name);
            chst[y]=1;
            return 1;
        }
        else
            chst[y]=0;
        y++;

    }
    return 0;
}

int b;

int valid_name(char name[30],int x)
{
    int i,m;
    char y[20];
    int t;
    for(t=0;t<counter;t++)
    {
        if(strcmp(v[t].name,name)==0)
        return 0;

    }

    for(i=0; name[i]!='='; i++)
    {
        if(isdigit(name[i]) || isalpha(name[i]))
        {
            y[i]=name[i];
        }
        else
        {
            return 0;
        }
    }
    int k=i;
    b=++k;
    y[i]=NULL;
    strcpy(v[x].name,y);
    return 1;

}

char infix[20];

int valid_exp(char m[30])
{
    int a=0;
    int x;
    int g=0;
    char val[10];
    for(b; b<strlen(m); b++)
    {
        if(isdigit(m[b]) || m[b]=='+' || m[b]=='-' || m[b]=='/' || m[b]=='*' || m[b]==')' || m[b]=='(' || m[b]=='.')
            infix[a++]=m[b];
        else if(isalpha(m[b]))
        {
        g=0;

            while(isdigit(m[b])|| isalpha(m[b]))
            {
                val[g]=m[b];
                ++b;
                ++g;
            }
            b--;
            val[g]=NULL;
            if(check_struct(val)==1)
            {
                int l;
                for(l=0; l<strlen(val); l++)
                {
                    infix[a]=val[l];
                    ++a;
                }
            }

            else
                return 0;

        }
        else return 0;
    }
    infix[a]=NULL;

    return 1 ;
}

void print_postfix(char c[30])
{

    stack f;
    initialize(&f);
    stack1 answer;
    initialize1(&answer);
    float val;
    int i,n;
    char postfix[30];
    int h=0;
    for(i=0; i<strlen(infix); i++)
    {
        if(check(infix[i])==1)
        {
            char d=infix[i];
            postfix[h]=d;
        }
        else if(infix[i]==')')
        {
            while(!isempty(&f)&&top(&f)!='(')
            {
                postfix[h]=' ';
                postfix[++h]=pop(&f);

            }
            pop(&f);
        }

        else if (isempty(&f))
        {
            postfix[h]=' ';
            push(&f,infix[i]);
        }
        else
        {
            while(!isempty(&f) && priority(top(&f))>=priority(infix[i]) && top(&f)!='(')
            {
                postfix[h]=' ';
                postfix[++h]=pop(&f);
            }

            postfix[h]=' ';
            push(&f,infix[i]);

        }
        ++h;

    }
    while(!isempty(&f))
    {
        postfix[h]=' ';
        postfix[++h]=pop(&f);
    }
    ++h;
    postfix[h]=NULL;
    char postfixc[30];
    strcpy(postfixc,postfix);
    postfixc[strlen(postfixc)]=NULL;

    val=evaluatepostfix(postfix);
    printf("\n-->The Postfix Expression : %s \n \n",postfixc);
    printf("-->The Result Is : %s = %.3f \n",v[counter].name,val);

    v[counter].value=val;
    ++counter;

}
int main()
{
    char post[30];
    system("color f5");
    int how,d;
    printf("\n\t\t\t**THE INFIX/POSTFIX CALCULATOR** ^_^");
    printf("\n\t\t\t------------------------------------");
    printf("\n\t\t\t------------------------------------\n");
    printf("\nEnter The Number Of Infix/Postfix Expressions : \n\n");
    scanf("%d",&how);
    for(d=0; d<how; d++)
    {
        printf("\nPlease Enter The #%d Infix Expression : \n\n",d+1);
        scanf("%s",post);
        if(valid_name(post,counter)==1 && valid_exp(post)==1 )
        {
            print_postfix(infix);
        }
        else
        {
            printf("\n \nERROR !! \nPlease check the infix expression Or the variable names.\n");
            printf("\nPlease enter a valid infix expression : ");
            scanf("%s",post);
            if(valid_name(post,counter)==1 && valid_exp(post)==1 )
                print_postfix(post);
        }
    }

    printf("\n\t\t\t< SYMBOL TABLE >\n");
    printf("\t\t\t -------------- \n");
    int y;
    for(y=0; y<counter; y++)
    {
        printf("\t\t\t");
        printf(" %s",v[y].name);
        printf("  ");
        printf(" | ");
        printf("  ");
        printf("%.3f",v[y].value);
        printf("\n\t\t\t");
        printf("__________________");
        printf("\n");
    }
    printf("\n\t\t//** Thanks For Using Our Program **\\\\ ^_^");
    printf("\n\t       --------------------------------------------");
    printf("\n\t       --------------------------------------------\n");
    return 0;
}
