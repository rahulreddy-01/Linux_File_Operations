#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDONLY, 0644);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    printf("File Opened with fd -> %d\n", fd);
    close(fd);
    return 0;
}