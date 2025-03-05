#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process executes `ls`
        execlp("ls", "ls", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        // Parent waits for the child to finish
        wait(NULL);
        printf("Child process completed.\n");
    }

    return 0;
}
