#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000
#define MAX_WORDS 1000

// 排序比较函数：按频次降序排序，频次相同按字典序升序
int compare(const void *a, const void *b) {
    int countA = ((int*)a)[1], countB = ((int*)b)[1];
    if (countA != countB) return countB - countA;
    return strcmp(((char**)a)[0], ((char**)b)[0]);
}

// 统计单词频次
int processInput(char *input, char *words[MAX_WORDS], int counts[MAX_WORDS]) {
    char word[50];
    int len = 0, size = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);
        } else if (len > 0) {
            word[len] = '\0'; len = 0;
            int found = 0;
            for (int j = 0; j < size; j++) {
                if (strcmp(words[j], word) == 0) {
                    counts[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[size] = strdup(word);
                counts[size++] = 1;
            }
        }
    }
    if (len > 0) {
        word[len] = '\0';
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (strcmp(words[j], word) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[size] = strdup(word);
            counts[size++] = 1;
        }
    }
    return size;
}

int main() {
    char input[MAX_LEN];
    char *words[MAX_WORDS];
    int counts[MAX_WORDS];

    // 输入字符串
    fgets(input, sizeof(input), stdin);

    // 处理输入并统计频次
    int size = processInput(input, words, counts);

    // 排序并输出
    qsort(words, size, sizeof(char*), compare);
    printf("%s %d\n", words[0], counts[0]);

    // 释放内存
    for (int i = 0; i < size; i++) free(words[i]);

    return 0;
}
