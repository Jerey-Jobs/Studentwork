
#include <stdio.h>
#include <string.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int n;
char pointc;
char str[20][20];
char my_st[20][20];
char book[20];
int len = 999;
int sum;
int max;

int my_strcmp(char *str,char *ptr,int len)
{
	char tmpp[100] = {0};
	strcpy(tmpp,ptr);
	*(tmpp + len) = '\0';
	return strcmp(str,tmpp);
}

/*获得两个字符串头尾多少个相同*/
int my_strcat(char *str,char *ptr)
{
	char *tmp_end = str;

	while(*tmp_end != '\0')
	{
		tmp_end++;
	}

	int max = MIN(strlen(ptr),strlen(str));
	int i;
	int count;

	for (i = 0; i < max; i++)
	{
		if(my_strcmp(tmp_end - i,ptr,i) == 0)
		{
			count = i;
		}
		else
			break;

	}

	return count;
}


int check()
{
	int i;

	char a = my_st[0][0];
//	if(a = pointc)
	{
		for(i = 0; i <= n; i++)
		{
			sum += my_strcat(my_st[i],my_st[i + 1]);
		}

		if((max - sum) < len)
		{
			len = max - sum;
		}
	//	printf("%d %d %d\n",max,sum,len);
	}
}

int dfs(int step)
{
	int i;
	if(step == n)
	{
		check();

		return 0;
	}

	for(i = 0; i < n; i++)
	{
		if(book[i] == 0)
		{
			book[i] = 1;
			memset(my_st[step],sizeof(my_st[step]),0);
			strcpy(my_st[step],str[i]);
			dfs(step + 1);
			book[i] = 0;
		}
	}


}

/*该题目卡在了之后读取一个字符 硬是读进去的是回车 
缓冲区没清空 做出了遍历 以及 获得两个字符串头尾多少个相同*/
int main(int argc, char const *argv[])
{

	int i;
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%s",str[i]);
		max += strlen(str[i]);
	}

	scanf("%c",&pointc);
	// printf("%d %c\n",pointc,pointc);
	// printf("%s\n", "wwaaaaa");

	dfs(0);

	printf("%d\n", len);

	return 0;
}



