/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：check_msg.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.26 
Description：检查是否有不文明用语
Funcion List: int is_sub_str(char *str,char *ptr)
              int find_sub_string(char *str,char *ptr)
              int check_msg(char *str)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:      int is_sub_str(char *str,char *ptr)
Description:   判断str处开始是否是ptr子串
Calls:         NO
Called By:     int find_sub_string(char *str,char *ptr)
Input:         char *str  主字符串
               char *ptr 子串
Return:        1  否
               0  是
*************************************************/ 
int is_sub_str(char *str,char *ptr)
{
    /*遍历ptr看str开始处是否与ptr相等*/
	while(*ptr != '\0')
    {
        if(*ptr != *str)
        {
            return 1;
        }
        ptr++;
        str++;
    }

    return 0;
}

/*************************************************
Function:       int find_sub_string(char *str,char *ptr)
Description:    检查str中是否存在ptr子串 若存在则替换
Calls:          int is_sub_str(char *str,char *ptr)
Called By:      int check_msg(char *str)
Input:          char *str 主串
                char *ptr 子串
Return:         O
*************************************************/ 
int find_sub_string(char *str,char *ptr)
{
	int i;
	int len = strlen(ptr);

	while(*str != '\0')
	{
		/*若开始为ptr子串 则替换为* */
	 	if(is_sub_str(str,ptr) == 0)
	 	{
            for(i = 0; i < len; i++)
            {
		        *str = '*';
		        str++;
            }
	 	}
	 	str++;
	}

	return 0;
}

/*************************************************
Function:      int check_msg(char *str) 
Description:   检查str字符串是否存在不文明用语 若存在则全部替换为‘*’
Calls:         int find_sub_string(char *str,char *ptr)
Called By:     int chat()
               int broad()
Input:         char *str 待检查字符串
Return:        no
*************************************************/ 
int check_msg(char *str)
{
	char check_str[][10] = {"fuck","sb","bitch"};     //初始化不文明用语
    int i;
     
    for(i = 0; i < 3; i++)
    {
        find_sub_string(str,check_str[i]);	
    }
    
    return 0;
}

