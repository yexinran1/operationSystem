#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 10

int main()
{

#if 1
    /* 使用lseek来计算文件大小 */
    int fd = open("./testWrite.c", O_RDWR);
    if (fd == -1)
    {
        perror("open error"); 
    }
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    
    #if 0
    off_t offset = lseek(fd, 0, SEEK_END);
    printf("offset:%ld\n", offset);
    #endif
#endif
    return 0;
}