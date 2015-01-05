/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：add_car.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description： 停车函数
Funcion List: int my_judge()
              int add_car()
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:     int my_judge()  
Description:  判断输入的是y还是n若是yes 返回YES 若是n 返回NO   
Calls:        int my_judge()
Called By:    int add_car()
Input:        NO  
Return:       YES  输入的是Y 
              NO   输入的是N
*************************************************/ 
int my_judge()
{

    char judge;                     //存放输入字符
            
    scanf("%c",&judge);
                    
    if(judge == 'Y' || judge == 'y')//若输入y或Y 则返回YES
    {
        setbuf(stdin,NULL);
        scanf("%*[^\n]");           //清除输入缓冲
        return YES;
    }
                        
    if(judge == 'N' || judge == 'n')//若输入n或N 则返回NO
    {
        scanf("%*[^\n]");           //清除输入缓冲
        return NO;                 
    }
                           
    if((judge != 'Y') && (judge != 'N'))  //若不是n和y则提示重新输入 继续调用judge函数
    {
        printf("错误！请重新输入！\n"); 

        my_judge();
    }
}

/*************************************************
Function:     int add_car()    
Description:  停放车辆函数,若停车场满,停放到等待队列  
Calls:        void menu()
              int my_judge()
Called By:    int check_putin() 
Input:        NO  
Return:       NO  
*************************************************/ 
int add_car(int fd)
{
    system("clear");

    int tmp;                      
    NODE newcar;                     //准备停放的车的信息
    time_t timeb;
    char str[MAX];

    /*判断停车场是否满*/
    if(top_park == 9)                
    {
        printf("停车场已满！");
        
        printf("是否要停放在等待区(Y/N): ");

        tmp = my_judge();                  
        
        /*若愿意等待，则要求输入车牌号并存放进队列中*/
        if(tmp == YES)                 
        {
            printf("Please input car plate :  ");
            getchar();
            gets(newcar.num);

            newcar.park_time = time((time_t *)NULL);   //记录停车时间

            tail++;                   //队列尾加1
            
            queue[tail] = newcar;     //插入队列中
            
            time(&timeb);
            
            strcat(str,ctime(&timeb));
            strcat(str,"   ");
            strcat(str,newcar.num);

            write_line(fd,str,10);

            printf("\n");
            printf("您的车牌号为: %s 已经停车成功",newcar.num);

            printf("停车成功，按任意件返回!");

        
            getchar();
            scanf("%*[^\n]");
      
            menu(fd);                    //返回主菜单界面
        }
        else                           //若返回值不是YES 则返回主页
        { 
            scanf("%*[^\n]");
      
            menu(fd);                  
        }

    }
    /*若停车场栈不满 则要求输入车牌号并存放进栈中*/
    else
    {
        printf("Please input car plate :  ");
        gets(newcar.num);

        newcar.park_time = time((time_t *)NULL);

        top_park++;                    //栈顶加1

        park[top_park] = newcar;       //新车入栈
       
        memset(str,0,MAX);
        
        time(&timeb);

        sprintf(str,"card: %s\ttime : %s",newcar.num,ctime(&timeb));   

        write_line(fd,str,10);

        printf("\n");

        printf("您的车牌号为: %s 已经停车成功",newcar.num);

        printf("停车成功，按任意件返回!");
        
        scanf("%*[^\n]");
      
        menu(fd);                         //返回主页  
    }

    return 0;
}
