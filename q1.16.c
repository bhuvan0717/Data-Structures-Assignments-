#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void reverse_array(int [],int);
void print_array(int [],int );

int main()
{
    int n;
    int a[100];
    printf("\nEnter array size : \t");
    scanf("%d",&n);
    read_array(a,n);
    print_array(a,n);
    reverse_array(a,n);
    print_array(a,n);
    return 0;
}
void read_array(int a[],int n)
{
    int i;
    printf("\nEnter %d elements  : ",n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int n)
{
    int i;

    printf("\nThe array elements are : \n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t",a[i]);
    }
}
void reverse_array(int a[],int n )
{
    int i;
    int temp;
    for(i = 0 ; i < n/2 ; i++)
    {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}

