//给定一个由英文字符、数字、空格和英文标点符号组成的字符串。
//长度不超过2000,请将其切分为单词，要求去掉所有的非英文字母。
//然后将单词全部转换成小写，再按照字典序升序排列，每个单词之间用空格分隔。

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 2000

// 提取单词、处理并排序的函数
void processString(char *input) {
    int len = strlen(input);
    char **words = (char **)malloc(len * sizeof(char *));  // 用于存储单词指针的数组
    int wordCount = 0;  // 记录单词的数量
    int wordIndex = 0;  // 当前单词内字符的索引

    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {  // 遇到英文字母，开始记录单词
            int start = i;
            while (i < len && isalpha(input[i])) {
                i++;
            }
            int wordLen = i - start;
            words[wordCount] = (char *)malloc((wordLen + 1) * sizeof(char));
            if (words[wordCount] == NULL) {
                printf("内存分配失败\n");
                return;
            }
            for (int j = 0; j < wordLen; j++) {
                words[wordCount][j] = tolower(input[start + j]);
            }
            words[wordCount][wordLen] = '\0';
            wordCount++;
            i--;  // 回退一位，避免跳过字符
        }
    }

    // 冒泡排序对单词按字典序升序排序
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    // 输出处理后的单词序列
    for (int i = 0; i < wordCount; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // 释放动态分配的内存
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    processString(input);
    return 0;
}
