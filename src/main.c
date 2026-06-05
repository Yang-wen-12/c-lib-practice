#include "sensor.h"
#include <stdio.h>

#define DATA_NUM 3 //采集3组传感器数据

int main(void)
{
    //1.动态开辟内存
    EnvData *p_data = create_sensor_arr(DATA_NUM);

    //手动填充模拟传感器数据
    p_data[0] = (EnvData){12.5f,62.3f,25.6f,1001};
    p_data[1] = (EnvData){15.2f,58.1f,23.9f,1002};
    p_data[2] = (EnvData){9.8f,70.5f,27.1f,1003};

    //2.写入data.bin二进制文件
    write_data_bin("data.bin",p_data,DATA_NUM);
    printf("数据写入文件成功\n");

    //3.清空内存，重新从文件读取
    EnvData *p_read = create_sensor_arr(DATA_NUM);
    read_data_bin("data.bin",p_read,DATA_NUM);
    printf("====从文件读取的传感器数据====\n");
    print_data(p_read,DATA_NUM);

    //4.释放堆内存（Day3：必须free，防止内存泄漏）
    free_sensor_arr(p_data);
    free_sensor_arr(p_read);
    p_data = NULL;
    p_read = NULL;

    return 0;
}
