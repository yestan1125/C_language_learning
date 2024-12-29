#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str = "123";
    int num = atoi(str);
    printf("转换后的数字: %d\n", num);
    return 0;
}

//atoi为标准库中的函数

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    int numbers[MAX_LEN];
    int numCount = 0;
    int temp = 0;

    fgets(input, MAX_LEN, stdin);
    if(input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            temp = temp * 10 + (input[i] - '0');  // 拼接数字
        } else if (!isdigit(input[i])) {
            if (temp > 0) {  // 如果temp有数字，存储到数组
                numbers[numCount++] = temp;
                temp = 0;  // 重置temp以准备下一个数字
            }
        }
    }

    printf("the numbers is:\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
