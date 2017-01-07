#include<stdio.h>

int add_func(int n, int &sum)
{
	n && add_func(n-1,sum);
	return (sum += n);
}

int main()
{
	int n = 100;
	int sum = 0;
	add_func(n,sum);
	printf("%d",sum);
	return sum;
}
