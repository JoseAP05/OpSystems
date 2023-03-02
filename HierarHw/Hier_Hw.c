#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	pid_t pid_A;
	pid_A = fork();
	int fd, i, j, w, r, inte;
	int ints[5] = {1,2,3,4,5};
	int intes[5];
	fd = open("datos.txt", 777);
	if (fd < 0){
		perror("error de open");
		exit(1);
	}
	
	// Child process
	if( pid_A == 0 )
	{
		for (j = 0; j < 5; j++){
			char buf[16];
			int len = snprintf(buf, sizeof(buf), "%d", ints[i]);
			w = write(fd, ints, sizeof(ints));
			if(w < 0)
			{
				perror("error en write");
				exit(1);
			}
		}
	}
	else if (pid_A > 0)
	{
		sleep(3);
		
		r = read(fd, intes, sizeof(intes));
			if(r < 0){
				perror("error de read");
				exit(1);
			}
		for(i = 0; i < 5; i++){
			
			printf("%d\n", intes[i]);
		}
		
		close(fd);
	}
	
	return 0;
}




