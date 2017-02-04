#include <stdio.h>

int  FindSub(char *str,char *ptr)
{
	int srcl = strlen(str);
	int subl = strlen(ptr);

	if(subl > srcl)
	{
		return -1;
	}

	int i = 0;
	int j = 0;

	while(i < srcl && j < subl)
	{
		if(str[i] == ptr[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i + 1 - j;
			j = 0;
		}
	}

	if(j >= subl) return i - subl;
	return -1;
}


int main(int argc, char const *argv[])
{
	char *str = "wrgfsdagabsdffwabsfwqe";
	char *ptr = "absf";

	*(str + 1) = 'f';

	printf("%d\n",FindSub(str,ptr));
		
	return 0;
}

