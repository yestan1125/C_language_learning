#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 5000      // 输入字符串的最大长度
#define MAX_WORDS 1000       // 存储单词和频次的最大单词数

// 结构体用于存储单词及其出现的频次
typedef struct WordFreq {
    char word[MAX_LENGTH];   // 存储单词的字符数组
    int freq;                // 存储单词出现的频次
} WordFreq;

// 比较两个单词的字典序，用于排序
// qsort函数会使用该比较函数对单词数组进行排序
int compareWords(const void *a, const void *b) {
    // 比较两个单词的字典序
    return strcmp(((WordFreq *)a)->word, ((WordFreq *)b)->word);
}

// 插入单词到WordFreq数组中，如果已存在则增加频次
// 通过遍历数组判断单词是否已存在，如果存在则增加频次，否则插入新单词
void insertWord(WordFreq words[], int *wordCount, const char *newWord) {
    // 遍历已有的单词数组
    for (int i = 0; i < *wordCount; i++) {
        // 如果单词已存在，则增加其频次并返回
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].freq++;
            return;
        }
    }
    // 如果单词不存在，则将新单词插入到数组
    strcpy(words[*wordCount].word, newWord);  // 复制新单词到数组
    words[*wordCount].freq = 1;                // 新单词的频次设置为1
    (*wordCount)++;                            // 单词计数增加
}

int main() {
    char input[MAX_LENGTH];  // 用于存储输入字符串

    // 读取输入的字符串
    fgets(input, MAX_LENGTH, stdin);

    // 如果输入字符串末尾有换行符，则去掉它
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    WordFreq words[MAX_WORDS];  // 用于存储单词及其频次的数组
    int wordCount = 0;          // 当前存储的单词数量
    int len = strlen(input);    // 输入字符串的长度

    // 遍历输入字符串
    for (int i = 0; i < len; i++) {
        // 如果当前字符是字母
        if (isalpha(input[i])) {
            int j = i;

            // 找到单词的结束位置
            while (j < len && isalpha(input[j])) {
                j++;
            }

            char tempWord[MAX_LENGTH];  // 临时字符串用于存储当前单词
            int wordLen = j - i;       // 计算单词的长度
            strncpy(tempWord, input + i, wordLen);  // 提取单词
            tempWord[wordLen] = '\0';  // 添加字符串结束符

            // 将单词转换为小写字母
            for (int k = 0; k < wordLen; k++) {
                tempWord[k] = tolower(tempWord[k]);
            }

            // 插入单词到单词数组中，统计频次
            insertWord(words, &wordCount, tempWord);

            // 跳过该单词已经处理的部分
            i = j - 1;
        }
    }

    // 使用qsort对单词数组进行排序
    // 排序规则：字典序升序
    qsort(words, wordCount, sizeof(WordFreq), compareWords);

    int maxFreq = 0;        // 最大频次
    char maxWord[MAX_LENGTH]; // 频次最高的单词

    // 遍历已排序的单词数组，找出频次最高的单词
    for (int i = 0; i < wordCount; i++) {
        // 如果当前单词的频次比已知的最大频次更大，则更新最大频次和相应的单词
        if (words[i].freq > maxFreq) {
            maxFreq = words[i].freq;
            strcpy(maxWord, words[i].word);
        }
    }

    // 输出频次最高的单词和它的频次
    printf("%s %d\n", maxWord, maxFreq);

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