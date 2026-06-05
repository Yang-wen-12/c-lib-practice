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


#include "../include/sensor.h"

// 菜单函数
void menu() {
    printf("\n===== 传感器管理系统 =====\n");
    printf("1. 添加数据\n2. 查看所有\n3. 保存二进制\n4. 保存文本\n5. 读取文件\n0. 退出\n");
    printf("==========================\n");
    printf("请输入选项：");
}

int main() {
    LinkList head = create_list();
    int choice;

    while (1) {
        menu();
        while(getchar() != '\n');
        scanf("%d", &choice);

        if (choice == 0) break;
        SensorData tmp;

        switch (choice) {
            case 1:
                printf("输入设备ID/名称/水位/水汽/温度：");
                scanf("%d %s %f %f %f",
                      &tmp.dev.dev_id, tmp.dev.dev_name,
                      &tmp.water, &tmp.vapor, &tmp.temp);
                add_data(head, tmp);
                break;
            case 2:
                show_all(head);
                break;
            case 3:
                save_bin(head, "data/sensor.bin");
                printf("二进制保存成功！\n");
                break;
            case 4:
                save_txt(head, "data/sensor.txt");
                printf("文本保存成功！\n");
                break;
            case 5:
                load_bin(head, "data/sensor.bin");
                printf("读取成功！\n");
                break;
        }
    }

    free_list(head);  // 释放内存
    return 0;
}
