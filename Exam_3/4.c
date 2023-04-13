#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int buffer = 0;

//
void* xd(void *args)
{
	while(1)
	{
		if(buffer < 0)
		{
			pthread_exit(NULL);
		}
		if(buffer > 0)
		{
			printf("cuadrado de buffer es: %d\n", buffer*buffer);
			buffer = 0;
		}
	}
	
	pthread_exit(NULL);
}


int main() {

    pthread_t thread_B;
    int state;
    
    state = pthread_create(&thread_B, NULL, xd, NULL);
    
    while(1)
    {
    	if(buffer == 0)
    	{
    		printf("Introduce a number \n");
		scanf("%d", &buffer);
    	}
    }
    
    pthread_join(thread_B, NULL);
    return 0;
}
