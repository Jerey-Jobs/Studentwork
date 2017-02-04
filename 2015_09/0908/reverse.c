#include <stdio.h>
#include <string.h>


void reverse_word(char *head,char *tail)
{
	char tmp;

	while(head < tail)
	{
		tmp = *head;
		*head = *tail;
		*tail = tmp;

		head++;
		tail--;
	}

}


void reverse_str(char *str)
{
	char *head = str;
	char *tail;

	while(*str != 0)
	{	
		if(*str == ' ' || *str == '\0')
		{
			tail = str - 1;
			reverse_word(head,tail);
			head = str + 1;
		}
		str++;
	}
}

int main(int argc, char const *argv[])
{
	char str[30] = "i come from shanghai";

	reverse_word(str,str + strlen(str) - 1);
	printf("%s\n", str);
	reverse_str(str);
	printf("%s\n", str);

	return 0;
}


