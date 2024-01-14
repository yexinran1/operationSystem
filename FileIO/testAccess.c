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
    int ret = access("./hhh.c", F_OK);
    if (ret != 0)
    {
        perror("access error");
    }
    return 0;
}