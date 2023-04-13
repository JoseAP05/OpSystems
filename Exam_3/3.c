#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int signum) 
{
    	printf("Recibi senal de SigUser1\n");
    	printf("Mi pid es: %d\n", getpid());
	printf("Mi papa es: %d\n", getppid());
}

void handler2(int signum2) 
{
    	printf("Recibi senal de SigUser2\n");
    	printf("Mi pid es: %d\n", getpid());
	printf("Mi papa es: %d\n", getppid());
}

void handler3(int signum3) 
{
    	printf("Alarma recivida\n");
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
		pid_C = fork();
		signal(SIGALRM, handler3);
		alarm(3);
		pause();
		kill(pid_A, SIGUSR1);
		
		if(pid_C == 0)
		{
			signal(SIGUSR2, handler2);
			pause();
		}
		
		waitpid(pid_C, &status, 0);
		waitpid(pid_A, &status, 0);
		printf("Mis hijos terminaron");
	}
	
	return 0;
}
