
/*
	pattern:��ʾ����,"ababc"
	next:��ʾҪ�洢������

*/
void make_next(const char *pattern, int *next)
{
	int q,k;
	//�ҵ��ַ�����
	int m = strlen(pattern);

	//��һ��ǰ׺Ԫ��û�й�������
	next[0] = 0;

	//q��ָ��pattern�ĵ�һ��ǰ׺����һ����Ȼ��q���������ƶ���k��ָ��pattern��ǰ׺
	for(q = 1, k <=0; q < m;q++)
	{

		//������ǻ��ݵ�λ��
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

	//pattern --> 'ababc',����Ϳ��������󹫹��ַ��ĸ���
	//��ʼʱ��next[0] = 0
	//Ȼ��ֻ�е���׺q��ǰ׺k��ֵ���ʱ���ſ�ʼ����
	//q=1,k=0,ptn[q]:ptn[k] = b:a; next[1] = 0;
	//q=2,k=0,ptn[q]:ptn[k] = a:a; k++, next[2] = 1;
	//q = 3, k =1,ptn[q]:ptn[k] = b:b;k++;next[3] = 2;
	//q = 4, k =2;ptn[q]:ptn[k] = c:a;k = next[k - 1]=next[1]=0;next[4]=0;
}

//ƥ��
int kmp(const char* text,const char* pattern,int *next)
{

	int n = strlen(text);
	int m = strlen(pattern);

	make_next(pattern,next);

	int i,q;
	//i��Ӧ����text ������ֵ
	//q��Ӧ����pattern������ֵ
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
			//���pattern������ֵ��ʾ�Ѿ�ȫ��ʶ����
			if(q == m)
			{
				break;
			}
		
	}
	
	return i-q+1;
}


