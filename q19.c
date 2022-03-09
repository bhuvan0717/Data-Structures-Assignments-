#include <stdio.h>
#include <stdlib.h>

void read_array(int [],int );
void sort_array(int [],int );
void print_array(int [],int );

int main()
{
    int a[100];
    int n;
    printf("\nEnter the array size : \n ");
    scanf("%d",&n);
    read_array(a,n);
    printf("\nDisplaying array before sorting : \n ");
    print_array(a,n);
    sort_array(a,n);
    printf("\nDisplaying array after sorting  : \n ");
    print_array(a,n);

    return 0;
}
void read_array(int a[],int n)
{
    int i;
    printf("\nEnter %d array elements : \n ",n);
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
void sort_array(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<(n-1);i++)
    {
       for(j=0;j<(n-i-1);j++)
       {
           if(a[j]>a[j+1])
           {
               temp = a[j];
               a[j] = a[j+1];
               a[j+1] = temp;
           }
       }
    }
}
