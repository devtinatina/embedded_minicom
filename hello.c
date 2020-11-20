#include <stdio.h>

int main()
{
    printf("20160818 이규호");
    return 0;
}

/*

gcc -o hello_host hello.c
arm-linux-gcc -o hello_em hello.c

./hello_host
./hello_em

cp hello_host /opt/nfs/root
cp hello_em /opt/nfs/root

./hello_host
./hello_em

file hello.c
*/