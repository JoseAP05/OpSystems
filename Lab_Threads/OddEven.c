#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

void* print_thread_number( void *args )
{
    int thread_num = *(int*)args;
    
    if (thread_num % 2 == 0) 
    {
        printf( "Thread %d is even.\n", thread_num );
    } else 
    {
        printf( "Thread %d is odd.\n", thread_num );
    }
    pthread_exit( NULL );
}


int main()
{
    pthread_t threads[THREADS_NO];
    int thread_args[THREADS_NO];
    
    int state, i;
   
    for(i = 0; i < THREADS_NO; i++)
    {
        thread_args[i] = i + 1;
        state = pthread_create(&threads[i], NULL, print_thread_number, &thread_args[i]);
        printf( "Main created thread %d.\n", i+1);
    }
   
    for (i = 0; i < THREADS_NO; i++) 
    {
        state = pthread_join(threads[i], NULL);
    }
    
}
