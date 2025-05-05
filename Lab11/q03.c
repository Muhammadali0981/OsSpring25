#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TELLERS 3
#define NUM_TRANSACTIONS 5

int balance = 1000;
pthread_mutex_t lock;

void *teller(void *arg) {
    int id = *((int *)arg);
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        pthread_mutex_lock(&lock);
        int change = (rand() % 200) - 100;
        balance += change;
        printf("Teller %d: Transaction %d: Change = %d, New Balance = %d\n", id, i + 1, change, balance);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_TELLERS];
    int ids[NUM_TELLERS];

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_TELLERS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, teller, &ids[i]);
    }

    for (int i = 0; i < NUM_TELLERS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Final Balance: %d\n", balance);
    return 0;
}
