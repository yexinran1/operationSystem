#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#define BUFFER_SIZE 64
void get_file_time(__time_t st_time)
{
    struct tm* info;
    info=localtime(&(st_time));
    printf("%02d %02d %02d:%02d\n",info->tm_mon+1,\
            info->tm_mday,info->tm_hour,info->tm_min);
}


int main()
{
    struct stat bufStat;
    stat("./testCopy.c", &bufStat);
    printf("mode:%d\n", bufStat.st_mode);
    printf("st_size:%ld\n", bufStat.st_size);

    
    // get_file_time(bufStat.st_atime);
    // get_file_time(bufStat.st_mtime);
    // get_file_time(bufStat.st_ctime);

/* 配置文件 */
    /* 库函数 */
    FILE *pfd = popen("md5sum testStat.c", "r");
    if (pfd == NULL)
    {
        perror("popen error");
        return 0;
    }
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    fread(buf, sizeof(buf) - 1, 1, pfd);

    printf("buf:%s\n", buf);
    pclose(pfd);
    return 0;
}
