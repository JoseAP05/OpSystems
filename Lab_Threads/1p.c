#include <stdio.h>
#include <pthread.h>

void *factorial(void *arg) {
    int start = *((int *) arg);
    int end = start + 2;
    long long result = 1;

    for (int i = start; i <= end; i++) {
        result *= i;
    }

    pthread_exit((void *) result);
}

int main() {
    int nums[] = {1, 4, 7};
    pthread_t threads[3];
    int results[3] = {0};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, factorial, (void *) &nums[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], (void **) &results[i]);
    }

    int total = results[0] * results[1] * results[2];
    printf("Factorial of 9 is %d\n", total);

    return 0;
}


