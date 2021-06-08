#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // execvp
        char *execvp_args[2];
        execvp_args[0] = strdup("/bin/ls");
        execvp_args[1] = NULL;
        execvp(execvp_args[0], execvp_args);
    } else {
        int wc = wait(NULL);
    }
    return 0;
}
