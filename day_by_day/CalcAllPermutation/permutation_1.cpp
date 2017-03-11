#include<stdio.h>
#include<algorithm>
using namespace std; // -std=c++11 需要这句不然error
void swap(int &a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void permutation(int array[], int start, int end)  //recursive
{
	if (array == NULL) return;
	if (start == end)
	{
		// for (int i = 0; i <= end; i++)
		// {
		//     printf("%d ",array[i]);
		// }
		// printf("\n");
		for_each(array, array+end+1, [] (int i)-> void { printf("%d",i); }); //使用for_each 和 lambda表达式
		printf("\n");
	}
	for (int j = start; j <= end; j++)
	{
		int k;//添加标志位k，第k位与j位相等
		for (k = 0; k < j; k++) //如果之前的值一样则不用交换
		{
			if (array[k] == array[j])
				break;
		}
		if (k<j) continue;
		swap(array[j],array[start]);
		permutation(array, start+1, end);
		swap(array[j],array[start]);
	}
}

void reverse(int array[], int start, int end)
{
	while( start < end )
	{
		swap( array[start++], array[end--] );
	}
}

void permutation2(int array[],int length) //iterative
{
	sort(array,array+length,[](int x, int y ) -> bool {return x<y;});  //最后的函数是定义greater,默认升序排列（从小到大）
	while (true)
	{
		for (int j = 0; j < length; j++)
		{
			printf("%d",array[j]);
		}
		printf("\n");

		int i = length - 2;//第一步找最后的递增序列头节点
		for (;i >= 0 && array[i] >= array[i+1]; i--);  //只写for不写{}来控制变量大小  //注意这个等于号啊我去
		if (i < 0) return;
		int k = length-1; //第二步找到从右向左第一个比i大的节点
		for (;k > i && array[k] <= array[i]; k--);
		swap(array[i],array[k]);// 第三步交换
		reverse(array, i+1, length-1);//第四步对i之后的节点逆序(交换后k之后的数字都比i小且一定是从大到小排列（i是最后的递增头），逆序变为顺序)
		//现在的array为之前的字典序的后一位
	}
}

void permutation3(int array[], int length)
{
	sort(array,array+length,[](int x, int y ) -> bool {return x<y;});  //最后的函数是定义greater,默认升序排列（从小到大）
	do
	{
		for_each(array,array+length,[](int x) -> void{ printf("%d",x); });
		printf("\n");
	}while(next_permutation(array, array+length)); //通过c++11自带的next_permutation实现
}

int main()
{
	int array[] = {10001,1,4,3};
	int length = sizeof(array)/sizeof(*array);
	// permutation(array,0,3);
	permutation3(array, length);
	return 0;
}
