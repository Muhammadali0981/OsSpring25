#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int n;
    int id = fork();
    if(id != 0){
        int x;
        fork();
        x = getpid();
    }
    if (id != 0){
        n = 11;
    }
    else if(id == 0 && x == getpid()){
        n = 5;
    }
    else{
        n = 1;
    }

    for (int i = n; i < n+5; i++){
        printf(i);
    }

    while(wait(NULL) == -1);
    return 0;
}
