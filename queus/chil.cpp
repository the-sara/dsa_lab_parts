#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    printf("A \n");
    pid1 = fork();
    if (pid1 == 0) {printf("B \n");}
    else {
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0) {printf("C \n");}
        pid3 = fork();
        if (pid3 == 0) {printf("D \n");}
    }
    return 0;
}
