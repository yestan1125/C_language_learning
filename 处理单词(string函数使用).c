//给定一个由英文字符、数字、空格和英文标点符号组成的字符串。
//长度不超过2000，请将其切分为单词，要求去掉所有的非英文字母，每行输出一个单词。
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 2000

int main() {
    char str[MAX_LEN];
    // 获取输入的字符串
    fgets(str, MAX_LEN, stdin);
    // 去除字符串末尾可能存在的换行符
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int i = 0;
    int len = strlen(str);
    while (i < len) {
        // 跳过前面的非英文字母字符，找到单词开头
        while (i < len &&!isalpha(str[i])) {
            i++;
        }

        int start = i;
        // 找到单词结尾，只要当前字符是英文字母就继续往后找
        while (i < len && isalpha(str[i])) {
            i++;
        }

        if (start < i) {
            char word[MAX_LEN];
            // 将找到的单词复制到新的字符数组word中
            strncpy(word, str + start, i - start);
            word[i - start] = '\0';
            // 输出单词，每行输出一个
            printf("%s\n", word);
        }
    }

    return 0;
}