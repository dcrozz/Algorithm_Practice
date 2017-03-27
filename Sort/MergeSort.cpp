#include<stdio.h>


void MergeSort(int arr[], int result[], int start, int end){
	if (start>= end) return;
	int length = end - start;
	int left1 = start; int left2 = (length>>1) + start;
	int right1 = left2+1; int right2 = end;
	MergeSort(arr, result, left1, left2);
	MergeSort(arr, result, right1, right2);
	int i = start; //注意是从start开始
	while( left1 <= left2 && right1 <= right2 )
		result[i++] = arr[left1] < arr[right1] ? arr[left1++] : arr[right1++];
	while( left1 <= left2 )
		result[i++] = arr[left1++];
	while( right1 <= right2 )
		result[i++] = arr[right1++];
	for(i = start; i <= end; i++)
		arr[i] = result[i];
}

int main(){
	int arr[] = {12,1,24,1,24,1,24,12,1,2,4};
	int result[11];
	MergeSort(arr, result, 0, 10);
	for (int i = 0 ; i < 10; i++)
		printf("%d ",arr[i]);
}
