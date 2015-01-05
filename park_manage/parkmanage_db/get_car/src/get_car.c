/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：park_or_queue.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23 
Description：  取车函数
Funcion List:   int park_or_queue(char *str)
                int get_car()
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:      int park_or_queue(char *str) 
Description:   判断输入的str车牌是在队列里还是在停车场里
Calls:         int my_strcmp(char *src,char *ptr)
Called By:     int get_car()
Input:         NO 
Return:        NO
*************************************************/ 
int park_or_queue(char *str)
{
    int i;
    
    /*判断是否在停车场里 若在 返回IN_PARK*/
    for(i = 0; i <= top_park; i++)
    {
        if(my_strcmp(park[i].num,str) == 0)
        {
            return IN_PARK;
        }
    }

    /*判断是否在队列里 若在 返回IN_QUEUE*/
    for(i = front; i <= tail; i++)
    {
        if(my_strcmp(queue[i].num,str) == 0)
        {
            return IN_QUEUE;
        }
    }

        return NOT_EXIST;
}


/*************************************************
Function:       int get_car()
Description:    取车函数，取出停车场一辆车，若等候队列有，则进入一辆 
Calls:          int park_to_way()
                int way_to_park()
                int queue_to_park()
Called By:      int check_putin()
Input:          NO
Return:         NO
*************************************************/ 
int get_car(int fd)
{
    system("clear");

    int all_time;               //该车停车时长
    char car_card[MAX];         //输入车牌号
    time_t timep;               

    printf("请输入车牌号 : ");
    scanf("%s",car_card);
   
    /*若车在停车场 则将该车之后的车全部取车放进让路栈 再取出该车 让路栈再依次进停车栈*/
    if(park_or_queue(car_card) == IN_PARK)
    {
        /*再未取到自己车之前不断取车放进让路栈*/
        while(my_strcmp(park[top_park].num,car_card) != 0)
        {
            park_to_way();        
        }

        printf("您的车牌号为 %s 的车已经取出\n",park[top_park].num);

        all_time = time((time_t *)NULL) - park[top_park].park_time;

        time(&timep);


        printf("取车时间为 : %s",ctime(&timep));
        printf("停车时长为 : %d 秒\n",all_time);

        printf("收费 %g 元 !\n",all_time * 0.1);

        top_park--;

        while(top_way != -1)
        {
            way_to_park();
        }
    
        if((tail - front) != 0)
        {
            queue_to_park();
        }
        printf("取车成功，按任意件返回!\n");
    }

    else if(park_or_queue(car_card) == IN_QUEUE)
    {
        printf("您的车不在停车场,仍在等候队列,自取即可\n");
        printf("按任意件返回!\n");
    }

    else if(park_or_queue(car_card) == NOT_EXIST)
    {
        printf("您的车不在停车场也不在等候队列\n");
        printf("按任意件返回!\n");
    }

    getchar();
    scanf("%*[^\n]");

    system("clear");
    menu(fd);
}
