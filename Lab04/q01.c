#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork();
    if (child1 == 0) {
        // First child prints its PID
        printf("Child 1: My PID is %d\n", getpid());
        exit(0);
    }

    child2 = fork();
    if (child2 == 0) {
        // Second child prints its parent's PID
        printf("Child 2: My Parent's PID is %d\n", getppid());
        exit(0);
    }

    // Parent waits for both children
    wait(NULL);
    wait(NULL);
    
    printf("Parent: Both child processes have terminated.\n");
    return 0;
}
