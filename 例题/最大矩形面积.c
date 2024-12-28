#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算最大矩形面积的函数
int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int*)malloc((heightsSize + 1) * sizeof(int)); // 栈
    int top = -1;  // 栈顶指针
    int max_area = 0; // 最大矩形面积
    
    for (int i = 0; i <= heightsSize; i++) {
        int h = (i == heightsSize) ? 0 : heights[i];  // 如果到达最后，设为0
        
        // 处理栈中元素，计算最大矩形
        while (top >= 0 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];  // 获取栈顶元素
            int width = (top == -1) ? i : i - stack[top] - 1;  // 计算宽度
            max_area = (max_area > height * width) ? max_area : height * width;
        }
        
        stack[++top] = i;  // 压入当前柱子的索引
    }
    
    free(stack);
    return max_area;
}

// 解析输入的数组字符串
void parse_input(char* input, int* heights, int* size) {
    int len = strlen(input);
    int index = 0;
    
    // 解析数组中的每个数字
    for (int i = 1; i < len; i++) {
        if (input[i] == '[' || input[i] == ' ' || input[i] == ',') {
            continue;
        }
        
        int num = 0;
        while (i < len && input[i] >= '0' && input[i] <= '9') {
            num = num * 10 + (input[i] - '0');
            i++;
        }
        heights[index++] = num;
    }
    *size = index;
}

int main() {
    char input[200];
    
    // 读取输入
    fgets(input, sizeof(input), stdin);
    
    int heights[100];
    int size = 0;
    
    // 解析输入
    parse_input(input, heights, &size);
    
    // 计算最大矩形面积
    int result = largestRectangleArea(heights, size);
    
    // 输出结果
    printf("最大矩形面积是：%d\n", result);
    
    return 0;
}
