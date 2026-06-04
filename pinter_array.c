#include <stdio.h>
int main() {
    int arr[5] = {10,20,30,40,50};
    // 数组名=首地址，赋值给指针
    int *p = arr;

    printf("指针遍历数组：");
    for(int i=0; i<5; i++){
        // 等价于 arr[i]
        printf("%d ", *(p+i));
    }
    return 0;
}
