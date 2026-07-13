#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Invalid Command Line Arguments!\n");
        return -1;
    }
    int fd1, fd2;
    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1) {
        perror("open");
        return -1;
    }

    fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(fd2 == -1) {
        perror("opne");
        return -1;
    }

    char buf[100];
    int ret;
    while((ret = read(fd1, buf, 20)) > 0) {

        if(write(fd2, buf, ret) != ret) {
            perror("write");
            return -1;
        }
    }

    if(ret < 0) {
        perror("read");
        return -1;
    }
    close(fd1);
    close(fd2);

    return 0;
}