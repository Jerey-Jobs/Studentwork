#include <stdio.h>
#include <string.h>

struct student 
{
	int age;
	char name[10];
	char addr[100];	
};

int main(int argc, char const *argv[])
{
    FILE *fp;	
    char buf[1024] = {0};
	
    
	struct student  stu1 = {12,"xiamin","iindasf"};
    

	fp = fopen("xiamin.txt","w+");

    sprintf(buf,"age:%d\tname:%s\taddr:%s\n",stu1.age,stu1.name,stu1.addr);
    
	fwrite(buf,strlen(buf),1,fp);

	fclose(fp);
    
    getchar();
    getchar();
	return 0;
}

