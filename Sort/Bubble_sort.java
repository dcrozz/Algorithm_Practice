package bubble_sort;

public class Bubble_sort {
	public static void bubble_sort(int [] arr){
		for(int i=arr.length-1; i>=0; i--){
			for(int j = 0; j < i; j++){
				if(arr[j]>arr[j+1]){
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
	}
	
	public static void main(String args[]){
		int[] array = {1,312,4,12,41,412,1};
		bubble_sort(array);
		System.out.println(array);
	}
}
