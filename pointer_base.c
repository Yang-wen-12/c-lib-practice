#include <stdio.h>
int main() {
    int a = 10;
    // 定义指针，存储a的地址
    int *p = &a;

    printf("a的值：%d\n", a);
    printf("a的地址：%p\n", &a);
    printf("指针p存储的地址：%p\n", p);
    printf("通过指针访问a：%d\n", *p);
    return 0;
}
