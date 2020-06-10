
/*
	pattern:表示样本,"ababc"
	next:表示要存储的数组

*/
void make_next(const char *pattern, int *next)
{
	int q,k;
	//找到字符长度
	int m = strlen(pattern);

	//第一个前缀元素没有公共部分
	next[0] = 0;

	//q是指向pattern的第一个前缀的下一个，然后q依次往后移动，k是指向pattern的前缀
	for(q = 1, k <=0; q < m;q++)
	{

		//这里就是回溯的位置
		while(k > 0 && pattern[q] != pattern[k])
		{
			k = next[k-1];
		}

		if(pattern[q] == pattern[k])
		{
			k++;
		}

		next[q] = k;
	}

	//pattern --> 'ababc',这里就可以算出最大公共字符的个数
	//开始时，next[0] = 0
	//然后，只有当后缀q和前缀k的值相等时，才开始计算
	//q=1,k=0,ptn[q]:ptn[k] = b:a; next[1] = 0;
	//q=2,k=0,ptn[q]:ptn[k] = a:a; k++, next[2] = 1;
	//q = 3, k =1,ptn[q]:ptn[k] = b:b;k++;next[3] = 2;
	//q = 4, k =2;ptn[q]:ptn[k] = c:a;k = next[k - 1]=next[1]=0;next[4]=0;
}

//匹配
int kmp(const char* text,const char* pattern,int *next)
{

	int n = strlen(text);
	int m = strlen(pattern);

	make_next(pattern,next);

	int i,q;
	//i对应的是text 的索引值
	//q对应的是pattern的索引值
	for(i  = 0,q=0; i < n; i++)
	{
		while(q > 0 && pattern[q]!= text[i])
		{
			q = next[q-1];
		}

		if(pattern[q] == text[i])
		{
			q++;
		}
			//如果pattern的索引值表示已经全部识别了
			if(q == m)
			{
				break;
			}
		
	}
	
	return i-q+1;
}


