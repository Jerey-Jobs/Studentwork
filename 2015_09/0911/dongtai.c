#include <stdio.h>
#include <stdlib.h>
/*
Լɪ����һ����ѧ��Ӧ�����⣺
��֪n���ˣ��Ա��1��2��3...n�ֱ��ʾ��Χ����һ��Բ����Χ
�ӱ��Ϊk���˿�ʼ����,����m���Ǹ��˳���;
������һ�����ִ�1��ʼ����,����m���Ǹ����ֳ���
���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�
*/
int main(void)
{
    int n;
    int  m;

    int i, j;
    int *p;

    int k; //k������ʾ��ǰ��������


    printf("����������Ϸ ��������:\n");

    scanf("%d", &n);



    printf("�������й���:");

    scanf("%d", &m);

    printf("���Ǳ���Ϊ%d �����\n", m);

    p = (int *)malloc(n * 4);


    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    printf("��ȷ�����ĸ��˿�ʼ����:\n");

    scanf("%d", &i);

    printf("����������Ϸ��ʼ:\n");

    int z;


    for(k = n; k >= 1; k--)
    {
        i = (i + m - 1) % k;

        printf("����: %d\n", p[i]);

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
