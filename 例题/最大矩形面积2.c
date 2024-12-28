#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // 使用 fmax 函数

typedef struct {
    int *data;
    int top;
    int size;
} Stack;

// 初始化栈
void init_stack(Stack *s, int size) {
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
}

// 压栈
void push(Stack *s, int val) {
    if (s->top + 1 == s->size) {
        return ;
    }
    s->data[++s->top] = val;
}

// 出栈
int pop(Stack *s) {
    return s->data[s->top--];
}

// 查看栈顶元素
int peek(Stack *s) {
    return s->data[s->top];
}

// 判断栈是否为空
int is_empty(Stack *s) {
    return s->top == -1;
}

// 释放栈的内存
void free_stack(Stack *s) {
    free(s->data);
    free(s);
}

// 计算矩形的最大面积
int largestRectangleArea(int* heights, int heightsSize){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init_stack(s, heightsSize);
    int *l = (int *)malloc(sizeof(int) * heightsSize);  // 左边界
    int *r = (int *)malloc(sizeof(int) * heightsSize);  // 右边界
    
    // 计算每个柱子左边第一个小于它的柱子的位置
    for (int i = 0; i < heightsSize; i++) {
        while (!is_empty(s) && heights[peek(s)] >= heights[i]) {
            pop(s);
        }
        l[i] = is_empty(s) ? -1 : peek(s);
        push(s, i);
    }
    
    // 清空栈
    s->top = -1;

    // 计算每个柱子右边第一个小于它的柱子的位置
    for (int i = heightsSize - 1; i >= 0; i--) {
        while (!is_empty(s) && heights[peek(s)] >= heights[i]) {
            pop(s);
        }
        r[i] = is_empty(s) ? heightsSize : peek(s);
        push(s, i);
    }

    // 计算每个柱子的最大矩形面积
    int ans = 0;
    for (int i = 0; i < heightsSize; i++) {
        ans = fmax(ans, (r[i] - l[i] - 1) * heights[i]);
    }

    free_stack(s);
    free(l);
    free(r);
    return ans;
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

//输入格式为height = [2,1,5,6,2,3]
