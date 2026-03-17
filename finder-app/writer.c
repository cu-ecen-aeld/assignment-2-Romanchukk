#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>

// TASK:
// Accepts the following arguments: the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile;
// the second argument is a text string which will be written within this file, referred to below as writestr
// Exits with value 1 error and print statements if any of the arguments above were not specified
// Creates a new file with name and path writefile with content writestr, overwriting any existing file and creating the path if it doesn’t exist. Exits with value 1 and error print statement if the file could not be created.

// Example:
// writer.c /tmp/aesd/assignment1/sample.txt ios
// Creates file:
// /tmp/aesd/assignment1/sample.txt
// With content:
// ios

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Argumet number is not matchin to writer format");
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    char *str = argv[2];
    size_t str_len = strlen(str) + 1;

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Failed to open: %s", filename);
        return EXIT_FAILURE;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", str, filename);
    ssize_t n = write(fd, str, str_len);
    if (n == -1) {
        syslog(LOG_ERR, "Failed to write content to file");
        return EXIT_FAILURE;
    } else if ((size_t)n != str_len) {
        syslog(LOG_ERR, "Saved data is not matching to arg[2] size");
    }

    return EXIT_SUCCESS;
}