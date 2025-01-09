/*M个相同的苹果放在N个相同的盘子中*/
#include <stdio.h>

// 计算放苹果的方法数
int placeApples(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    } else if (n > m) {
        return placeApples(m, m);
    } else {
        return placeApples(m, n - 1) + placeApples(m - n, n);
    }
}

int main() {
    int m, n;
    printf("请输入苹果的个数 M: ");
    scanf("%d", &m);
    printf("请输入盘子的个数 N: ");
    scanf("%d", &n);

    int result = placeApples(m, n);
    printf("一共有 %d 种放法\n", result);

    return 0;
}
