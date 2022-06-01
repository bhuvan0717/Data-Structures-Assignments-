#include<stdio.h>
#include<stdlib.h>
typedef struct placement
{
    char name[20],cname[20];
    int year,pack;
    struct placement *next;
}*NODE;
NODE get_details();
NODE insert_sort(NODE);
NODE display(NODE);
NODE display_2020(NODE);
NODE display_high(NODE);
void main()
{
    NODE head=NULL;
    int x;
    while(1)
    {
        printf("Enter the choice\n");
        printf("1.Insert 2.Display 3.Display 2020 4.Display Highest 5.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: head=insert_sort(head);
                    break;
            case 2: printf("Details are:\n");
                    printf("Name\tCompany Name\tPassed Year\tPackage\n");
                    head=display(head);
                    break;
            case 3: printf("Students who passed in 2020 are\n");
                    printf("Name\tCompany Name\tPassed Year\tPackage\n");
                    head=display_2020(head);
                    break;
            case 4: printf("Highest Package\n");
                    printf("Name\tCompany Name\tPassed Year\tPackage\n");
                    head=display_high(head);
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid Choice!");
                    break;
        }
    }
}
NODE get_details()
{
    NODE temp;
    temp=malloc(sizeof(NODE));
    if(temp==NULL)
    {
        return NULL;
    }
    else
    {
        printf("Enter Name\tCompany Name\tPassed year\tPackage\n");
        scanf("%s\t%s\t%d\t%d",temp->name,temp->cname,&temp->year,&temp->pack);
        temp->next=NULL;
        return temp;
    }
}
NODE insert_sort(NODE head)
{
    NODE newn,cur,prev;
    newn=get_details();
    if(newn==NULL)
    {
        printf("Node not created\n");
        return NULL;
    }
    else if(head==NULL)
    {
        return newn;
    }
    if(head->pack<newn->pack)
    {
        newn->next=head;
        return newn;
    }
    cur=head->next;
    prev=head;
    while(cur!=NULL)
    {
        if(head->pack<newn->pack)
        {
            newn->next=cur;
            prev->next=newn;
            return head;
        }
        prev=cur;
        cur=cur->next;
    }
    prev->next=newn;
    return head;
}
NODE display(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("List Empty\n");
        return head;
    }
    cur=head;
    while(cur!=NULL)
    {
        printf("%s\t%s\t\t%d\t%d\n",cur->name,cur->cname,cur->year,cur->pack);
        cur=cur->next;
    }
    return head;
}
NODE display_2020(NODE head)
{
    NODE cur;
    int i;
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    cur=head;
    while(cur!=NULL)
    {
        if(cur->year==2020)
        {
            printf("%s\t%s\t\t%d\t%d\n",cur->name,cur->cname,cur->year,cur->pack);
            i++;
        }
        cur=cur->next;
    }
    if(i=0)
    {
        printf("No students passed out in year 2020\n");
        return head;
    }
}
NODE display_high(NODE head)
{
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("%s\t%s\t\t%d\t%d\n",head->name,head->cname,head->year,head->pack);
    return head;
}
