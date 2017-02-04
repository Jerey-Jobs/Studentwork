#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void order(char **s)
{
    char *tmp; 
    int j;
    int i;
    for(j = 0; j < 31; j++)
    {
        for(i = 0; i < 31 - j; i++)
        {
            if(strcmp(s[i],s[i+1]) > 0)
            {
                tmp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = tmp;              
            }        
        }    
    }
    
}

int main()
{
    char *s[32];
       
    int j;
    int i;
    
    order(s);
      
    for(i = 0; i < 5; i++)
    {
        printf("%s\n",s[i]);    
    }	
    
	system("pause");
	return 0;
}
