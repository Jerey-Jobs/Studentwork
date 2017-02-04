#include <stdio.h>
#include <string.h>

int my_inet_aton(char *str,unsigned int *ret)
{
	int tmp_int;
	int count = 0;
	unsigned int tmp_result = 0;
	unsigned int result = 0;

	while(*str != '\0')
	{
		count++;
		tmp_int = *str - '0';
		if(tmp_int >= 0 && tmp_int < 10)
		{
			tmp_result = tmp_result * 10 + tmp_int;
		}
		else
		{
			count = 0;
			result |= tmp_result;
			result <<= 8;						
			tmp_result = 0;
		}
        
		str++;
	}
    result |= tmp_result;
    *ret = result;
    return 0;
}

int main(int argc, char **argv)
{
    char ip_buf[16] = "192.168.1.2";
    unsigned int result_addr;
	
	printf("please input ip address: ");
	scanf("%s", ip_buf);

	my_inet_aton(ip_buf, &result_addr);

	printf("%x\n", result_addr);
	
    return 0;
}
