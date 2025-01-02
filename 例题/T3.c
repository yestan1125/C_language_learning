// 引入标准输入输出库
#include <stdio.h>

// 主函数
int main(void) {
    // 声明两个整型变量m和n，用于存储用户输入的两个整数
    int m, n;
    // 从标准输入读取两个整数，分别存储到m和n中
    scanf("%d %d", &m, &n);

    // 声明一个大小为m的整型数组memory，用于模拟内存
    int memory[m];
    // 初始化memory数组的所有元素为-1，表示内存为空
    for (int i = 0; i < m; i++) {
        memory[i] = -1;
    }

    // 声明一个大小为1001的整型数组words，用于存储用户输入的单词
    int words[1001];
    // 从标准输入读取n个整数，分别存储到words数组中
    for (int i = 0; i < n; i++) {
        scanf("%d", &words[i]);
    }

    // 初始化head和tail指针，分别指向内存的头部和尾部
    int head = 0, tail = 0;
    // 初始化count变量，用于记录页面错误的次数
    int count = 0;

    // 遍历words数组中的每个单词
    for (int i = 0; i < n; i++) {
        // 初始化found变量，用于标记当前单词是否在内存中找到
        int found = 0;
        // 在memory数组中查找当前单词
        for (int j = head; j <= tail; j++) {
            if (memory[j % m] == words[i]) {
                // 如果找到，设置found为1，并跳出循环
                found = 1;
                break;
            }
        }
        // 如果当前单词未在内存中找到
        if (!found) {
            // 页面错误次数加1
            count++;
            // 将当前单词存储到内存中
            memory[tail % m] = words[i];
            // 移动tail指针到下一个位置
            tail++;
            // 如果内存已满，移动head指针到下一个位置，模拟FIFO页面置换算法
            if (tail - head == m) {
                head++;
            }
        }
    }
    // 输出页面错误的次数
    printf("%d", count);
    // 程序正常结束
    return 0;
}
