#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 10

int main(int argc, const char *argv[])
{
    /* 如果命令行参数不为3 */
    if (argc != 3)
    {
        printf("argc param must be 3\n");
    }
    /* 源文件 */
    

    
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open error");
    }
    int fdCopy = open(argv[2], O_RDWR | O_CREAT);
    if (fdCopy == -1)
    {
        perror("open error");
    }

    /* 缓冲区 */
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    int readLen = 0;
    while(1)
    {
        readLen = read(fd, buf, BUFFER_SIZE - 1);
        if (readLen == 0)
        {
            /* 说明文件读完了 */
            break;
        }
        write(fdCopy, buf, readLen);
        if (readLen < BUFFER_SIZE - 1 || readLen == 0)
        {
            break;
        }
    }
    /* 关闭文件 */
    close(fd);
    close(fdCopy);
    return 0;
}