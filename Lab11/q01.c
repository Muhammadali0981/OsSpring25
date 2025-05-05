#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

FILE *tempFile;
char filename[] = "/tempfile";  

void cleanup(int sig) {
    if (tempFile) {
        fclose(tempFile);
        unlink(filename);  // delete the file
        printf("\nFile closed and deleted. Cleanup done.\n");
    }
    exit(0);
}

int main() {
    int fd = mkstemp(filename);
    if (fd == -1) {
        perror("mkstemp failed");
        return 1;
    }

    tempFile = fdopen(fd, "w");
    if (!tempFile) {
        perror("fdopen failed");
        return 1;
    }

    signal(SIGINT, cleanup);

    int count = 0;
    while (1) {
        fprintf(tempFile, "Writing line %d\n", count++);
        fflush(tempFile);
        sleep(1);
    }

    return 0;
}
