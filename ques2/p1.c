
#include<stdio.h>
/*including header file of shared object*/
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
/*including header file of truncate*/
#include <unistd.h>
#include <string.h>
#define CHAR_SEARCH 'm'

char* count; 
char WORD[100];

int main(int argc, char const *argv[])
{
int fd;
int shmd;
int i=0;
shmd=shm_open("/shmd",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR); //open shared memory so that prog 2 can axcess
ftruncate(shmd,sizeof(int)); //trancate the length
count= (char*)mmap(NULL, sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,shmd, 0);//memory mapping

fd=open("dictionary.txt",O_RDONLY); //open the file
if(fd==-1)
    {
        printf("Could not open file"); //if file doesn't found
        return -1;
    }
read(fd,WORD,100);
//printf("the read message:\n%s",WORD);

while(WORD[i]!='\0')
{ 
if (WORD[i] == CHAR_SEARCH)
{
   break;
}
else
i++;
}
count=WORD;
printf("the send message:\n%s",count);

    return 0;
}



