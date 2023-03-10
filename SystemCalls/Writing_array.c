#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	int n, fd;
	float a[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	
	fd = creat("datos.txt", 777);
	
	n = write(fd, a, sizeof(a));
	if(fd < 0)
	{
		perror("write error");
	}
	
	close(fd);
	
	return 0;
}

