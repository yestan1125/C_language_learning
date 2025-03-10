#include <stdio.h>
#include <stdlib.h>

// 约瑟夫环函数
int josephus(int n, int k) {
    int *people = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        people[i] = i + 1;
    }
    int index = 0;
    int count = n;
    while (count > 1) {
        index = (index + k - 1) % count;
        // 将当前出圈的人从数组中移除，通过后面的元素向前移动
        for (int i = index; i < count - 1; i++) {
            people[i] = people[i + 1];
        }
        count--;
    }
    int lastPerson = people[0];
    free(people);
    return lastPerson;
}

int main() {
    int n = 3;
    int k = 2;
    int lastPerson = josephus(n, k);
    printf("the last one is %d\n", lastPerson);
    return 0;
}