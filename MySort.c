#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Ѿ����ԣ��ײ����
#define DATA_ARRAY_LENGTH 12
/*ϣ������(�����Ĳ�������)
	data:��δ��������Դ
	length:��ʾ���ݵĳ���
*/
int shell_sort(int *data,int length)
{

	//����
	int gap = 0, i = 0,j = 0;
	int tmp = 0;
	//��ѭ����������
	for(gap = length/2; gap>=1; gap/=2)
	{	
		//��ѭ����������
		//i��ʾ�α�
		for(i = gap; i < length; i++)
		{
			//�Ȱѵ�ǰ���ݻ���
			tmp = data[i];
			//�໥�Ƚ�
			for(j = i-gap; j>=0 &&tmp < data[j];j = j -gap)
			{
				//����
				data[j+gap] = data[j];
			}
			//ʵ�ֽ���
			data[j+gap] = tmp;
		}
		
	}
	return 0;
}

/*
	���������ϱ��һ������ļ��ϣ�����Ҫ����һ��temp����,temp������һ���м�״̬���������o(n)�Ŀռ�洢
*/
void merge(int * data,int *temp,int start,int middle,int end)
{

	int i = start,j = middle + 1,k = start;
	while(i <= middle && j<= end)
	{

		//����Ҫȷ��2�������Ѿ�������ġ�
		//����˭С˭�ȡ�
		//�����>��Ϊ<��Ҳ���Խ���
		if(data[i] > data[j])
		{
			temp[k++] = data[j++];
		}else
		{
			temp[k++] = data[i++];
		}

		//����ڶ������ϵ�Ԫ�أ�j�Ѿ���ĩβ�ˣ���ֻ��Ҫ�ѵ�һ������ʣ�µ�Ԫ�ؿ�����temp��
		
	}

	//�ڶ��鼯���Ѿ�����
	while(i <= middle) 
	{
		temp[k++] = data[i++];
	}
	//��һ�鼯���Ѿ�����
	while(j <= end)
	{
		temp[k++] = data[j++];
	}

	//������м������ٸ��ƻ���
	for(i = start; i <= end; i++)
	{
		data[i] = temp[i];
	}
	
}

/*�鲢���򣬵ݹ��˼��

1.�ȵݹ����
2.Ȼ���ںϲ�����
  int * temp:��ʾһ����ʱ���顣
*/
int merge_sort(int * data,int * temp,int start,int end)
{
	int middle;

	if(start < end)
	{
		//����indexֵ
		middle = start + (end - start)/2;
		//�ݹ����
		merge_sort(data,temp,start,middle);
		merge_sort(data,temp,middle+1,end);

		//�ָ���֮��ÿ�����������ֻ��2��Ԫ�ء�
		//�ϲ�
		merge(data,temp,start,middle,end);
	}
}




//��������,ͨ�������ȷ�Ϊ����������Ȼ���ٶ��������������зֱ�����
//ͨ�����������ǰ����ڱ�С��ֵ��ȫ��������ߣ����ڱ����ֵ�������ұ�
//ͨ����һ������ȷ���ڱ���λ�á�ʱ�临�Ӷ�Ϊnlogn,������o(n*n)
int sort(int * data,int left,int right)
{

	if(right < left)
		return -1;
	int i = left;
	int j = right;

	//ѡ���ڱ���λ�ã�key����ռ临�Ӷ�Ϊo(1)
	int key = data[left];
	//i������j���ͻ�һֱȥѰ�ұ�keyС��λ��
	while(i < j)
	{
		while(i < j && key<=data[j])
		{
			//�����ƶ�
			j--;
		}
		//���key����data[j]�������滻
		data[i] = data[j];

		while(i < j && key>=data[i])
		{
			//��ǰ�ƶ�
			i++;
		}
		//���򣬽��н���
		data[j] = data[i];
	}

	//��key��ֵ�ŵ���i��λ��,��ʱi�Ѿ�����j��
	data[i] = key;

	//�ݹ� 
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

