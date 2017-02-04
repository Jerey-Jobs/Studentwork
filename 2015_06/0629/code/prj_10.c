/**
 * @author evan lau
 * @date 2015/06/14
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

struct my_in_addr
{
	unsigned int s_addr;
};

int my_inet_aton(const char *cp, struct my_in_addr *ap)
{
	int dots = 0;
    register unsigned int acc = 0;
	register unsigned int addr = 0;

	do
	{
        register char cc = *cp;

		switch (cc)
		{
     	case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			acc = acc * 10 + (cc - '0');
			break;
		case '.':
			if (++dots > 3)
			{
				return 0;
			}

		case '\0':
			if (acc > 255)
			{
				return 0;
			}
			addr = addr << 8 | acc;
			acc = 0;
			break;

		default:
			return 0;
		}
	} while (*cp++);

	if (dots < 3)
	{
		addr <<= 8 * (3 - dots);
	}

	if (ap)
	{
		ap->s_addr = addr;
	}

	return 1;
}


int main(int argc, char **argv)
{
    char ip_buf[16];
    struct  my_in_addr hex_addr;
	
	printf("please input ip address: ");
	scanf("%s", ip_buf);

	my_inet_aton(ip_buf, &hex_addr);

	printf("%x\n", hex_addr.s_addr);
	
    return 0;
}


