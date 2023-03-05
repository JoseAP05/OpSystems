#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	pid_t pid_R;
	pid_R = fork();
	
	if(pid_R == 0)
   	{
      		//esto es T
      		printf("soy T y mi pid es %d\n", pid_R);
      		pid_t pid_V;
      		pid_V = fork();
      		if(pid_V == 0){
      			printf("soy T y mi pid es %d\n", pid_R);
      		}
   	}
   
   
   	if(pid_R > 0)
   	{
      		pid_t pid_W
      		pid_t = fork();
      		
   	}
