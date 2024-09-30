#include<stdio.h>
void main()
{
	int num;
	int d1, d2, d3, d4, d5, rev;
	printf("Enter number:");
	scanf("%d", &num);
	d1 = num % 10;
	d2 = (num / 10) % 10;
	d3 = (num / 100) % 10;
	d4 = (num / 1000) % 10;
	d5 = (num / 10000);
	rev = d1 * 10000 + d2 * 1000 + d3 * 100 + d4 * 10 + d5;
	printf("\nReverse of %d is:%d", num, rev);
}