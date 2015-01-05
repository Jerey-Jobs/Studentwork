/*************************************************
copyright (C), 2014-2015, Lighting Studio. Co., Ltd. 
File name：     display_park.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：  显示出当前的停车场信息
Funcion List: int display_park()
*************************************************/

#include "../../include/myhead.h"

/************************************************
Function:      int display_park()  
Description:   打印出当前停车场的信息 
Calls:         void menu()
Called By:     int check_putin()
Input:         no
Return:        no
*************************************************/ 
int display_park(int fd)
{
    system("clear");
    printf("当前停车场中有 %d 辆车,等候队列有 %d 辆车\n",top_park + 1,tail - front); 

    printf("------------------------------\n");
    printf("|   车位号   |     车牌号    |\n");
    printf("------------------------------\n");

    int i;

    /*打印出目前停车场里所有的车的信息*/
    for(i = 0; i <= top_park; i++)
    {
        printf("| %4d       |     %5s     |\n",i + 1,park[i].num);
        printf("------------------------------\n");
    }


    printf("\t\t\033[47;31m按任意键返回主页!\033[0m\n");

    scanf("%*[^\n]");          //进入主菜单界面前清空行缓冲
    
    menu(fd);
}
