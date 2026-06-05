#include <stdio.h>

typedef struct {
    float water;
    float vapor;
    int id;
} Sensor;

int main() {
    // ========== 1. 二进制写入文件 ==========
    FILE *fp = fopen("data.bin", "wb");
    Sensor s = {25.8f, 55.2f, 1001};
    fwrite(&s, sizeof(Sensor), 1, fp);
    fclose(fp);
    printf("写入成功\n");

    // ========== 2. 二进制读取文件 ==========
    Sensor read_s;
    fp = fopen("data.bin", "rb");
    fread(&read_s, sizeof(Sensor), 1, fp);
    printf("读取成功：水位=%.2f\n", read_s.water);
    fclose(fp);

    return 0;
}
