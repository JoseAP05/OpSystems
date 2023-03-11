#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>


int main()
{
	pid_t pid_L, pid_D;
	int status;
	pid_L = fork();
	
	
	if (pid_L == 0)
	{
		sleep(3);
		printf("soy L y mi pid es: %d.\n\n", pid_L);
		printf("soy L y mi papa es: %d.\n\n", getpid());
		return 0;
	}
	
	if( pid_L > 0 )
	{
		pid_D = fork();
		
		if (pid_D == 0)
		{
			sleep(1);
			printf("soy D y mi pid es: %d.\n\n", pid_D);
			printf("soy D y mi papa es: %d.\n\n", getpid());
			return 0;
		}	
		wait(&status);
		if (WEXITSTATUS(status) == 0)
		{
			printf("uno de mis hijos termino su ejecucion");
		}
	}
}
