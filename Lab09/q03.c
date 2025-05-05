#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void sigusr1_handler(int sig) {
    printf("Thread %ld received SIGUSR1\n", pthread_self());
}

void *thread_func(void *arg) {
    signal(SIGUSR1, sigusr1_handler);

    while (1) {
        printf("Thread %ld running...\n", pthread_self());
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    sleep(3);

    // Send SIGUSR1 to the entire process (all threads may handle it)
    printf("Sending SIGUSR1 using kill()\n");
    kill(getpid(), SIGUSR1);

    sleep(3);

    // Send SIGUSR1 to specific thread
    printf("Sending SIGUSR1 to t2 using pthread_kill()\n");
    pthread_kill(t2, SIGUSR1);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
