#include <stdio.h>   
#include <sys/stat.h>   
#include <dirent.h>   
#include <string.h>
  
int showConsoleDir(char* path, int cntFloor) 
{  
    DIR* dir;  
    DIR* dir_child;  
    struct dirent* dir_ent;  
  
    if ((dir = opendir(path))==NULL) {   //open current directory   
        printf("open dir failed!\n");  
        return -1;  
    }  

    while ((dir_ent = readdir(dir))!=NULL) 
    {  
        char tName[10000];  

        if ((dir_ent->d_name[0] == '.') || (strcmp(dir_ent->d_name, "..") ==0))
            continue;  

        memset(tName, 0, 10000);  
        snprintf(tName,sizeof(tName),"%s/%s",path,dir_ent->d_name);  

        if ((dir_child = opendir(tName))!=NULL)
        {  //if have a directory   
            int t = cntFloor;  
            while (t--)   
                printf("  ");  
           
            printf("+%s\n",dir_ent->d_name);  
            showConsoleDir(tName, cntFloor+1);  
        }  
        else  
        {  
            int t = cntFloor;  
            while (t--) 
                printf("  ");  
             
            printf("%s\n",dir_ent->d_name);  
        }     
    }     
}  
  
int main(int argc, char* argv[])
{  
    int cntFloor=1;  
    showConsoleDir("./", cntFloor);        
} 
