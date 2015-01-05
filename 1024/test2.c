#include<stdio.h>
int main()
{
    char str1[100]={0},str2[100]={0};
    printf("please input two strings:\n");
    gets(str1);//读入字串
    gets(str2);
    char * p1=str1;//分别用来存str1和str2的当下比较位置
    char * p2=str2;
    int max=0,num=0;//max存放比较后最长字串长度，num是这一轮比较公共字串长度  
    char * start;//存放最大串起始位置
     while(*p1!='\0')//先是串1大循环
        {
        p2=str2;   //p2是串2首地址
            while(*p2!='\0')
          {   
              char * begin=p1;//begin是串1当前比较位置
              char * begin2=p2;//begin2是串2开始比较位置
              num=0;//比较前初始化为0
         while(*begin!='\0' && *begin2!='\0')//一轮新的比较
          {
           if(*begin==*begin2)     //若相同，num++；
                 {num++;begin++;begin2++;}
           else break;
              }
         if(num>max)    //若新比较出的字串更长，则替换max值和start内容
            {max=num;
             start=p1;}
         p2++;            //串2右移1位
              }
       p1++;       //串1右移1位
         }
 while(max--)  //输出串
  printf("%c",*start++);
printf("\n");
}