#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[25],gender[7];
    int age,emp_id,salary;
    struct employee *next;
};

typedef struct employee *NODE;

NODE getnode()
{
	NODE newnode;
	newnode=(NODE)malloc(sizeof(struct employee));
	if(newnode==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	newnode->next = NULL;
	return newnode;
}

NODE read_details()
{
    NODE temp;
    temp = getnode();
    printf("Enter name, employee id, salary, gender and age\n");
    scanf("%s %d %d %s %d",temp->name,&temp->emp_id,&temp->salary,temp->gender,&temp->age);
    return temp;
}

NODE insert_sort(NODE head)
{
    NODE temp=read_details();
    if(head==NULL)
    {
        head=temp;
    }
    else if(head->age < temp->age)
    {
            temp->next=head;
            head=temp;
    }
    else
    {
        NODE cur=head, prev=NULL;
        while(cur->age > temp->age && cur->next !=NULL)
         {
            prev=cur;
            cur=cur->next;
        }
        if(cur->next==NULL && cur->age > temp->age)
        {
            cur->next=temp;
        }
        else
        {
            prev->next=temp;
            temp->next=cur;
        }
    }
    return head;
}


void display_all(NODE head)
{
    NODE cur=head;
    if(cur==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nEmployee Details\n");
        while(cur!=NULL)
        {
            printf("%s\t%d\t%d\t%s\t%d\n",cur->name,cur->emp_id,cur->salary,cur->gender,cur->age);
            cur=cur->next;
        }
    }
}

NODE insert_end(NODE head)
{
    NODE newnode=NULL, cur=NULL;
    newnode = read_details();
    if(head == NULL)
    {
        return newnode;
    }
    else
    {
        cur=head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
    return head;
}

NODE insert_front(NODE head)
{
    NODE newnode;
    newnode = read_details();
    if(head == NULL)
    {
        return newnode;
    }
    newnode->next = head;
    head = newnode;
    return head;
}

int count(NODE head)
{
    NODE temp;
    temp = head;
    int cnt=0;
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
    }
    return cnt;
}

NODE split(NODE head1,NODE head2,int count)
{
    int i;
    NODE cur,prev;
    if(head1==NULL)
    {
        return head1;
    }
    cur=head1;
    prev=NULL;
    while(i!=count/2)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    prev->next=NULL;
    head2=cur;
    return head2;
}

NODE merged_list(NODE head1,NODE head2)
{
    NODE c;
    c=head1;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=head2;
    return head1;
}

int main()
{
    NODE head1=NULL,head2=NULL;
    int ch,cnt;
    while(1)
    {
        printf("\n---Employee Details---\n");
        printf("1:Insert Sorted in descending order 2:Display 3:Insert youngest employee 4:Insert oldest employee 3:Splitting of list 4:Merge of split lists 5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head1=insert_sort(head1);
                    break;
            case 2:display_all(head1);
                    display_all(head2);
                    break;
            case 3:head1 = insert_end(head1);
                            break;
            case 4: head1 = insert_front(head1);
                            break;
            case 5:cnt=count(head1);
                    head2=split(head1,head2,cnt);
                    printf("\nList 1");
                    display_all(head1);
                    printf("\nList 2");
                    display_all(head2);
                    break;
            case 6:printf("Merged List\n");
                    head1=merged_list(head1,head2);
                    head2=NULL;
			        break;
            case 7:exit(0);
                    break;
            default: printf("Invalid choice\n");
                    break;
        }
    }
    return 0;
}
