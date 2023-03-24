#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{
	printf("Transcurrieron 3 segundos");
}

int main(){
	signal(SIGALRM, signal_handler);
	alarm(3); 
	pause();
	return 0;
}
