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
	pid_t pid_A, pid_B, pid_M;
	int status;
	pid_M = fork();
	
	
	if (pid_M == 0)
	{
		sleep(3);
		printf("soy M y mi pid es: %d\n", pid_M);
		return 3;
	}
	else
	{
		pid_A = fork();
		
		if (pid_A == 0)
		{
			sleep(10);
			printf("soy A y mi pid es: %d\n", pid_A);
			return 10;
		}
		else
		{
			pid_B = fork();
			if (pid_B == 0)
			{
				printf("soy B y mi pid es: %d\n", pid_B);
				return 0;
			}
		}
	}
	if (pid_M > 0)
	{
		waitpid(pid_M, &status, 0);
		printf("M termino con status: %d\n", WEXITSTATUS(status));
	}
	if (pid_A > 0)
	{
		waitpid(pid_A, &status, 0);
		printf("A termino con status: %d\n", WEXITSTATUS(status));
	}
	if (pid_B > 0)
	{
		waitpid(pid_B, &status, 0);
		printf("B termino con status: %d\n", WEXITSTATUS(status));
	}
}
