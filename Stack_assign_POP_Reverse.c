#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} *NODE;

NODE getNODE(int item)
{
    NODE n = (NODE)malloc(sizeof(struct stack));
    if(n==NULL)
    {
        printf("Node is not created.\n");
        exit(0);
    }
    n->data = item;
    n->next = NULL;
    return n;
}

NODE push(NODE top, int item)
{
    NODE temp = getNODE(item);
    if(top==NULL)
        return temp;
    NODE cur = top;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return top;
}

NODE pop(NODE top)
{
    if(top==NULL)
    {
        printf("Shelf is empty.\n");
    }
    else
    {
        NODE tmp = top;
        top = top->next;
        //printf("%d\n", tmp->data);
        free(tmp);
    }
    return top;
}

void display_stack(NODE top)
{
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        NODE cur = top;
        int n, r, s;
        while(cur != NULL)
        {
            n = cur->data;
            s = 0;
            while(n!=0)
            {
                r = n%10;
                s = s*10 + r;
                n = n/10;
            }
            printf("%d ", s);
            cur = cur->next;
        }
        printf("\n");
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, data, n_pop;
    NODE top = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &data);
        top = push(top,data);
    }
    scanf("%d", &n_pop);
    for(int i=0; i<n_pop; i++)
        top = pop(top);
    display_stack(top);
    return 0;
}

