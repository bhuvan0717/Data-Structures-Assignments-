/*1) Write a modular C program to add two complex numbers using structures.*/
#include<stdio.h>

typedef struct complex
{
    float real, imag;
}COMP;

COMP read_complex(COMP c)
{
    printf("Enter real part: ");
    scanf("%f",&c.real);
    printf("Enter imaginary part: ");
    scanf("%f",&c.imag);
    return c;
}

void display_complex(COMP c)
{
    if(c.imag>=0)
        printf("%0.2f + %0.2f i\n",c.real,c.imag);
    else
        printf("%0.2f %0.2f i\n",c.real,c.imag);
}

COMP add_complex(COMP c1, COMP c2)
{
    COMP c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}

int main()
{
    COMP c1, c2,c3;
    printf("Enter a complex number 1 \n");
    c1 = read_complex(c1);
    printf("Enter a complex number 2 \n");
    c2 = read_complex(c2);
    printf("Complex number 1\n");
    display_complex(c1);
    printf("Complex number 2\n");
    display_complex(c2);
    c3=add_complex(c1,c2);
    printf("Addition of 2 complex numbers\n");
    display_complex(c3);
    return 0;
}
