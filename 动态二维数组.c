#include<stdio.h>
#include<stdlib.h>

int main() {
    int n1, n2, i, j;
    int **arr;
    printf("��������Ҫ�����Ķ�̬����ĵ�һά���ȣ�");
    scanf("%d", &n1);
    printf("��������Ҫ�����Ķ�̬����ĵڶ�ά���ȣ�");
    scanf("%d", &n2);

    if ((arr = (int **) malloc(n1 * sizeof(int *))) == NULL)//ʹ��malloc����һά�����ڴ�
    {
        printf("�����ڴ�ռ�ʧ��!\n");//����ڴ����ʧ�ܣ������쳣�˳�
        return -1;
    }

    for (i = 0; i < n1; i++) {
        if ((arr[i] = (int *) malloc(n2 * sizeof(int))) == NULL)//ʹ��malloc���ڶ�ά�����ڴ�
        {
            printf("�����ڴ�ռ�ʧ��!\n");//����ڴ����ʧ�ܣ������쳣�˳�
            return -1;
        }
    }
    for (i = 0; i < n1; i++) { //ͨ��ѭ�������鸳ֵ���ڿ���̨���д�ӡ
        for (j = 0; j < n2; j++) {
            arr[i][j] = i * n2 + j + 1;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n1; i++) {
        free(arr[i]);//�ͷŵڶ�ά
    }
    free(arr);//�ͷŵ�һά

    return 0;
}
