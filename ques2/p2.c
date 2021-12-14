#include<stdio.h>
/*including header file of shared object*/
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
/*including header file of truncate*/
#include <unistd.h>
#include <string.h>

char* count; 
//char WORD[100];

int main(int argc, char const *argv[])
{
int fd,length,shmd;
shmd=shm_open("/shmd",O_RDWR|O_CREAT,S_IWUSR|S_IRUSR);
ftruncate(fd,sizeof(int));
count = (char*)mmap(NULL,sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,shmd, 0);

fd=open("dictionary.txt",O_RDONLY); //open the dictionary file 
read(fd,count,100);

length=strlen(count);  //find the length of string
printf("The received msg is:%s and size of msg is:%d\n",count,length);
return 0;
}