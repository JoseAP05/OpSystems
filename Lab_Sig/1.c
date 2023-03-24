#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{
    	printf("Usuario presiono ctrl c\n");
    	sleep(3);
}

int main(){
	signal(SIGINT, signal_handler);
	while( 1 )
	{
		printf( "ID: %d.\n", getpid() );
	}
	return 0;
}
