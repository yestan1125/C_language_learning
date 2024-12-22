#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int remainder = a % b;  // 先计算初始余数
    for (int i = 1; i < n; i++) {
        remainder *= 10;  // 将余数乘以10，模拟除法运算的下一步
        remainder %= b;  // 取新的余数
    }
    remainder *= 10;  // 再乘以10，准备获取要输出的那一位数字
    int digit = remainder / b;  // 得到小数点后第n位数字

    printf("%d\n", digit);

    return 0;
}
/*分数a/b化为小数后，小数点后第n位的数字是多少？其中0 < a < b < 100，1≤n≤10000。
输入格式
三个正整数a，b，n，相邻两个数之间用单个空格隔开。
输出格式
一个数字
输入样例
1 2 1
输出样例
5*/
