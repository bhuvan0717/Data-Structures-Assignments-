#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void read_array(int a[],int n);
void add_m(int a[],int n,int m);
int main()
{
   int a[100],n,m;
    printf("Value of n:\n");
    scanf("%d",&n);
     printf("Value of m:\n");
    scanf("%d",&m);
    read_array(a,n);
    add_m(a,n,m);
    return 0;
}
void read_array(int a[],int n)
{   int i;
    printf("enter no.s\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void add_m(int a[],int n,int m)
{
    int i=0,j=0;
    for(i=0;i<n-m;i++)
    {
         int sum=0;
        for(j=i+1;j<m+i+1;j++)
    {
        sum=sum+a[j];
    }
     printf("for position %d, sum= %d\n",i+1,sum);
    }
}
