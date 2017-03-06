#include<stdio.h>
bool verifyBST(int sequence[], int length)
{
	if( sequence == NULL || length == 0) return true;
	int root = sequence[length-1];
	int i = 0;
	for(; i < length -1;  i++)
	{
		if (sequence [i] > root)
			break;
	}

	int left_len = i;
	for(; i < length - 1 ; i++)
	{
		if (sequence[i] < root) return false;
	}

	bool left = verifyBST(sequence, left_len);
	bool right = verifyBST(sequence+left_len, length-left_len-1);
	return left && right;
}

int main()
{
	// int Sequence = [1,4,3,5];
	int Sequence[] = {6,8,7,5};
	if(verifyBST(Sequence, 4))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}
