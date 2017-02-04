#include "stdio.h"

typedef struct{
	char Name[20];
	float Math;
	float English;
	float Physical;
	float Sum;
}Stu;

int main()
{
	int i;
	int MaxKey = 0;
	int Max = 0;
	Stu Person[10];

	for(i = 0; i < 4; i++)
	{
		scanf("%s%f%f%f",Person[i].Name,&Person[i].Math,&Person[i].English,&Person[i].Physical);
		Person[i].Sum = Person[i].Math + Person[i].English + Person[i].Physical;
		if(Person[i].Sum > Max)
		{
			Max = Person[i].Sum;
			MaxKey = i;
		}
	}

	printf("%s,%f,%f,%f\n",Person[MaxKey].Name,Person[MaxKey].Math,
		Person[MaxKey].English,Person[MaxKey].Physical);
	
}

