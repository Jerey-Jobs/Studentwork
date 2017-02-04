/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int continue_max(char *outputstr,char *inputstr)
{
    int max = 0;
    int count;
    char *flag = outputstr;

    while(*inputstr != '\0')
    {
        count = 0;

        while(*inputstr <= '9' && *inputstr >= '0')
        {
            count++;
            inputstr++;
        }

        if(count > max)
        {
            max = count;
         
            outputstr = flag;
            while(count > 0)
            {
                *outputstr = *(inputstr - count);
                count--;
                outputstr++;
            }
            *outputstr = '\0';
            
        }

        inputstr++;
    }

    return max;
}

int main()
{
    char *str = "fds324vdflgh123456fdsil12345675fd";
    char ptr[100];
    int num;

    num = continue_max(ptr,str);

    printf("num is : %d\n",num);
    printf("ptr is : %s",ptr);

    

    return 0;
}
