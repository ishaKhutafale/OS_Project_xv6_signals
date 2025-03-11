#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// Define SEEK_SET, SEEK_CUR, and SEEK_END manually for XV6
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int main() {
    int fd = open("testfile.txt", O_CREATE | O_RDWR);
    if (fd < 0) {
        printf(1, "Failed to open file\n");
        exit();
    }

    write(fd, "Hello, XV6!", 12); // Writing sample text

    // Seek to offset 6 from the start
    int new_offset = lseek(fd, 6, SEEK_SET);
    printf(1, "New Offset (SEEK_SET 6): %d\n", new_offset);

    char buf[10];
    read(fd, buf, 6); // Read next 6 characters
    buf[6] = '\0'; // Null-terminate the string
    printf(1, "Read after lseek: %s\n", buf); // Expected to read ", XV6!"

    // Seek 2 bytes forward from the current position
    new_offset = lseek(fd, 2, SEEK_CUR);
    printf(1, "New Offset (SEEK_CUR +2): %d\n", new_offset);

    // Seek 3 bytes back from the end
    new_offset = lseek(fd, -3, SEEK_END);
    printf(1, "New Offset (SEEK_END -3): %d\n", new_offset);

    close(fd);
    exit();
}

