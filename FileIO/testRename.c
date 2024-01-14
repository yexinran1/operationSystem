#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
    int ret = rename("./hhh.c", "./xxx.c");
    if (ret == -1)
    {
        perror("rename error");
        return 0;
    }
    return 0;
}