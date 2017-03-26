#include<stdio.h>
#include<algorithm>
void QuickSort(int arr[], int start, int end){
	if(start >= end) return;
	int left = start+1;
	int right = end;
	int mid = arr[start];
	while(left < right){
		while(arr[left]<= mid && left < right) left++;
		while(arr[right] >= mid && left < right) right--;
		std::swap(arr[left],arr[right]);
	}
	if(arr[left] <= mid)
		std::swap(arr[left],arr[start]);
	else{
		left--;
		std::swap(arr[left],arr[start]);
	}
	QuickSort(arr, start, left-1);
	QuickSort(arr, left+1, end);
}
int main(){
	int arr[] = {3,124,1,2,4,15,1,23,5,15,121};
	int length = sizeof(arr)/sizeof(*arr);
	QuickSort(arr,0,length-1);
	for (int i = 0 ; i < length ; i++)
		printf("%d ", arr[i]);
	return 0;

}


