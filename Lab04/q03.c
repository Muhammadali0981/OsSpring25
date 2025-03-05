#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Current Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    printf("User ID (UID): %d\n", getuid());
    
    return 0;
}
