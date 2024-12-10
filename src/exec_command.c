#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void execute_program(const char *program) {
    if (access(program, X_OK) != 0) {
        perror("Program not executable or not found");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return;
    } else if (pid == 0) {
        execl(program, program, NULL);
        perror("exec");
        _exit(errno);
    } else {
        wait(NULL);
    }
}

