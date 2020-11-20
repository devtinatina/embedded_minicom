#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define CS3_BASE 0x0C000000
unsigned short FND_OFFSET[6] = { 0x0600, 0x0700, 0x0800, 0x0900, 0x0A00, 0x0B00 };

// 이것은 일종의 폰트 데이터
unsigned char FND_FONT[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F };

int main(void)
{
    int fd;
    int num, offset;
    int input;

    unsigned char* CS3_base;
    unsigned char* fnd;

    printf("input : ");
    scanf("%d", &input);

    // 1. 메모리 장치 파일 열기
    fd = open("/dev/mem", O_RDWR);
    if(fd < 0)
    {
        perror("/dev/mem FAIL! \n");
        exit(1);
    }

    // 2. mmap 함수 호출
    CS3_base = (unsigned char*)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS3_BASE);

    if((int)CS3_base == -1)
    {
        perror("mmap FAIL! \n");
        return -1;
    }

    // 3. 장치로 출력

    for (offset = 5; offset >= 0; offset--)
    {
        fnd = (unsigned char*)(CS3_base + FND_OFFSET[offset]);
        num = input % 10;
        if(input > 0)
        {
             *fnd = FND_FONT[num];
        }
        else
        {
            *fnd = 0;
        }
        input = input / 10;
        
    }

    // 4. munmap 함수 호출
    munmap((unsigned char*)CS3_base, 4096);

    // 메모리 장치 파일 닫기
    close(fd);
    return 0;
}

/*
gedit fnd.c

arm-linux-gcc -o fnd fnd.c

cp fnd /opt/nfs/root/embedded

cd /root/embedded

./fnd

/*