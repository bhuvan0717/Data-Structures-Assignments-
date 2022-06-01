/*
The government of India is collecting citizens' information by using "cowin" web application to
provide the covid vaccine.
Use the below structure to implement the functions.
struct address
{
 int house_no;
 char street_name[20];
 char city[20];
};
struct details
{
char name[20];
 int age;
 struct address adr;
};
a) Read and display
b) Display the details of citizens who are 18 to 44
c) Display the details of citizens who stays in Hubballi.
Note: a) Use Nested structure
 b) Use Nested structure and Pointer
 */

#include<stdio.h>
#include<string.h>
struct address
{
 int house_no;
 char street_name[20];
 char city[20];
};
struct details
{
 char name[20];
 int age;
 struct address adr;
};
struct address read_address(struct address a)//reading address details
{
    printf("Enter House number\n");
    scanf("%d",&(a.house_no));
    printf("Enter Street Name\n");
    scanf("%s",(a.street_name));
    printf("Enter City Name\n");
    scanf("%s",(a.city));
    return a;
}
void read_details(struct details *a,int n)//to read all deatils
{
    printf("ENTER DETAILS\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter your name\n");
        scanf("%s",(a+i)->name);
        printf("Enter your age\n");
        scanf("%d",&(a+i)->age);
        (a+i)->adr=read_address((a+i)->adr);
    }
}
void display_address(struct address a)//function to display address
{
    printf("House number:%d\nStreet name:%s\nCity name:%s\n\n",a.house_no,a.street_name,a.city);
}
void display_details(struct details *d,int n)//to display all details
{
    for(int i=0;i<n;i++)
    {
        printf("\n Details of Enrolled User %d\n\n",(i+1));
        printf("Name:%s\nAge:%d\n",(d+i)->name,(d+i)->age);
        display_address((d+i)->adr);
    }
}
void display_hubbali(struct details *d,int n)//to display people of Hubbali
{
    printf("\nDetails of people living in Hubbali are:\n\n");
    for(int i=0;i<n;i++)
    {
        if(strcmp(((d+i)->adr.city),"Hubbali")==0)
        {
            printf("Name:%s\nAge:%d\n",(d+i)->name,(d+i)->age);
            display_address((d+i)->adr);
        }
    }
}
void display_18_44(struct details *d,int n)//to display details of people of age 18-44
{
    printf("\n\nDetails of people b/w age 18-44 are\n\n");
    for(int i=0;i<n;i++)
    {
        if(((d+i)->age)>=18 && ((d+i)->age)<=44)
        {
            printf("Name:%s\nAge:%d\n",(d+i)->name,(d+i)->age);
            display_address((d+i)->adr);
        }
    }
}
void main()
{
    int n;
    printf("Enter number of people\n");
    scanf("%d",&n);
    struct details d[n];
    read_details(d,n);
    int choice;
    printf("Enter\n1. to display details of all users\n2. to display people of Hubbali\n3. To display people from age 18-44\n\n");
    scanf("%d",&choice);
    if(choice==1)
        display_details(d,n);
    else if(choice == 2)
        display_hubbali(d,n);
    else if(choice == 3)
        display_18_44(d,n);
    else
        printf("Wrong choice\n");
}
