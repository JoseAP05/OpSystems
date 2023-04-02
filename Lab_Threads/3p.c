#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {0};


void *secondary_thread(void *arg)
{
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        if (array[i] != 0) 
        {
            printf("Second thread: non zero found with value %d\n", array[i]);
            array[i] = 0;
        }
    }
    printf("Second thread last item is %d\n", array[ARRAY_SIZE]);
    pthread_exit(NULL);
}


int main()
{
    int i;
    pthread_t thread;


    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        int input;
        printf("Enter a value for array[%d]: ", i);
        scanf("%d", &input);
        array[i] = input;
    }
    
    pthread_create(&thread, NULL, secondary_thread, NULL);
    
    if (i == ARRAY_SIZE) 
        {
            pthread_join(thread, NULL);
            printf("done\n");
        }
        
    return 0;
}
