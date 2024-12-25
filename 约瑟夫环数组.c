#include <stdio.h>

int main() {
    int n, m;  // n表示总人数，m表示报数的数字
    printf("input people:");
    scanf("%d", &n);
    printf("input number:");
    scanf("%d", &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // 初始化数组，存放人员编号1到n
    }

    int count = 0;  // 记录当前报数
    int index = 0;  // 当前下标位置
    int remain = n;  // 剩余人数

    while (remain > 1) {
        if (arr[index]!= 0) {  // 如果当前位置人员未出圈
            count++;
            if (count == m) {  // 报到m
                arr[index] = 0;  // 将该位置人员标记出圈
                count = 0;
                remain--;  // 剩余人数减1
            }
        }
        index = (index + 1) % n;  // 移动到下一个位置，模拟环形
    }

    for (int i = 0; i < n; i++) {
        if (arr[i]!= 0) {  // 找到最后剩下的那个人的编号
            printf("the last one is %d\n", arr[i]);
            break;
        }
    }

    return 0;
}