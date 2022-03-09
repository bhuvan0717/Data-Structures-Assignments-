#include <stdio.h>
#include <stdlib.h>
void read_array(int [] , int );
void disp_array(int [] , int );
void p_freq(int [] , int );
void n_freq(int [] , int );
int main()
{
    int arr[100];
    int n;
    printf("Enter the array size: \n ");
    scanf("%d",&n);
    read_array(arr,n);
    disp_array(arr,n);

    p_freq(arr,n);
    n_freq(arr,n);

    return 0;
}
void read_array(int a[] , int b )
{
    int i;
    printf("\n Enter %d Array elements : \n",b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
}
void disp_array(int a[] , int b)
{
    int i;
    printf("\n Displaying  %d Array elements : \n",b);
    for(i=0;i<b;i++)
    {
        printf("%d  \t",a[i]);
    }

}
void n_freq(int a[] , int b)
{
    int i,neg;
    neg=0;
    for(i=0;i<b;i++){
        if(a[i]<0)
        {
            neg++;

        }

    }
    printf("\n Negative number count :  %d ",neg);

}
void p_freq(int a[] , int b)
{
    int i,pos;
    pos=0;
    for(i=0;i<b;i++){
        if(a[i]>0)
        {
            pos++;

        }

    }
    printf("\n Positive number count :  %d ",pos);

}
