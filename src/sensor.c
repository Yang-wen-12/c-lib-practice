#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>

// 动态内存分配
EnvData* create_sensor_arr(int num)
{
    // Day3：malloc堆内存分配
    EnvData *p = (EnvData*)malloc(sizeof(EnvData)*num);
    if(p == NULL){
        perror("malloc fail");
        exit(-1);
    }
    return p;
}

// 释放堆内存，避免内存泄漏
void free_sensor_arr(EnvData *arr)
{
    if(arr != NULL)
        free(arr);
}

// 二进制写入文件
int write_data_bin(const char *path, EnvData *arr, int cnt)
{
    FILE *fp = fopen(path,"wb"); // wb二进制写
    if(fp == NULL){
        perror("open write file fail");
        return -1;
    }
    fwrite(arr,sizeof(EnvData),cnt,fp);
    fclose(fp);
    return 0;
}

// 二进制读取文件
int read_data_bin(const char *path, EnvData *arr, int cnt)
{
    FILE *fp = fopen(path,"rb"); // rb二进制读
    if(fp == NULL){
        perror("open read file fail");
        return -1;
    }
    fread(arr,sizeof(EnvData),cnt,fp);
    fclose(fp);
    return 0;
}

void print_data(EnvData *arr,int cnt)
{
    for(int i=0;i<cnt;i++)
    {
        printf("设备%d：水位=%.2fm 水汽=%.2f%% 温度=%.2f℃\n",
                arr[i].dev_id,arr[i].water_level,arr[i].vapor,arr[i].temp);
    }
}
