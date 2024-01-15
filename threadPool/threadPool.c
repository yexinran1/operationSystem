#include"threadPool.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define DEFAULT_MIN_THREADS 5
#define DEFAULT_MAX_THREADS 10
#define DEFAULT_QUEUE_CAPACITY 100

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ACCESS_INVALID,
    UNKNOWN_ERROR,
};

void * threadHander(void *arg)
{

}

/*线程池初始化*/
int threadPoolInit(threadpool_t *pool, int minThreads, int maxThreads, int queueCapacity)
{
    if (pool == NULL)
    {
        return NULL_PTR;
    }
    do
    {
        /*判断合法性*/
        if (minThreads <= 0 || maxThreads <= 0 || minThreads >= maxThreads)
        {
            minThreads = DEFAULT_MIN_THREADS;
            maxThreads = DEFAULT_MAX_THREADS;
        }
        /*更新线程池属性*/
        pool->minThreads = minThreads;
        pool->maxThreads = maxThreads;

        /*判断合法性*/
        if (queueCapacity <= 0)
        {
            queueCapacity = DEFAULT_QUEUE_CAPACITY;
        }
        /*更新线程池 任务队列属性*/
        pool->queueCapacity = queueCapacity;
        pool->queueFront = 0;
        pool->queueRear = 0;
        pool->queueSize = 0;
        pool->taskQueue = (task_t*)malloc(sizeof(task_t) * pool->queueCapacity);
        if (pool->taskQueue == NULL)
        {
            perror("malloc error");
            break;
        }
        /*清除脏数据*/
        memset(pool->taskQueue, 0, sizeof(task_t) * pool->queueCapacity);

        /*为线程ID分配空间*/
        pool->threadIds = (pthread_t*)malloc(sizeof(pthread_t) * maxThreads);
        if (pool->threadIds == NULL)
        {
            perror("malloc error");
            exit(-1);
        }
        /*清除脏数据*/
        memset(pool->threadIds, 0, sizeof(pthread_t) * maxThreads);

        int ret = 0;
        /*创建线程*/
        for (int idx = 0; idx < minThreads; idx++)
        {
            /*线程ID为0，可以用*/
            if (pool->threadIds[idx] == 0)
            {
                ret = pthread_create(&(pool->threadIds[idx]), NULL, threadHander, NULL);
                if (ret != 0)
                {
                    perror("thread create error");
                    break;
                }
            }
        }
        /*此ret是创建线程函数的返回值*/
        if (ret != 0)
        {
            break;
        }

        return ON_SUCCESS;
    }while(0);

    /*程序执行到这里，上面一定有失败*/

    /*回收堆空间*/
    if (pool->taskQueue != NULL)
    {
        free(pool->taskQueue);
        pool->taskQueue = NULL;
    }
    /*回收线程资源*/
    for (int idx = 0; idx < pool->minThreads; idx++)
    {
        if (pool->threadIds[idx] != 0)
        {
            pthread_join(pool->threadIds[idx], NULL);
        }
    }
    
    if (pool->threadIds != NULL)
    {
        free(pool->threadIds);
        pool->threadIds = NULL;
    }
    return UNKNOWN_ERROR;
}

/*线程池销毁*/
int threadPoolDestroy(threadpool_t *pool)
{

}