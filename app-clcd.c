#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/ioctl.h>
#define LCD_DEV_MAGIC 'Y'
#define LCD_INIT _IO(LCD_DEV_MAGIC, 0)
int main()
{
    int fd;
    char str[100];
    fd = open("/dev/clcd", O_RDWR);
    printf("input string (max 32 chars) : ");
    scanf("%s", str);
    str[32] = '\0';
    ioctl(fd, LCD_INIT);
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}