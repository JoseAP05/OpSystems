#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_found_flag = 0; 
int target_number; 

int array1[] = {1, 2, 3, 4};
int array2[] = {5, 6, 7, 8}; 
int array3[] = {9, 10, 11, 12}; 

void *search_array(void *arg) {

    int *array = (int *) arg;
    int array_size = sizeof(array)/sizeof(int);
    
    
    for (int i = 0; i < array_size; i++) 
    {
        if (array[i] == target_number) 
        {
            global_found_flag = 1; 
            break;
        }
    }
    pthread_exit(NULL);
}


int main() {
    pthread_t thread1, thread2, thread3;

    printf("What number are you looking for?: ");
    scanf("%d", &target_number); 

    pthread_create(&thread1, NULL, search_array, (void *) array1);
    pthread_create(&thread2, NULL, search_array, (void *) array2);
    pthread_create(&thread3, NULL, search_array, (void *) array3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);


    if (global_found_flag == 1) 
    {
        printf("Number found\n");
    } else 
    {
        printf("Number not found\n");
    }

    return 0;
}
