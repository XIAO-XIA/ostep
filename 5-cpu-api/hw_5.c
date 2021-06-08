#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child process
        // int wc = wait(NULL);
        printf("Child process pid: %d\n", (int) getpid());
    } else {
        int wc = wait(NULL);
        printf("Parent prcess pid: %d, wc = %d\n", (int) getpid(), wc);
    }
    return 0;
}

