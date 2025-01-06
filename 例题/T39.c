#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000

typedef struct {
    char word[50];
    int count;
} WordCount;

// 手动实现排序：按频次降序排序，频次相同按字典序升序
void sortWords(WordCount *wordCounts, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // 如果当前频次小于下一个元素的频次，交换
            if (wordCounts[j].count < wordCounts[j + 1].count) {
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
            // 如果频次相同，按字典序排序
            else if (wordCounts[j].count == wordCounts[j + 1].count) {
                if (strcmp(wordCounts[j].word, wordCounts[j + 1].word) > 0) {
                    WordCount temp = wordCounts[j];
                    wordCounts[j] = wordCounts[j + 1];
                    wordCounts[j + 1] = temp;
                }
            }
        }
    }
}

// 处理输入字符串，统计单词频次
void processInput(char *input, WordCount *wordCounts, int *size) {
    char word[50];
    int len = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);  // 转换为小写字母，并存进 word 数组
        } else if (len > 0) {
            word[len] = '\0';  // 结束当前单词
            len = 0;

            // 查找是否已存在
            int found = 0;
            for (int j = 0; j < *size; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[*size].word, word);
                wordCounts[*size].count = 1;
                (*size)++;  // 引用变量，更新 size
            }
        }
    }
}

int main() {
    char input[MAX_LEN];
    WordCount wordCounts[1000];
    int size = 0;

    // 输入字符串
    fgets(input, MAX_LEN, stdin);

    // 处理输入，统计单词频次
    processInput(input, wordCounts, &size);

    // 手动排序
    sortWords(wordCounts, size);

    // 输出结果：出现频次最多的单词及其频次
    printf("%s %d\n", wordCounts[0].word, wordCounts[0].count);

    return 0;
}
