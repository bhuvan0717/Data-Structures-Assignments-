#include<stdio.h>
#include<stdlib.h>

typedef struct football_team
{
    char name[20];
    char position[20];
    int jersey_no;
    int age;
    struct football_team *link;
}*NODE;

NODE getnode()
{
	NODE t;
	t=(NODE)malloc(sizeof(struct football_team));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	t->link = NULL;
	return t;
}

NODE read_details()
{
    NODE temp;
    temp = getnode();
    scanf("%s %s %d %d",temp->name,temp->position,&temp->age,&temp->jersey_no);
    return temp;
}

NODE insert_end(NODE head)
{
    NODE newn=NULL, cur=NULL;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    else
    {
        cur=head;
        while(cur->link != NULL)
            cur = cur->link;
        cur->link = newn;
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head == NULL)
    {
        printf("TEAM List is Empty\n");
    }
    else
    {
        cur=head;
        printf("Team details\n");
        printf("Name Position Age Jersey Number\n");
        printf("head-> ");
        while(cur != NULL)
        {
            printf("%s %s %d %d ->",cur->name,cur->position,cur->age,cur->jersey_no);
            cur = cur->link;
        }
        printf("NULL\n");
    }
}

NODE replace_specific(NODE head)
{
    NODE prev=NULL, cur=head;
    printf("Enter the details of the player who will come in as replacement\n");
    NODE temp = read_details();
    int n;
    printf("Enter jersey number of player who has to be replaced?\n");
    scanf("%d",&n);
    if(head == NULL)
    {
        printf("Team List is Empty\n");
    }
    if(head->link == NULL && n==cur->jersey_no)
    {
        printf("Replaced player = %s %s %d %d\n", head->name,head->position,head->age,head->jersey_no);
        free(head);
        head=temp;
        return head;
    }
    if(n==cur->jersey_no)
    {
        cur=head;
        head = head->link;
        printf("Replaced player = %s %s %d %d\n", cur->name,cur->position,cur->age,cur->jersey_no);
        free(cur);
        head=temp;
        return head;
    }
    while(cur != NULL)
    {
        if(n==cur->jersey_no)
        {
            break;
        }
        else
        {
            prev= cur;
            cur= cur->link;
        }
    }
    if(cur->link==NULL)
    {
        printf("Player with jersey number %d not found!",n);
    }
    prev->link = temp;
    temp->link = cur->link;
    printf("Replaced player = %s %s %d %d\n", cur->name,cur->position,cur->age,cur->jersey_no);
    free(cur);
    return head;
}

int main()
{
    int ch,n;
    NODE head=NULL;
    while(1)
    {
        printf("\n---Football Team---\n");
        printf("1:Insert team details 2:Display 3:Replace Player 4:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Number of players:");
                scanf("%d",&n);
                printf("Enter name, position, age, jersey number\n");
                for(int i=0;i<n;i++)
                {
                    head=insert_end(head);
                }
            case 2:display_list(head);
                    break;
            case 3:head=replace_specific(head);
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid choice");
                    break;
        }
    }
    return 0;
}
