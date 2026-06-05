#ifndef SENSOR_H
#define SENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 子结构体：设备信息（结构体嵌套）
typedef struct {
    int dev_id;           // 设备编号
    char dev_name[20];    // 设备名称
} DeviceInfo;

// 主结构体：传感器数据（嵌套 + 封装）
typedef struct {
    float water;    // 水位
    float vapor;    // 水汽
    float temp;     // 温度
    DeviceInfo dev; // 嵌套子结构体
} SensorData;

// 链表节点（指针核心：动态内存管理）
typedef struct Node {
    SensorData data;
    struct Node *next;
} Node, *LinkList;

// ========== 函数声明 ==========
// 创建链表
LinkList create_list();
// 尾插数据
void add_data(LinkList head, SensorData data);
// 遍历打印
void show_all(LinkList head);
// 释放链表（内存管理核心）
void free_list(LinkList head);

// 文件IO（二进制 + 文本）
int save_bin(LinkList head, const char *path);
int load_bin(LinkList head, const char *path);
int save_txt(LinkList head, const char *path);

#endif
