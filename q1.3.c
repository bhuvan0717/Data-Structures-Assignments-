#include <stdio.h>
#include <stdlib.h>


struct employee
{
    int basic;


    int experience;
    float salary;
}employee[50];


void read_employee(struct employee[] ,int);
void calculate_salary(struct employee[] , int);

int main()
{
    int n;

    printf("Enter the total number of employees : \n");
    scanf("%d",&n);
    read_employee(employee,n);

    return 0;
}
void read_employee(struct employee employee[50],int b)
{
    int i=1;
    int j = b;


    printf("\n Enter %d employee details : \n ",j);
    while(j!=0)
    {
        printf("\n Enter experience of employee %d   : ",i);
        scanf("%d",&employee->experience);


        j--;
        i++;

    }
    calculate_salary(employee,b);

}
void calculate_salary(struct employee employee[50], int b)
{

    if(employee -> experience >= 5 || employee -> experience <= 7)
    {
        employee->basic = 10600;
        employee->salary = employee->basic + (employee->basic * 0.10f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }


    if(employee -> experience>=8 || employee->experience<=10)
    {
        employee->basic = 21300;
        employee->salary = employee->basic + (employee->basic * 0.20f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }
    if(employee->experience>10)
    {
        employee->basic = 32100;
        employee->salary = employee->basic + (employee->basic * 0.30f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }


}



    /*for(i=0;i<b;i++,j++)
    {
        printf("\nSalary details of employee %d",j);
        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }*/

