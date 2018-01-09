#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
/**
Justin Seda
This program goes through the text file called ""WK4-lseek.txt" and uses lseek and SEEK_CUR to output "ESU COMPSCIIS GOOD!"
(Professor wanted this output, I dont know why)
**/

int main()
{
    int file=0;
    if((file=open("WK4-lseek.txt",O_RDONLY)) < -1)
	{
    	return 1;
	}
    char buffer[5];
	while(1)
	{
        if(lseek(file,4,SEEK_CUR) < 0) 
		{
			return 1;
		}
        if(read(file,buffer,1) != 1)  
		{
			return 1;
		}
        printf("%s",buffer);
    }
   return 0;
}
 