
package insert_sort;

public class insert_sort {
	public static void main(String args[]){
		int[] array1 = {1,23,1,24,12,41,241};
		int[] array2 = {1,23,1,24,12,41,241};
		int[] array3 = {1,23,1,24,12,41,241};
		insertion_sort_self(array1);
		insertion_sort_wiki1(array2);
		insertion_sort_wiki2(array3);
		System.out.println(array3);
	}
	public static void insertion_sort_self(int[] arr){
		for(int i=1; i<arr.length; i++){
			int tmp = arr[i];
			for(int j=i-1; j>=0; j--){
				if (arr[j] > tmp){
					arr[j+1] = arr[j];
				}else{
					arr[j+1] = tmp;
					break;
				}
			}
		}
	}
	public static void insertion_sort_wiki1(int [] arr){
		for (int i= 0; i< arr.length-1; i++){
			for (int j=i+1; j>0; j --){
				if(arr[j-1]<=arr[j])
					break;
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	public static void insertion_sort_wiki2(int [] arr){
		for (int i=1; i< arr.length; i++){
			int temp = arr[i];
			int j = i-1;
			for(; j>=0 && arr[j]<temp;j--){
				arr[j+1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}
}
