#include<stdio.h>
#include<string>
int main()
{
	int array[] = {1,2,3,4,5,6,8,19};
	int n=10;
	int len = sizeof(array) / sizeof(array[0]); //get the size of the array
	int i=0;
	while(i != len)
	{
		if (array[i] + array[len] < n)
		{
			i++;
		}
		else if (array[i] + array[len] > n)
		{
			len--;
		}
		else
		{
			printf("%d %d",array[i],array[len]);
			break;
		}
	}
}
