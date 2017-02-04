/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

/*int my_strcmp(char *src,char *ptr)
{
    if(src == NULL && ptr == NULL)
    {
        return 0;
    }


    while((*ptr != '\0') && (*str != '\0') )      
    {
    	if(*ptr != *str)
    	{
    		return 1;
    	}

        if(*ptr == ' ' && *str != ' ')
        {
            return 1;
        }

        
        if(*ptr != ' ' && *str == ' ')
        {
            return 1;
        }

        if(*ptr == ' ' && *str == ' ')
        {
            return 0;
        }
        str++;
        ptr++;
    }
   
*************************************************/ 
int my_strcmp(char *src,char *ptr)
{
    if(src == NULL && ptr == NULL)
    {
        return 0;
    }

    /*遍历ptr 若src前面对应的src*/
    while(*ptr && *src && *ptr == *src && *ptr != ' ')       
    {
        src++;
        ptr++;
    }
   
    return *src - *ptr;
}

