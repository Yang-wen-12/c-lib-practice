#include "../include/sensor.h"

// 二进制保存
int save_bin(LinkList head, const char *path) {
    FILE *fp = fopen(path, "wb");
    Node *p = head->next;
    while (p) {
        fwrite(&p->data, sizeof(SensorData), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return 0;
}

// 二进制读取
int load_bin(LinkList head, const char *path) {
    FILE *fp = fopen(path, "rb");
    SensorData tmp;
    while (fread(&tmp, sizeof(SensorData), 1, fp)) {
        add_data(head, tmp);
    }
    fclose(fp);
    return 0;
}

// 文本保存（可读格式）
int save_txt(LinkList head, const char *path) {
    FILE *fp = fopen(path, "w");
    Node *p = head->next;
    while (p) {
        fprintf(fp, "%d %s %.2f %.2f %.2f\n",
                p->data.dev.dev_id, p->data.dev.dev_name,
                p->data.water, p->data.vapor, p->data.temp);
        p = p->next;
    }
    fclose(fp);
    return 0;
}
