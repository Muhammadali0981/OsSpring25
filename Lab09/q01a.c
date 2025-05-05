#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>     
#include <sys/types.h>
#include <sys/wait.h>


void handle_sigint(int sig) {
    printf("\nCaught SIGINT using sigaction. Exiting...\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Running. Press Ctrl+C to trigger SIGINT.\n");

    while (1) {
        printf("Working...\n");
        sleep(1);
    }

    return 0;
}
