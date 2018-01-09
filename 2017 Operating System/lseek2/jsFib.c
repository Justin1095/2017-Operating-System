
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
/**
Justin Seda
This program displays the use of lseek and SEEK_SET.
**/
int main()
{
   int file=0;
   int i, first = 0,sec = 1, new, num;
	printf("Enter in a value: ");
	scanf("%d", &num);
	//printf("%d, ",num);
    
	 if((file=open("WK4-Fib.txt",O_RDONLY)) < -1)
	{
    	return 1;
	}
	int loop = num;
	for(i= 0; i< loop; i++)
	{
   		char buffer[0];
        if(lseek(file,first,SEEK_SET) < 0) 
		{
			return 1;
		}
        if(read(file,buffer,1) != 1)  
		{
			return 1;
		}
        printf("%s\n",buffer);
		//printf("%d, ",first);
		

		new = first + sec;
		first = sec;
		sec = new;
    }
   return 0;
}


