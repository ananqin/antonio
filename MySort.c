#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//已经测试，亲测可用
#define DATA_ARRAY_LENGTH 12
/*希尔排序(分组后的插入排序)
	data:是未排序数据源
	length:表示数据的长度
*/
int shell_sort(int *data,int length)
{

	//步长
	int gap = 0, i = 0,j = 0;
	int tmp = 0;
	//外循环用来分组
	for(gap = length/2; gap>=1; gap/=2)
	{	
		//内循环用来排序
		//i表示游标
		for(i = gap; i < length; i++)
		{
			//先把当前数据缓存
			tmp = data[i];
			//相互比较
			for(j = i-gap; j>=0 &&tmp < data[j];j = j -gap)
			{
				//升序
				data[j+gap] = data[j];
			}
			//实现交换
			data[j+gap] = tmp;
		}
		
	}
	return 0;
}

/*
	把两个集合变成一个有序的集合，就需要借助一个temp数组,temp数组是一个中间状态，这里就有o(n)的空间存储
*/
void merge(int * data,int *temp,int start,int middle,int end)
{

	int i = start,j = middle + 1,k = start;
	while(i <= middle && j<= end)
	{

		//这里要确保2个集合已经是有序的。
		//升序，谁小谁先。
		//如果把>变为<，也可以降序
		if(data[i] > data[j])
		{
			temp[k++] = data[j++];
		}else
		{
			temp[k++] = data[i++];
		}

		//如果第二个集合的元素，j已经到末尾了，就只需要把第一个集合剩下的元素拷贝到temp中
		
	}

	//第二组集合已经到顶
	while(i <= middle) 
	{
		temp[k++] = data[i++];
	}
	//第一组集合已经到顶
	while(j <= end)
	{
		temp[k++] = data[j++];
	}

	//把这个中间数组再复制回来
	for(i = start; i <= end; i++)
	{
		data[i] = temp[i];
	}
	
}

/*归并排序，递归的思想

1.先递归分组
2.然后在合并排序
  int * temp:表示一个临时数组。
*/
int merge_sort(int * data,int * temp,int start,int end)
{
	int middle;

	if(start < end)
	{
		//定义index值
		middle = start + (end - start)/2;
		//递归分组
		merge_sort(data,temp,start,middle);
		merge_sort(data,temp,middle+1,end);

		//分割完之后，每个集合里面就只有2个元素。
		//合并
		merge(data,temp,start,middle,end);
	}
}




//快速排序,通过排序先分为两个样本，然后，再对这两个样本进行分别排序
//通过快速排序后，前面比哨兵小的值，全部放在左边，比哨兵大的值，放在右边
//通过第一次排序，确定哨兵的位置。时间复杂度为nlogn,最坏情况是o(n*n)
int sort(int * data,int left,int right)
{

	if(right < left)
		return -1;
	int i = left;
	int j = right;

	//选择哨兵的位置，key代表空间复杂度为o(1)
	int key = data[left];
	//i不等于j，就会一直去寻找比key小的位置
	while(i < j)
	{
		while(i < j && key<=data[j])
		{
			//往后移动
			j--;
		}
		//如果key大于data[j]，进行替换
		data[i] = data[j];

		while(i < j && key>=data[i])
		{
			//往前移动
			i++;
		}
		//否则，进行交换
		data[j] = data[i];
	}

	//把key的值放到第i个位置,这时i已经等于j了
	data[i] = key;

	//递归 
	sort(data,left,i-1);
	sort(data,i+1,right);
	return 0;
	
}
int quick_sort(int * data,int length)
{
	sort(data,0,length-1);
}

int main()
{

	int data[DATA_ARRAY_LENGTH] = {23, 64, 24, 12, 9, 16, 53, 57, 71, 79, 87, 97};
#if 1
	shell_sort(data,DATA_ARRAY_LENGTH);
#elif 0
	int temp[DATA_ARRAY_LENGTH] = {0};
	merge_sort(data,temp,0,DATA_ARRAY_LENGTH - 1);
#else
	quick_sort(data,DATA_ARRAY_LENGTH);
#endif
	int i = 0;
	for(i = 0; i < DATA_ARRAY_LENGTH; i++)
	{

		printf("%4d",data[i]);
	
	}
	printf("\n");
}

