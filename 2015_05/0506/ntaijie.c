/*һֻ����һ�ο������� 1 ��̨�ף�
Ҳ��������2 ���������������һ��n ����̨���ܹ��ж�����������*/


#include <stdio.h>

int n;
int count = 0;


int get(int t)
{
    if(t <= 0)
    {
    	return 0;
    }

    if(t == 1)
    {
    	return 1;
    }
    
    if(t == 2)
    {
        return 2;    
    }
    
    return get(t - 1) + get(t - 2);
}


int main(int argc, char const *argv[])
{
	int a;

	scanf("%d",&a);

   printf("%d\n",get(a));

	getchar();
	getchar();

	return 0;
}



