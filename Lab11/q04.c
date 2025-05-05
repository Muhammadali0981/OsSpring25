#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CUSTOMERS 5
#define NUM_CHEFS 2

sem_t chef_sem;
pthread_mutex_t order_lock;
int order_id = 1;

void *customer(void *arg) {
    int id = *((int *)arg);
    printf("Customer %d is placing an order...\n", id);

    sem_wait(&chef_sem); // wait for an available chef

    pthread_mutex_lock(&order_lock);
    int my_order = order_id++;
    printf("Chef is preparing order #%d for Customer %d\n", my_order, id);
    pthread_mutex_unlock(&order_lock);

    sleep(2); // simulate cooking time

    printf("Order #%d for Customer %d is ready!\n", my_order, id);
    sem_post(&chef_sem); // release chef
    return NULL;
}

int main() {
    pthread_t customers[NUM_CUSTOMERS];
    int ids[NUM_CUSTOMERS];

    sem_init(&chef_sem, 0, NUM_CHEFS);
    pthread_mutex_init(&order_lock, NULL);

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        ids[i] = i + 1;
        pthread_create(&customers[i], NULL, customer, &ids[i]);
    }

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_join(customers[i], NULL);
    }

    sem_destroy(&chef_sem);
    pthread_mutex_destroy(&order_lock);
    return 0;
}
