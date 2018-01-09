#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
/*
Justin Seda
This program gets the image titled GolfBldg.bmp and changes the image yellow 
The new image is called test.bmp
*/

int main(int argc, char *argv[]);

#define BUF_SIZE 3
#define OUTPUT_MODE 0700

int main(int argc, char *argv[])
{
	
	//int *file1 = fopen("Steno.txt",r);	
	int in_fd, out_fd, rd_count, wt_count;
	char buffer[BUF_SIZE];
	//chAR sbuff[1]
	char buffer2[54];
	
	
	if (argc != 3) exit(1);

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd < 0) exit(2);
	out_fd = creat(argv[2], OUTPUT_MODE);
	if (out_fd < 0) exit(3);
	
	
	rd_count = read(in_fd, buffer2, 54);
	wt_count = write(out_fd, buffer2, 54);
	
	while(1){
		rd_count = read(in_fd, buffer, BUF_SIZE);
		if (rd_count <= 0) break;
		buffer[0] = '\0';
		
		
		wt_count = write(out_fd, buffer, rd_count);
		if (wt_count <= 0) exit(4);
	}
	
	close(in_fd);
	close(out_fd);
	if(rd_count == 0)
		exit(0);
	else
		exit(5);
}