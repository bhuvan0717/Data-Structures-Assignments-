#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct gym
{
    int count;
    char exe[100];
    struct gym *next;
};

typedef struct gym *NODE;

NODE insert_after(NODE head)
{
    NODE newn=NULL,cur=NULL;
    newn=(NODE)malloc(sizeof(struct gym));
    scanf("%d%s",&newn->count,newn->exe);
    newn->next=NULL;
    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        for(cur=head;cur->next!=NULL;cur=cur->next);
        cur->next=newn;
    }
    return(head);
}

void insert_end(NODE head)
  {
    char S[50]="benchpresses";
    NODE cur=head,nwen=NULL;
    nwen=(NODE)malloc(sizeof(struct gym));
    nwen->count=10;
    strcpy(nwen->exe,S);
    nwen->next=NULL;
    for(cur=head;cur->next!=NULL;cur=cur->next);
    cur->next=nwen;
    cur=head;
    while(cur!=NULL)
    {
        printf("%d %s ",cur->count,cur->exe);
        cur=cur->next;
    }
}
 NODE deletespecific(NODE head,NODE cur,NODE prev)
{
    if(cur==head)
    {
        head=cur->next;
        free(cur);
    }
    else
    {
        prev->next=cur->next;
        free(cur);
    }
    return(head);
}

void deleteselected(NODE head)
{
    char S[40]="pushups";
    NODE cur=head,prev=NULL;
    while(cur!=NULL)
    {
        if(strcmp(cur->exe,S)==0)
        {
            head=deletespecific(head,cur,prev);
        }
        prev=cur;
        cur=cur->next;
    }
    insert_end(head);
}

int main()
{
    NODE head=NULL;
    int n,i;
    scanf("%d",&n);
    if(n==5)
    {
        for(i=0;i<n;i++)
        {
           head=insert_after(head);
        }
        deleteselected(head);
    }
    else
    {
        printf("Vikram performs 5 exercises.");
    }
}
