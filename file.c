#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE*fp;
    fp=fopen("f.txt","w");
    if (fp=='\0')
    {

        printf("error in opening file");
        exit(0);

    }
    int d=0;
    fprintf(fp,"%d",d);
    int i;
    fscanf(fp,"%d" ,&i);
    printf("data in the file is =%d\n",i);
    fclose(fp);
    return(0);
}

