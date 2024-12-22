#include <stdio.h>
#include <stdlib.h>

// 定义结构体表示考生信息
typedef struct Student {
    int chinese;
    int math;
    int english;
    int index;  // 考生序号，对应输入的行号（从1开始）
} Student;

// 比较函数，用于qsort的自定义比较规则
int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    // 先按总分降序排列
    int totalA = studentA->chinese + studentA->math + studentA->english;
    int totalB = studentB->chinese + studentB->math + studentB->english;
    if (totalA!= totalB) {
        return totalB - totalA;
    }
    // 若总分相同，按语文分数降序排序
    if (studentA->chinese!= studentB->chinese) {
        return studentB->chinese - studentA->chinese;
    }
    // 若语文分数相同，按数学分数降序排序
    if (studentA->math!= studentB->math) {
        return studentB->math - studentA->math;
    }
    // 若数学分数相同，按英语分数降序排序
    if (studentA->english!= studentB->english) {
        return studentB->english - studentA->english;
    }
    // 若所有分数都相同，按录入的顺序排列（序号小的在前）
    return studentA->index - studentB->index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    // 读取每个考生的信息并记录序号
    for (int i = 0; i < n; i++) {
        students[i].index = i + 1;
        scanf("%d %d %d", &students[i].chinese, &students[i].math, &students[i].english);
    }
    // 使用qsort进行排序
    qsort(students, n, sizeof(Student), compare);
    // 输出前m个考生的序号
    for (int i = 0; i < m; i++) {
        printf("%d ", students[i].index);
    }
    printf("\n");
    free(students);
    return 0;
}