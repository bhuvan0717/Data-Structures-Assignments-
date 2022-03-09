#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void print_array(int [],int );
void exchange_arrays(int [],int [],int );


int main()
{
    int n;
    int a[100],b[100];
    printf("Enter array elements : ");
    scanf("%d",&n);
    printf("\nEnter first array : \n");
    read_array(a,n);
    printf("\nEnter second array : \n");
    read_array(b,n);
    printf("\n Displaying arrays before swapping : \n");
    printf("\n First array : \n");
    print_array(a,n);
    printf("\n Second array : \n");
    print_array(b,n);
    exchange_arrays(a,b,n);
    printf("\n \n Results after swapping arrays : \n");
    printf("\n First array : \n");
    print_array(a,n);
    printf("\n Second array : \n");
    print_array(b,n);
    return 0;
}

void read_array(int a[],int n)
{
    int i;
    printf("\nEnter %d array elements : ",n);


    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%d\t",a[i]);
    }
}

void exchange_arrays(int a[],int b[],int n)
{
    int i;
    int temp[n];
    for(i=0;i<n;i++)
    {
        temp[i]= a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}
