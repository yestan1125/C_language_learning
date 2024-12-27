#include<stdio.h>
#include<stdlib.h>

int main() {
    int n1, n2, i, j;
    int **arr;
    printf("请输入所要创建的动态数组的第一维长度：");
    scanf("%d", &n1);
    printf("请输入所要创建的动态数组的第二维长度：");
    scanf("%d", &n2);

    if ((arr = (int **) malloc(n1 * sizeof(int *))) == NULL)//使用malloc给第一维分配内存
    {
        printf("分配内存空间失败!\n");//如果内存分配失败，报错异常退出
        return -1;
    }

    for (i = 0; i < n1; i++) {
        if ((arr[i] = (int *) malloc(n2 * sizeof(int))) == NULL)//使用malloc给第二维分配内存
        {
            printf("分配内存空间失败!\n");//如果内存分配失败，报错异常退出
            return -1;
        }
    }
    for (i = 0; i < n1; i++) { //通过循环给数组赋值并在控制台进行打印
        for (j = 0; j < n2; j++) {
            arr[i][j] = i * n2 + j + 1;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n1; i++) {
        free(arr[i]);//释放第二维
    }
    free(arr);//释放第一维

    return 0;
}
