#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // 使用 fmax 函数

// 计算柱状图的最大矩形面积
int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int*)malloc((heightsSize + 1) * sizeof(int)); // 定义栈
    int top = -1; // 栈顶指针
    int maxArea = 0; // 最大面积
    int i = 0;

    // 遍历柱子
    while (i < heightsSize) {
        // 如果栈为空或者当前高度大于等于栈顶柱子的高度，则入栈
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++; // 入栈当前柱子下标，并移动到下一个柱子
        } else {
            // 否则，弹出栈顶柱子，计算以该柱子为高度的矩形面积
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1; // 宽度的计算
            maxArea = fmax(maxArea, h * width);
        }
    }

    // 处理剩余的柱子
    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        maxArea = fmax(maxArea, h * width);
    }

    free(stack); // 释放栈的内存
    return maxArea;
}

// 解析输入字符串，提取数组
void parse_input(char *s, int **heights, int *heightsSize) {
    // 找到第一个 '[' 和最后一个 ']'
    char *start = strchr(s, '[');
    char *end = strchr(s, ']');
    
    // 如果没有找到 '[' 或 ']'，则返回
    if (!start || !end) {
        *heightsSize = 0;
        return;
    }
    
    // 计算数组长度
    int len = end - start - 1;  // 去掉 '[' 和 ']'
    char *nums = (char *)malloc(len + 1);
    strncpy(nums, start + 1, len);  // 拷贝数组部分
    nums[len] = '\0';  // 添加字符串结束符

    // 计算空格数量，来估算数组大小
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] == ',') {
            cnt++;
        }
    }

    *heightsSize = cnt + 1;
    *heights = (int *)malloc(sizeof(int) * (*heightsSize));

    // 用 strtok 拆分数组字符串
    char *p = strtok(nums, ",");
    for (int i = 0; p; i++) {
        (*heights)[i] = atoi(p);  // 转换为整数并存入数组
        p = strtok(NULL, ",");
    }

    free(nums);  // 释放临时字符串内存
}

int main() {
    char s[1000];
    int *heights, heightsSize;

    // 输入字符串，格式为 heights = [2, 1, 5, 6, 2, 3]
    fgets(s, sizeof(s), stdin);
    
    // 解析字符串，提取整数数组
    parse_input(s, &heights, &heightsSize);
    
    // 输出最大矩形面积
    printf("%d\n", largestRectangleArea(heights, heightsSize));

    // 释放内存
    free(heights);  
    return 0;
}
