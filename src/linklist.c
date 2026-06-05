#include "../include/sensor.h"

// 创建头结点
LinkList create_list() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

// 尾插法添加数据
void add_data(LinkList head, SensorData data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;

    Node *tmp = head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = p;
}

// 遍历打印
void show_all(LinkList head) {
    Node *p = head->next;
    if (!p) {
        printf("无数据！\n");
        return;
    }
    while (p) {
        printf("设备：%s(%d) | 水位:%.2f 水汽:%.2f 温度:%.2f\n",
               p->data.dev.dev_name, p->data.dev.dev_id,
               p->data.water, p->data.vapor, p->data.temp);
        p = p->next;
    }
}

// 释放整个链表（避免内存泄漏）
void free_list(LinkList head) {
    Node *p = head;
    while (p) {
        Node *q = p->next;
        free(p);
        p = q;
    }
}
