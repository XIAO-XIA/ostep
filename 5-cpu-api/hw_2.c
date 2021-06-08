#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    // redirect the stdout into file
    close(STDOUT_FILENO);
    open("./hw_2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    // create a child process with fork()
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // inside the child process
        printf("Print from child process %d\n", (int) getpid());
    } else {
        // inside the parent process
        printf("Print from parent precess %d\n", (int) getpid());
    }

    return 0;
}
