#include <stdio.h>
#include <string.h>
#include "cat_command.h"
#include "exec_command.h"

int main() {
    char command[256];

    printf("myshell> ");
    while (fgets(command, sizeof(command), stdin) != NULL) {
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "cat ", 4) == 0) {
            my_cat(command + 4);
        } else if (strncmp(command, "../", 3) == 0) {
            execute_program(command);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }

        printf("myshell> ");
    }

    return 0;
}

