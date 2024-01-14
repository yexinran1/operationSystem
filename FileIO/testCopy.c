#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 10

int main()
{
    int fd = open("./testOpen.c", O_RDONLY);
    if (fd == -1)
    {
        perror("open error");
    }
    int fdCopy = open("./testOpenCopy.c", O_RDWR | O_CREAT);
    if (fdCopy == -1)
    {
        perror("open error");
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    int readLen = 0;
    while(1)
    {
        readLen = read(fd, buf, BUFFER_SIZE - 1);
        if ( readLen == 0)
        {
            /*说明文件读完了*/
            break;
        }
        write(fdCopy, buf, readLen);
        if (readLen < BUFFER_SIZE - 1)
        {
            break;
        }
    }
    close(fd);
    close(fdCopy);
    return 0;
}