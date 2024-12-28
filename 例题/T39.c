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
/*给定一个由英文字符、数字、空格和英文标点符号组成的字符串，长度不超过5000，请将其切分为单词，要求去掉所有的非英文字母，然后将单词全部转换成小写，然后统计每一个词出现的次数，输出频次最高的那个词以及它出现的次数。如果有多个词的频次相同，则输出按字典序排列在最前面的那个。

例如给定字符串：String input = "1 fish 2 fish red fish blue fish";
频次最高的单词是fish，它出现了4次。

再比如给定字符串：If the digit is less than 10, then '0' + digit is returned. Otherwise, the value 'a' + digit - 10 is returned.
频次最高的单词是digit和is，都出现了3次。但是digit的字典序在is前面，所以应该输出digit和3。

输入格式
一个长度不超过2000的字符串，只有末尾有回车符。

输出格式
输出一行，首先是频次最高的那个单词，然后是它出现的次数，中间用空格分隔

输入样例
A character may be part of a Unicode identifier if and only if one of the following statements is true.
输出样例
a  2*/
