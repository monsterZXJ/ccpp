#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node * PNode;
typedef int Item;
typedef struct node
{
    Item data;
    PNode down;
}Node;
typedef struct stack
{
    PNode top;
    int size;
}Stack;

Stack *InitStack();
int IsEmpty(Stack *ps);
PNode Push(Stack *ps,Item item);
PNode Pop(Stack *ps,Item *pitem);
PNode GetTop(Stack *ps,Item *pitem);

Stack *InitStack()
{
    Stack *ps = (Stack *)malloc(sizeof(Stack));
    if(ps!=NULL)
    {
        ps->top = NULL;
        ps->size = 0;
    }
    return ps;
}

int IsEmpty(Stack *ps)
{
    if(ps->top == NULL && ps->size == 0)
        return 1;
    else
        return 0;
}

PNode Push(Stack *ps,Item item)
{
    PNode pnode = (PNode)malloc(sizeof(Node));
    if(pnode != NULL)
    {
        pnode->data = item;
        pnode->down = GetTop(ps,NULL);
        ps->size++;
        ps->top = pnode;

    }
    return pnode;
}

PNode Pop(Stack *ps,Item *pitem)
{
    PNode p = ps->top;
    if(IsEmpty(ps)!=1&&p!=NULL)
    {
        if(pitem!=NULL)
            *pitem = p->data;
        ps->size--;
        ps->top = ps->top->down;
        free(p);
    }
    return ps->top;
}

PNode GetTop(Stack *ps,Item *pitem)
{
    if(IsEmpty(ps)!=1&&pitem!=NULL)
    {
        *pitem = ps->top->data;
    }
    return ps->top;
}


int main(void)
{
    Stack *ps = InitStack();
    int i,item,len,num;
    printf("栈的长度为:");
    scanf("%d",&len);

    printf("将数字依次入栈：\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&num);
        Push(ps,num);
    }

    printf("\n\n");
    printf("将数字依次出栈：\n");

     for(i=0;i<len;i++)
    {
        Pop(ps,&item);
        printf("%d ",item);
    }
    return 0;
}

