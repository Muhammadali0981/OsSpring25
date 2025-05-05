#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>     // <-- Important for memset
#include <sys/types.h>
#include <sys/wait.h>


void handle_sigchld(int sig) {
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Child %d terminated.\n", pid);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigchld;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID %d) running.\n", getpid());
        sleep(2);
        printf("Child process (PID %d) exiting.\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID %d), waiting for child.\n", getpid());

        // Simulate long running work
        while (1) {
            printf("Parent working...\n");
            sleep(1);
        }
    }

    return 0;
}
