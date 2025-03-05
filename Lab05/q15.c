#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Step 1: Open "input.txt" for reading
    fd = open("input.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Step 2: Read contents into buffer
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }
    buffer[bytesRead] = '\0';  // Null-terminate string

    printf("Parent Process: File Content Before Modification:\n%s\n", buffer);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(1);
    }

    if (pid == 0) {
        // Step 3: Child process modifies file
        const char *childMessage = "\nProcessed by child process\n";
        write(fd, childMessage, strlen(childMessage));

        // Step 4: Execute `cat input.txt` to display modified content
        execlp("cat", "cat", "input.txt", NULL);
        perror("execlp failed");  // If execlp fails
        exit(1);
    } else {
        // Parent waits for child to complete
        wait(NULL);
        printf("Parent Process: Child has completed.\n");
    }

    close(fd);
    return 0;
}
