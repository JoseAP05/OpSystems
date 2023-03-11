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
	pid_t pid_B, pid_C, pid_E;
	int status;
	pid_B = fork();
	
	
	if (pid_B == 0)
	{
		sleep(3);
		return 1;
	}
	
	if( pid_B > 0 )
	{
		waitpid(pid_B, &status, 0);
		printf("B termino con status: %d\n", WEXITSTATUS(status));	
		
		pid_C = fork();
		
		if(pid_C == 0)
		{
			sleep(1);
			return 2;
		
		}
		
		if(pid_C > 0)
		{
			waitpid(pid_C, &status, 0);
			printf("C termino con status: %d\n", WEXITSTATUS(status));
			
			pid_E = fork();
			
			if (pid_E == 0)
			{
				return 3;
			}
			
			if(pid_E > 0)
			{
				waitpid(pid_E, &status, 0);
				printf("E termino con status: %d\n", WEXITSTATUS(status));
			}
		
		}
	}
}
