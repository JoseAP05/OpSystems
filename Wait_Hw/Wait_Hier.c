#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include<stdlib.h>


int main()
{
	pid_t pid_A, pid_B, pid_M;
	int status;
	pid_A = fork();
	int contador = 0;
	int random = rand();
	
	
	if (pid_A == 0)
	{
		printf("soy A y mi pid es: %d\n", pid_A);
		printf("numero de a: %d\n", random);
		return 0;
	}
	
	if( pid_A > 0 )
	{
		pid_B = fork();
		if (pid_B == 0)
		{
			printf("soy B y mi pid es: %d\n", pid_B);
			printf("numero de b: %d\n", random);
			return 0;
		}
		
		if(pid_B > 0)
		{
			pid_M = fork();
			if (pid_M == 0)
			{
				printf("soy M y mi pid es: %d\n", pid_M);
				printf("%d\n", random);
				return 0;
			}
		
		}
		
		wait(&status);
		if (WEXITSTATUS(status) == 0)
		{
			contador = contador + 1;
		}
		
		wait(&status);
		if (WEXITSTATUS(status) == 0)
		{
			contador = contador + 1;
		}
		
		wait(&status);
		if (WEXITSTATUS(status) == 0)
		{
			contador = contador + 1;
		}
		printf("la cantidad de hijos que terminaron %d\n", contador);
	}
	return 0;
}




