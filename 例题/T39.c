#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000     // 输入字符串的最大长度
#define MAX_WORDS 1000   // 最大单词数量

// 排序比较函数：按频次降序排序，频次相同按字典序升序
int compare(const void *a, const void *b) {
    // 提取频次信息
    int countA = ((int*)a)[1], countB = ((int*)b)[1];
    
    // 如果频次不同，按频次降序排序
    if (countA != countB) return countB - countA;
    
    // 如果频次相同，按字典序升序排序
    return strcmp(((char**)a)[0], ((char**)b)[0]);
}

// 处理输入字符串，统计单词频次
int processInput(char *input, char *words[MAX_WORDS], int counts[MAX_WORDS]) {
    char word[50];  // 临时存储每个单词
    int len = 0, size = 0;  // len 用来记录当前单词的长度，size 用来记录已有单词数量

    // 遍历输入字符串
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            // 如果是字母，转换为小写并加入当前单词
            word[len++] = tolower(input[i]);
        } else if (len > 0) {
            // 如果遇到非字母字符并且当前单词已结束
            word[len] = '\0';  // 终止当前单词
            len = 0;           // 重置单词长度
            
            int found = 0;
            // 查找当前单词是否已存在
            for (int j = 0; j < size; j++) {
                if (strcmp(words[j], word) == 0) {  // 找到相同的单词
                    counts[j]++;  // 频次加1
                    found = 1;
                    break;
                }
            }
            // 如果该单词不存在，添加到单词数组并初始化频次为1
            if (!found) {
                words[size] = strdup(word);  // 将单词复制到动态内存
                counts[size++] = 1;  // 初始化频次为1，并增加单词数量
            }
        }
    }
    
    // 处理输入字符串最后一个单词
    if (len > 0) {
        word[len] = '\0';  // 终止最后一个单词
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (strcmp(words[j], word) == 0) {  // 找到相同的单词
                counts[j]++;  // 频次加1
                found = 1;
                break;
            }
        }
        if (!found) {
            words[size] = strdup(word);  // 新单词，复制到数组
            counts[size++] = 1;  // 初始化频次为1
        }
    }
    return size;  // 返回已处理的单词数量
}

int main() {
    char input[MAX_LEN];  // 用于存储输入字符串
    char *words[MAX_WORDS];  // 用于存储单词
    int counts[MAX_WORDS];   // 用于存储每个单词的频次

    // 从标准输入读取一行字符串
    fgets(input, sizeof(input), stdin);

    // 处理输入字符串，统计每个单词的频次
    int size = processInput(input, words, counts);

    // 使用 qsort 排序单词，根据频次降序，频次相同按字典序升序
    qsort(words, size, sizeof(char*), compare);

    // 输出出现频次最多的单词及其频次
    printf("%s %d\n", words[0], counts[0]);

    // 释放动态分配的内存
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
