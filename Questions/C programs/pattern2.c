#include<stdio.h>
void main()
{
	int n,i,j,k,spaces,stars=1;
	printf("Enter the number of rows:\n");
	scanf("%d",&n);
	spaces=n-1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=spaces-1;j++)
		{
			printf(" ");

		for(k=0;k<=n-spaces-1;k++)
		{
			printf("*");
		}
		}
		if(spaces>i)
		{
			spaces=spaces-1;
			stars=stars+2;
		}
		if(spaces<i)
		{
			spaces=spaces+1;
			stars=stars-2;
		}
		printf("\n");
	}
	
	
}
