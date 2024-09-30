#include<stdio.h>
int main()
{
	int rows,i,j,k;
	printf("Enter rows:\n");
	scanf("%d",&rows);
	for(i=rows;i>0;i--)
	{
		for(j=1;j<=rows-i;j++)
		{
			printf(" ");
			for(k=1;k<=2*j-1;k++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
