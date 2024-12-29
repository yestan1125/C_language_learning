#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123";
    int num = atoi(str);
    printf("转换后的数字: %d\n", num);
    return 0;
}

//atoi为标准库中的函数

输入格式为[12,34,56,78]时
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

// 提取输入字符串中的数字，并返回数字的个数
int extractNumbers(char *input, int *numbers) {
    int numCount = 0;
    int temp = 0;
    int isReadingNumber = 0;  // 用于标记是否正在读取数字

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            if (!isReadingNumber) {
                isReadingNumber = 1;  // 开始读取数字
                temp = input[i] - '0';  // 将字符数字转换为整数
            } else {
                temp = temp * 10 + (input[i] - '0');  // 拼接数字
            }
        } else {
            if (isReadingNumber) {
                numbers[numCount++] = temp;  // 读取完一个数字，存储到数组中
                isReadingNumber = 0;  // 结束读取数字
            }
        }
    }

    // 如果最后一个字符是数字，处理最后一个数字
    if (isReadingNumber) {
        numbers[numCount++] = temp;
    }

    return numCount;
}

int main() {
    char input[MAX_LEN];
    int numbers[MAX_LEN];
    
    // 输入格式为 [12,23,34,56,334]
    fgets(input, MAX_LEN, stdin);

    // 提取数字
    int size = extractNumbers(input, numbers);
    
    // 输出提取出来的数字
    printf("提取出的数字是：\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
