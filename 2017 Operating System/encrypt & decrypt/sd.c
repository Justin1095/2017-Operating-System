#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
/*
	Justin Seda
  This program pulls out the text of "Steno.txt" from test.bmp and outputs it into test.txt 
  The decrypt text is called test.txt
  ./a.out text.bmp test.txt
*/

int main(int argc, char * argv[]);
#define BUF_SIZE 3
#define OUTPUT_MODE 0700
int main(int argc, char * argv[])
{
	int in_fd, out_fd, rd_count, wt_count;
	int fd;
	char buffer[BUF_SIZE];
	char stenoBuff[0];
	char headerBuff[54];
	int key = 85;
	
	if (argc != 3) exit(1);
	in_fd = open(argv[1], O_RDONLY);

	if (in_fd < 0) exit(2); 	
	out_fd = creat(argv[2], OUTPUT_MODE); 
	
	if (out_fd < 0) exit(3);
	
	rd_count = read(in_fd, headerBuff, 54);
	wt_count = write(out_fd, headerBuff, rd_count);

	while (buffer[2] != -1) {
		rd_count = read(in_fd, buffer, BUF_SIZE); 
	
		stenoBuff[0] = buffer[2]^key;
		
		wt_count = write(out_fd, stenoBuff, 1);
	}

	close(in_fd);
	close(out_fd);
	if (rd_count == 0)
	exit(0);
	else
	exit(5);
}
