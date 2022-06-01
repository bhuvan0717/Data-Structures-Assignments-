#include<stdio.h>
#include<stdlib.h>

struct coin
{
    int denom;
    struct coin *next;
};
typedef struct coin *NODE;

NODE arjun_head,bheem_head,temp,nnode,new_node;

NODE select_coin(NODE);
NODE remove_coin(NODE);
void display_coins(NODE);

int arjun_count=0,bheem_count=0,count=0;

int main()
{
    int i,n;
     arjun_head=NULL;
     bheem_head=NULL;
     printf("enter the number of coins to be selected by arjun and bheem\n");
     scanf("%d",&n);

     printf("select %d coins for arjun",n);
     for (i=1;i<=n;i++)
     {
         arjun_head=select_coin(arjun_head);
     }
     printf("select %d coins for bheem",n);
     for (i=1;i<=n;i++)
     {
         bheem_head=select_coin(bheem_head);
     }
     printf("\narjun coins are \n");
     display_coins(arjun_head);

      printf("\nbheem coins are \n");
     display_coins(bheem_head);

     printf("\ncoins with arjun");
     for (i=1;i<=n;i++)
     {
         arjun_head=remove_coin(arjun_head);
     }
     arjun_count=count;
     printf("\ncoins arjun has %d",arjun_count);
     printf("\nTotal coins with bheem");
     count=0;
     for (i=1;i<=n;i++)
     {
         bheem_head=remove_coin(bheem_head);
     }
     bheem_count=count;
     printf("\nTotal coins bheem has %d",bheem_count);

     if(arjun_count>bheem_count)
        printf("\narjun wins\n");
     else if(arjun_count<bheem_count)
        printf("\nbheem wins\n");
     else
        printf("\nboth wins");
}

NODE get_node()
{
    nnode=(NODE)malloc(sizeof(struct coin));
    if(nnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&nnode->denom);
        nnode->next=NULL;
    }
    return nnode;
}
NODE select_coin(NODE chead)
{
    new_node=get_node();
    if(chead==NULL)
    {
        chead=new_node;
    }
    else
    {
        new_node->next=chead;
        chead=new_node;
    }
    return (chead);
}
NODE remove_coin(NODE chead)
{

    if(chead==NULL)
    {
        printf("\n no coin to display\n");

    }
    else
    {
        printf("\n coin removed is %d \n",chead->denom);
        count=count+chead->denom;
        temp=chead;
        chead=chead->next;
        free(temp);
    }
    return (chead);
}
void display_coins(NODE chead)
{
    if(chead==NULL)
    {
        printf("no coin to display\n");
    }
    else
    {
        temp=chead;
        printf("coins are\n");
        while(temp!=NULL)
        {
            printf("%d \t ",temp->denom);
            temp=temp->next;
        }
    }
}

