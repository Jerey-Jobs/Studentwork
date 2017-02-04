#include <stdio.h>
#include <string.h>

int flag;


void my_judge(char *a,char *b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	if(len_a > len_b || ((*a - *b) > 0 && len_a == len_b) )
	{
        flag = 1;
	}
	else
	{
		flag = -1;
	}
}



void reverse(char *str)
{
    char *end = str + strlen(str) - 1;    //将end指向字符串'\0'前面一个字符
    char tmp;
    
    /*头尾掉换，直到str不小于end*/
    while(str < end)
    {
        tmp = *str;
        *str = *end;
        *end = tmp;

        str++;
        end--;
    }
}

void compute(char *a,char *b,char *ptr)
{
	int tmp;
	while(*b != '\0')
		{
	        tmp = *a - *b;

	        if(tmp < 0)
	        {   
	            *(a + 1) = *(a + 1) - 1;
	        	*ptr = tmp + '9' + 1;
	        }
	        else
	        {
	        	*ptr = tmp + '0';
	        }

	        a++;
	        b++;
	        ptr++;
		}

	while(*a != '\0')
	{
        *ptr = *a;
        a++;
        ptr++;
    }    

    *ptr = '\0';
}


int main(int argc, char const *argv[])
{
    char str1[500];
    char str2[500];
    char ptr[500];

    scanf("%s%s",str1,str2);

    my_judge(str1,str2);

    reverse(str1);
    reverse(str2);
    
    if(flag == 1)
    {	
        compute(str1,str2,ptr);

        reverse(ptr);

        printf("%s\n",ptr);
    }
    else if(flag == -1)
    {
    	compute(str2,str1,ptr);

    	reverse(ptr);

        printf("-%s\n",ptr);
    }
    
	return 0;
}

