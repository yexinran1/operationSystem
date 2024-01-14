#include<stdio.h>
#include<time.h>
#include<unistd.h>

int g_debug = 0;
/* 日志 ： 就是文件 */
/* 打开日志文件 */
void log_init()
{
    time_t now;
    /* 避免野指针 */
    struct tm *ptm = NULL;
#define DEBUG_FLAG "./my_debug.flag"
    /* access函数 成功返回0 */
    if (access(DEBUG_FLAG, F_OK) == 0)
    {
        g_debug = 1;
    }
    if (!g_debug)
    {
        return;
    }
#define DEBUG_FILE "./my_debug.flag"
}

void  log_close()
{

}

int main()
{
    struct tm * info = localtime(NULL);

    return 0;

}