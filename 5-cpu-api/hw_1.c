#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[]) {
    // set the value of x to 100 in parent process
    int x = 100;
    printf("The raw value of x is %d\n", x);
    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // inside the child process
        printf("The value of x in child process %d is %d\n", (int) getpid(), x);
        x = getpid();
        printf("The value of x in child process %d is %d after modification\n", (int) getpid(), x);
    } else {
        // inside the parent process
        // inside the child process
        printf("The value of x in parent process %d is %d\n", (int) getpid(), x);
        x = getpid();
        printf("The value of x in parent process %d is %d after modification\n", (int) getpid(), x);
    }

    return 0;

}
