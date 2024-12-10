#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void my_cat(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("cat");
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    if (bytes_read < 0) {
        perror("read");
    }

    close(fd);
}

