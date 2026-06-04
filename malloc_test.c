#include <stdio.h>
#include <stdlib.h>  // malloc/free 必须的头文件

int main() {
    int n;
    printf("请输入数组长度：");
    scanf("%d", &n);

    // 1. 申请堆内存
    int *arr = (int *)malloc(n * sizeof(int));
    // 判断内存是否申请成功
    if(arr == NULL){
        printf("内存申请失败！\n");
        return 1;
    }

    // 2. 赋值+遍历
    for(int i=0; i<n; i++){
        arr[i] = i + 1;
    }
    printf("动态数组：");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    // 3. 释放内存（必须写！）
    free(arr);
    arr = NULL;
    return 0;
}
