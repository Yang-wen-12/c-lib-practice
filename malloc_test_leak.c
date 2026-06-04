#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    int count = 0;
    // 循环频繁申请内存，永不释放，制造泄漏
    while(1)
    {
        int *p = (int *)malloc(1024*sizeof(int));
	if(p == NULL) {
	    printf("内存申请失败\n");
            exit(1);
	}
	count++;
	//每100次申请打印一次，避免输出刷屏
	if (count % 100 == 0) {
	    printf("已申请 %d 次内存，共约%d KB\n",count,count*4);
	    fflush(stdout);
	}     
   // 没有free(p); 内存持续泄漏
        sleep(1);
    }
    return 0;
}
