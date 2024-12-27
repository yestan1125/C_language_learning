#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000  // 可根据实际情况调整，用于存储文章单词的数组大小

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int memory[m];  // 用数组模拟内存单元，直接存放单词
    for (int i = 0; i < m; i++) {
        memory[i] = -1;  // 初始化为 -1，表示为空单元
    }
    int words[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &words[i]);
    }
    int lookupTimes = 0;
    int front = 0, rear = 0;  // 模拟队列的头尾指针，用于管理内存单元的使用顺序
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = front; j <= rear; j++) {
            if (memory[j % m] == words[i]) {  // 检查单词是否已在内存中
                found = 1;
                break;
            }
        }
        if (!found) {
            lookupTimes++;
            memory[rear % m] = words[i];
            rear++;
            if (rear - front == m) {  // 内存已满，更新头指针模拟删除最早进入的单词
                front++;
            }
        }
    }
    printf("%d\n", lookupTimes);
    return 0;
}