#include <stdio.h>
#include <stdlib.h>

float getAvg(int *scores, int n){
    int sum = 0;
    for(int i=0; i<n; i++) sum += scores[i];
    return (float)sum / n;
}

int main() {
    int n;
    printf("学生人数：");
    scanf("%d", &n);

    int *scores = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        printf("成绩%d：", i+1);
        scanf("%d", &scores[i]);
    }

    printf("平均分：%.2f\n", getAvg(scores, n));
    free(scores);
    scores = NULL;
    return 0;
}
