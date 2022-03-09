#include <stdio.h>
#include <stdlib.h>
void read_array(int [], int);
void print_array(int [], int);
void find_key(int [] , int);

int main()
{
    int arr[100];
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    read_array(arr,n);
    find_key(arr,n);

    return 0;
}
void read_array(int a[], int b)
{
	int i;
	printf("Enter %d Array elements : \n",b);

	for(i=0;i<b;i++)
      {
	   scanf("%d",&a[i]);
	}

}
void print_array(int a[], int b)
{
	int i;
	for(i=0;i<b;i++)
      {
	   printf("%d\t",a[i]);
	}

}
void find_key(int a[] , int b)
{
    int i,j,key;
    j=0;

    printf("\nEnter the key number : ");
    scanf("%d",&key);
    for(i=0;i<b;i++)
    {
        if(a[i]==key)
        {
            j=i+1;
            printf("\n The key number is present in the given array and is present in the %d position \n",j);

        }
    }

    print_array(a,b);
}
