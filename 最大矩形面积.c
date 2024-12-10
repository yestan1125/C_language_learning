#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 栈的结构体定义
typedef struct {
    int *data;
    int top;
    int size;
} Stack;

// 初始化栈
void init_stack(Stack *stack, int size) {
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
}

// 入栈
void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

// 出栈
int pop(Stack *stack) {
    return stack->data[stack->top--];
}

// 获取栈顶元素
int peek(Stack *stack) {
    return stack->data[stack->top];
}

// 获取栈的大小
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// 释放栈
void free_stack(Stack *stack) {
    free(stack->data);
}

// 计算最大矩形面积的函数
int largestRectangleArea(int* heights, int heightsSize) {
    Stack stack;
    init_stack(&stack, heightsSize + 1);  // 多分配一个位置，方便处理栈空的情况
    int max_area = 0;
    
    for (int i = 0; i <= heightsSize; i++) {
        int h = (i == heightsSize) ? 0 : heights[i];  // 当到达最后时，将高度设为0
        
        while (!is_empty(&stack) && h < heights[peek(&stack)]) {
            int height = heights[pop(&stack)];  // 获取栈顶元素作为矩形的高度
            int width = (is_empty(&stack)) ? i : i - peek(&stack) - 1;  // 计算宽度
            max_area = (max_area > height * width) ? max_area : height * width;  // 更新最大面积
        }
        
        push(&stack, i);  // 压入当前柱子的索引
    }
    
    free_stack(&stack);
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
