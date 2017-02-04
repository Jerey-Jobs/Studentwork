#include <stdio.h>
#include <stdlib.h>
/*
约瑟夫环是一个数学的应用问题：
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围
从编号为k的人开始报数,数到m的那个人出列;
他的下一个人又从1开始报数,数到m的那个人又出列
依此规律重复下去，直到圆桌周围的人全部出列。
*/
int main(void)
{
    int n;
    int  m;

    int i, j;
    int *p;

    int k; //k变量表示当前报数人数


    printf("报数出列游戏 参赛人数:\n");

    scanf("%d", &n);



    printf("报数出列规则:");

    scanf("%d", &m);

    printf("凡是报数为%d 则出列\n", m);

    p = (int *)malloc(n * 4);


    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    printf("请确定从哪个人开始报数:\n");

    scanf("%d", &i);

    printf("报数出列游戏开始:\n");

    int z;


    for(k = n; k >= 1; k--)
    {
        i = (i + m - 1) % k;

        printf("出列: %d\n", p[i]);

        for(j = i + 1; j < n; j++)
        {
            p[j - 1] = p[j];
        }

        for(z = 0; z < n; z++)
        {
            printf("%d ", p[z]);
        }
    }

    return 0;
}
