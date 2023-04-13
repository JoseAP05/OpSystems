#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int signum) 
{
    	printf("Senal 1 recibida\n");
}

void handler2(int signum2) 
{
    	printf("Senal 2 recibida\n");
}

int main(){
	pid_t pid_Q, pid_V, pid_R, pid_P;
	int status;

	pid_V = fork();
	
	if(pid_V == 0)
	{
		kill(getppid(), SIGUSR1);
		pid_R = fork();
		pid_P = fork();
		if(pid_R == 0)
		{
			while(1)
			{
				printf("mi pid: %d", getpid());
			}
		}
		if(pid_P == 0)
		{
			while(1)
			{
				printf("mi pid: %d", getpid());
			}
		}
	
	}
	
	if(pid_A > 0)
	{
		pid_Q = fork();
		
		if(pid_Q == 0)
		{
			kill(getppid(), SIGUSR2);
		}
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler2);
		pause();
		pause();
		
		
		waitpid(pid_Q, &status, 0);
		waitpid(pid_V, &status, 0);
		printf("Mis hijos terminaron");
		
	}
	
	return 0;
}
