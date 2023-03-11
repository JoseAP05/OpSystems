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
	pid_t pid_A, pid_B, pid_C, pid_D;
	int status;
	pid_A = fork();
	
	
	if (pid_A == 0)
	{
		pid_D = fork();
		if( pid_D == 0)
		{
			execl("/bin/ls", "ls", NULL);
		}
		
		waitpid(pid_D, &status, 0);
		execl("/bin/rm", "rm", "-r", "new_folder", NULL);
	}
	
	if( pid_A > 0 )
	{
		waitpid(pid_A, &status, 0);	
		
		pid_C = fork();
		
		if(pid_C == 0)
		{
			execl("/bin/ls", "ls", NULL);
		
		}
		
		if(pid_C > 0)
		{
			waitpid(pid_C, &status, 0);
			
			pid_B = fork();
			
			if (pid_B == 0)
			{
				execl("/bin/mkdir", "mkdir", "new_folder", NULL);
			}
			
			if(pid_B > 0)
			{
				waitpid(pid_B, &status, 0);
				printf("Soy M y mi pid: %d\n", getpid());
				execl("/bin/ls", "ls", NULL);
			}
		
		}
	}
}
