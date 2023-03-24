#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

void handlerALR(int signum) 
{
    	printf("Alarma recibida\n");
    	exit(1);
}

int main(){
	pid_t pid_B, pid_C;
	int status;

	pid_B = fork();
	signal(SIGALRM, handlerALR);
	alarm(5);
	
	if(pid_B == 0)
	{
		sleep(1);
		kill(pid_C, SIGKILL);
		pause();
	
	}
	
	if(pid_B > 0)
	{
		pid_C = fork();
		
		if(pid_C == 0)
		{
			while(1)
			{
				printf("Esperando senal\n");
			}
		}
		waitpid(pid_B, &status, 0);
	}
	
	return 0;
}
