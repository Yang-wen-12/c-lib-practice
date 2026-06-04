#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Day4：定义结构体：封装硬件传感器数据（水位+水汽+采集时间）
typedef struct {
    int collect_time;   // 采集时间戳
    float water_level;  // 水位值 单位m 预期范围0~5m
    float humidity;     // 水汽浓度 预期范围30~90%RH
} SensorData;

// 函数声明 Day2：自定义函数
// 1.生成模拟传感器数据（模拟硬件采集）
SensorData create_sensor_data(void);
// 2.批量存储数据+写入文件（Day3 malloc + Day4 fwrite）
int save_sensor_to_file(int data_cnt, const char *file_name);
// 3.读取文件校验数据（Day4 fread，模拟回读硬件输出做校验）
int check_sensor_from_file(int data_cnt, const char *file_name);

int main(void)
{
    // 设定采集10组硬件数据
    int collect_num = 10;
    const char *log_file = "sensor_log.txt";

    // 写入：模拟硬件采集输出数据到文件
    if(save_sensor_to_file(collect_num, log_file) == 0)
    {
        printf("传感器数据已写入文件（模拟硬件输出完成）\n");
    }
    else
    {
        printf("硬件数据写入异常\n");
        return -1;
    }

    // 读取校验：模拟读取硬件返回数据，验证是否符合预期
    check_sensor_from_file(collect_num, log_file);
    return 0;
}

// 生成单条模拟硬件数据
SensorData create_sensor_data(void)
{
    SensorData data;
    data.collect_time = (int)time(NULL);
    // 随机生成符合硬件规格的数据：水位0~5，水汽30~90
    data.water_level = (rand()%500)/100.0f;
    data.humidity = 30 + (rand()%600)/10.0f;
    return data;
}

// 动态malloc开辟内存、批量写入文件
int save_sensor_to_file(int data_cnt, const char *file_name)
{
    // Day3：动态堆内存申请，存储批量结构体数据
    SensorData *p_data = (SensorData *)malloc(sizeof(SensorData)*data_cnt);
    if(p_data == NULL)
    {
        perror("malloc fail");
        return -1;
    }

    // 循环生成硬件数据
    for(int i=0; i<data_cnt; i++)
    {
        p_data[i] = create_sensor_data();
    }

    // Day4：fopen/fwrite 写入文件=硬件串口输出
    FILE *fp = fopen(file_name, "wb");
    if(fp == NULL)
    {
        perror("fopen fail");
        free(p_data); // 异常也要释放内存
        return -1;
    }
    fwrite(p_data, sizeof(SensorData), data_cnt, fp);
    fclose(fp);

    // Day3：用完必须free释放堆内存，杜绝内存泄漏
    free(p_data);
    p_data = NULL;
    return 0;
}

// 读取文件校验数据（模拟读取硬件输出结果）
int check_sensor_from_file(int data_cnt, const char *file_name)
{
    SensorData *p_check = (SensorData *)malloc(sizeof(SensorData)*data_cnt);
    FILE *fp = fopen(file_name, "rb");
    fread(p_check, sizeof(SensorData), data_cnt, fp);
    fclose(fp);

    printf("=====硬件输出数据校验结果=====\n");
    int err_cnt = 0;
    for(int i=0; i<data_cnt; i++)
    {
        // 校验规则：水位0~5，水汽30~90，超出范围=硬件异常
        if(p_check[i].water_level<0 || p_check[i].water_level>5 || p_check[i].humidity<30 || p_check[i].humidity>90)
        {
            printf("第%d组数据异常：水位%.2f 水汽%.2f\n",i+1,p_check[i].water_level,p_check[i].humidity);
            err_cnt++;
        }
        else
        {
            printf("第%d组正常：水位%.2fm,水汽%.2f%%RH\n",i+1,p_check[i].water_level,p_check[i].humidity);
        }
    }
    free(p_check);
    if(err_cnt == 0)
        printf("✅全部硬件数据校验通过，符合给定规格\n");
    else
        printf("❌存在异常数据，需调试修改采集逻辑\n");
    return err_cnt;
}
