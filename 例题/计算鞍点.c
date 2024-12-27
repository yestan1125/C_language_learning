#include <stdio.h>

int main() {
    int m, n, i, j, k;
    scanf("%d %d", &m, &n);
    int array[m][n];

    // 输入数组元素
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int flag = 0;
    for (i = 0; i < m; i++) {
        int rowMax = array[i][0];//取每行第一个 
        int colIndex = 0;
        for (j = 1; j < n; j++) {
            if (array[i][j] > rowMax) {
                rowMax = array[i][j];
                colIndex = j;//找到该行最大 
            }
        }

        int colMin = rowMax;
        for (k = 0; k < m; k++) {
            if (array[k][colIndex] < colMin) {
                colMin = array[k][colIndex];//找到该列最小 
            }
        }

        if (colMin == rowMax) {
            printf("Array[%d][%d]=%d\n", i, colIndex, rowMax);//判断是否相等 
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("No\n");
    }

    return 0;
}
