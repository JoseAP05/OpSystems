#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	int n, fd;
	float a = 1;
	float b = 2;
	float c = 3;
	float d = 4;
	float e = 5;
	
	fd = creat("datos2.txt", 777);
	
	n = write(fd, &a, sizeof(a));
	n = write(fd, &b, sizeof(b));
	n = write(fd, &c, sizeof(c));
	n = write(fd, &d, sizeof(d));
	n = write(fd, &e, sizeof(e));
	
	if(fd < 0)
	{
		perror("write error");
	}
	
	close(fd);
	
	return 0;
}

