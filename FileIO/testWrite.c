#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
#if 1
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    char * ptr  = "hello world\n";
    /* 向文件中写入数据 */
    int bytes = write(fd, ptr, strlen(ptr));
    if (bytes < 0)
    {
        perror("open error");
    }
    else
    {
        printf("bytes:%d\n", bytes);
    }
    /* 关闭文件 */
    close(fd);
#endif

#if 0   
    /* 打开文件 */
    /*  */
    int fd1 = open("./hello.txt", O_RDWR | O_TRUNC);
    if (fd1 == -1)
    {
        perror("open error");
    }
#endif

#if 0
    /* 打开文件 */
    /* 以追加的方式打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_APPEND);
    if (fd == -1)
    {
        perror("open error");
    }
    char  ptr[] = "123\n";
    write(fd, ptr, sizeof(ptr));
    /* 关闭文件 */
    close(fd);
#endif
    return 0;
}
