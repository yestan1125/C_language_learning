#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = (int*)malloc(n * sizeof(int));  // 使用动态分配内存定义数组
    if (arr == NULL) {  // 检查内存分配是否成功
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = 1;  // 初始化为1，表示灯初始是开着的
    }

    for (int i = 1; i <= m; i++) {  // 从1开始遍历人，符合题目编号从1开始
        for (int j = i - 1; j < n; j += i) {  // 从i - 1开始（对应编号为i的人操作倍数的灯），以i为步长
            arr[j] =!arr[j];
        }
    }

    int flag = 0;  // 用于控制输出格式，避免多余空格开头
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {  // 如果灯是关闭状态（值为0）
            if (flag) {
                printf(",%d", i + 1);  // 输出逗号间隔
            }
            else {
                printf("%d", i + 1);
                flag = 1;
            }
        }
    }
    free(arr);  // 释放动态分配的内存
    return 0;
}
