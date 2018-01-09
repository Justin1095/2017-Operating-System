#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
/*
	Justin Seda
  This program puts the file titled, "Steno.txt" into the image titled "GolfBldg.bmp"
  The encrypt image is called test.bmp
  ./a.out GolfBldg.bmp test.bmp
*/

int main(int argc, char * argv[]);
#define BUF_SIZE 3
#define OUTPUT_MODE 0700
int main(int argc, char * argv[])
{
	int in_fd, out_fd, rd_count, wt_count,c;
	FILE *readFile = fopen("Steno.txt", "r");
	int fd;
	char buffer[BUF_SIZE];
	char stenoBuff[1];
	char headerBuff[54];
	int key = 85;
	
	if (argc != 3) exit(1);
	in_fd = open(argv[1], O_RDONLY);

	if (in_fd < 0) exit(2); 	
	out_fd = creat(argv[2], OUTPUT_MODE); 
	
	if (out_fd < 0) exit(3);

	rd_count = read(in_fd, headerBuff, 54);
	wt_count = write(out_fd, headerBuff, rd_count);
	
	while ((c = fgetc(readFile))!= EOF) {
		rd_count = read(in_fd, buffer, BUF_SIZE); 
		
		if (rd_count <= 0) break;
		
		stenoBuff[1] = key^c;
		buffer[2]= stenoBuff[1];
		
		
		wt_count = write(out_fd, buffer, rd_count);

		if (wt_count <= 0) exit(4);
	}
	
	rd_count = read(in_fd, headerBuff, 54);
	buffer[2]= -1;
	wt_count = write(out_fd, headerBuff, rd_count);

	while (1) {
		rd_count = read(in_fd, buffer, BUF_SIZE); 
		
		if (rd_count <= 0) break;	
		
		wt_count = write(out_fd, buffer, rd_count);

		if (wt_count <= 0) exit(4);
	}

	close(in_fd);
	close(out_fd);
	if (rd_count == 0)
	exit(0);
	else
	exit(5);
}
