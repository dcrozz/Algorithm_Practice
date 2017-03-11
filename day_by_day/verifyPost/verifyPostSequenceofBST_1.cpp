#include<stdio.h>

bool verifyPostSequenceBST(int sequence[], int start, int end)
{
	if (sequence == NULL)// || start == end)
		return false;
	int root = sequence[end];
	int left = start;
	while (left < end)
	{
		if ( sequence[left] < root )
			left += 1;
		else
			break;
	}
	int rightPos = left;
	for(; rightPos < end; rightPos++)
	{
		if (sequence[rightPos]< root)
			return false;
	}
	bool leftSequence,rightSequence;
	if (left > start) //has left child
	{
		leftSequence = verifyPostSequenceBST(sequence,0,left-1);

	}
	if (left < end) //has right child
	{
		rightSequence = verifyPostSequenceBST(sequence,left, end-1);
	}
	return leftSequence && rightSequence;
}

int main()
{
	int sequence[]  = {1,4,3,5};
	int length = sizeof(sequence)/sizeof(sequence[0]);
	if(verifyPostSequenceBST(sequence,0,length-1))
	{

		printf("%d",length);
		printf("yes");
	}
	else
	{

		printf("%d",length);
		printf("no");
	}
}
