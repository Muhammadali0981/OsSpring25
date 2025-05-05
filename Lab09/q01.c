#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nCaught SIGINT (Ctrl+C). Exiting gracefully...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    printf("Running. Press Ctrl+C to trigger SIGINT.\n");

    while (1) {
        printf("Working...\n");
        sleep(1);
    }

    return 0;
}
