#ifndef SENSOR_H
#define SENSOR_H

// 传感器结构体（Day4核心）
typedef struct{
    float water_level;  //水位 m
    float vapor;        //水汽 %RH
    float temp;         //温度 ℃
    int dev_id;         //设备编号
}EnvData;

// 函数声明（Day2 函数）
// 动态开辟n条传感器内存（Day3 malloc）
EnvData* create_sensor_arr(int num);
// 释放动态内存（Day3 free）
void free_sensor_arr(EnvData *arr);
// 数据写入二进制文件（Day4 fwrite）
int write_data_bin(const char *path, EnvData *arr, int cnt);
// 从文件读取数据（Day4 fread）
int read_data_bin(const char *path, EnvData *arr, int cnt);
// 打印传感器数据
void print_data(EnvData *arr,int cnt);

#endif
