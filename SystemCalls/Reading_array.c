#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	int m, fd;
	float a[5];
	
	fd = open("datos.txt", 0);
	if(fd < 0)
	{
		perror("open error");
	}
	
	m = read(fd, a, sizeof(a));
	
	for (int i=0; i<5; i++)
	{
		printf("%f", a[i]);
	}
	
	close(fd);
	
	return 0;
}

