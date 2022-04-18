#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	int n,i;
	double *a;//a[]={0};
	if(argc<2)
	{
		printf("How many elements you want to display:");
		scanf("%d",&n);
	}
	else
	{
		n=atoi(argv[1]);
	}
	a[0]=0;a[1]=1;
        printf("The series is: %.0f %.0f", a[0],a[1]);
        for(i=2;i<n;i++)
	{
		a[i]=a[i-2]+a[i-1];
		printf(" %.0f", a[i]);
	}

		printf("\n");
}
