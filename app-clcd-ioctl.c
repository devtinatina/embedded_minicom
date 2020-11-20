#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/ioctl.h>
#define LCD_DEV_MAGIC 'Y'
#define LCD_INIT _IO(LCD_DEV_MAGIC, 0)
#define LCD_SET_POS _IOW(LCD_DEV_MAGIC, 1, int)

int main()
{
    int fd;
    char str[100];
    char *msg1 = "ABCDEFG";
    char *msg2 = "0123456";

    fd = open("/dev/clcd", O_RDWR);

    ioctl(fd, LCD_SET_POS, 17);
    write(fd, msg1, strlen(msg1));

    ioctl(fd, LCD_SET_POS, 1);
    write(fd, msg2, strlen(msg2));

    // printf("input string (max 32 chars) : ");
    // scanf("%s", str);
    // str[32] = '\0';
    // ioctl(fd, LCD_INIT);
    // write(fd, str, strlen(str));
    close(fd);
    return 0;
}