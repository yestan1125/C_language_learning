#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int*)malloc((heightsSize + 1) * sizeof(int)); // 定义栈
    int top = -1; // 栈顶指针
    int maxArea = 0; // 最大面积
    int i = 0;

    while (i < heightsSize) {
        // 如果栈为空或者当前高度大于等于栈顶柱子的高度，则入栈
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++; // 入栈当前柱子下标，并移动到下一个柱子
        } else {
            // 否则，弹出栈顶柱子，计算以该柱子为高度的矩形面积
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1; // 宽度的计算
            maxArea = (h * width > maxArea) ? h * width : maxArea;
        }
    }

    // 处理剩余的柱子
    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        maxArea = (h * width > maxArea) ? h * width : maxArea;
    }

    free(stack); // 释放栈的内存
    return maxArea;
}

int main() {
    char input[100];
    printf("输入（用户输入字符串）：");
    fgets(input, 100, stdin);

    int heights[100];
    int n = 0;

    // 解析输入字符串并将数字填充到heights数组中
    char *token = strtok(input, "[], ");
    while (token != NULL) {
        heights[n++] = atoi(token);
        token = strtok(NULL, "[], ");
    }

    // 调用函数计算最大矩形面积
    int maxArea = largestRectangleArea(heights, n);
    printf("输出：%d\n", maxArea);

    return 0;
}

/*解释第一次遍历：
i = 0：柱子高度为 2，栈为空，入栈 2，栈内容：[2]。
i = 1：柱子高度为 1，栈顶为 2（heights[0]），1 小于 2，弹出栈顶，计算面积 2 * 1 = 2，最大面积更新为 2。然后栈为空，入栈 1，栈内容：[1]。
i = 2：柱子高度为 5，栈顶为 1（heights[1]），5 大于 1，入栈 2，栈内容：[1, 2]。
i = 3：柱子高度为 6，栈顶为 5（heights[2]），6 大于 5，入栈 3，栈内容：[1, 2, 3]。
i = 4：柱子高度为 2，栈顶为 6（heights[3]），2 小于 6，弹出栈顶，计算面积 6 * 1 = 6，最大面积更新为 6。栈顶为 5（heights[2]），2 小于 5，弹出栈顶，计算面积 5 * 2 = 10，最大面积更新为 10。然后栈为空，入栈 4，栈内容：[4]。
i = 5：柱子高度为 3，栈顶为 2（heights[4]），3 大于 2，入栈 5，栈内容：[4, 5]。
剩余柱子的处理：
弹出栈顶（heights[5]）计算面积，最大面积更新为 10。
弹出栈顶（heights[4]）计算面积，最大面积更新为 10。*/
