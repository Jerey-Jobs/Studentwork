/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   num_of_1.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/18
Description：  给出一个字节中被置为1的个数
Funcion List: 
             1.int find_nuber_1(char src)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int find_number_1(char src)
Description:    求出该字节中被置1的个数
Calls:          no
Called By:      main
Input:          char src  待求字节
Return:         sum       被置为1的个数
*************************************************/ 
int find_number_1(int src)
{
    int i;
    int tmp;
    int sum = 0;                   //存放置1个数
   
    for(i = 0; i < 8; i++)
    {
        tmp = src & 1;             //将该字节与00000001相与求得最后一位
        src = src >> 1;   

        if(tmp == 1)               //若相与后仍为1 则该位是被置1的
        {
            sum++;
        }
    }

    return sum;                    //返回置1个数

}


int main()
{
    int src;
    int num;                        //存放被置1个数

    printf("Please input :");
    scanf("%d",&src);

    num = find_number_1(src);       //调用find_number_1求出src所在字节被置1的个数

    printf("the number of 1 is %d\n",num);

    return 0;
}
