#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    int key_in = 0;
    fd = open("/dev/key", O_RDWR);
    do
    {
        read(fd, &key_in, 4);
        printf("read! : keypad(%d)\n", key_in);
    } while (key_in != 11); // '#'
    close(fd);
    return 0;
}