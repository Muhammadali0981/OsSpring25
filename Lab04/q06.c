#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int sig) {
    printf("Alarm received. Terminating program.\n");
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5); // Set an alarm for 5 seconds

    for (int i = 1; ; i++) {
        printf("Program running... %d\n", i);
        sleep(1);
    }

    return 0;
}
