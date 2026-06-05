#include <stdio.h>

// 定义传感器结构体（水位 + 水汽 + 设备号）
typedef struct {
    float water;  // 水位
    float vapor;  // 水汽
    int id;       // 设备ID
} Sensor;

int main() {
    // 定义并赋值
    Sensor s = {12.5f, 60.0f, 1001};
    
    // 打印数据
    printf("设备%d：水位=%.2f，水汽=%.2f\n", s.id, s.water, s.vapor);
    return 0;
}
