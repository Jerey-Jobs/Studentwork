#include <stdio.h>
#include <string.h>

char str[100];
char t[100][100];
int n;
int result[100];

int cut()
{
	int i;
	for(i = 0; i < n; i++)
	{
		strcpy(t[i],str + i);
	}
}

int my_order()
{
	int i;
	int j;
	char str_tmp[100];
	int tmp;
	for(i = 0; i < n - 2; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(strcmp(t[j],t[j + 1]) > 0)
			{
				strcpy(str_tmp,t[j]);
				strcpy(t[j],t[j + 1]);
				strcpy(t[j + 1],str_tmp);
				tmp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = tmp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
//	printf("%d\n",strcmp("zz","ell"));
	int i;
	scanf("%d",&n);

	scanf("%s",str);
	cut();

	for(i = 0; i < n; i++)
	{
	//	printf("%s\n",t[i]);
		result[i] = i + 1;
	}

	my_order();


    for(i = 0; i < n; i++)
	{
		printf("%d\n",result[i]);
	}


	return 0;
}

