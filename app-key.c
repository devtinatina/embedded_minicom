#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    int key_buff = 0;
    fd = open("/dev/key", O_RDWR);

    char ch;
    do
    {
        read(fd, &key_buff, 4);
        //printf("read! : keypad(%d)\n", key_in);
        if (key_buff == 10) // '*'
            ch = '\n';
        else if (key_buff == 11) // #
            break;
        else
            ch = '0' + key_buff;
        printf("%c", ch);
        fflush(stdout);
    } while (key_buff != 11); // '#'
    close(fd);
    return 0;
}