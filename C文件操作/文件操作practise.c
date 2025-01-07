#include <stdio.h>

int main() {
    // 打开文件进行写入操作
    FILE *file = fopen("example.txt", "w");  // 打开文件，写入模式
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;  // 文件打开失败
    }

    // 向文件写入字符串
    fputs("Hello, World!\n", file);  
    // 向文件写入单个字符
    fputc('A', file);  

    // 关闭文件（写入完成）
    fclose(file);  

    // 打开文件进行读取操作
    file = fopen("example.txt", "r");  // 打开文件，读取模式
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;  // 文件打开失败
    }

    // 读取并显示文件内容
    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {  // 逐字符读取文件内容
        putchar(ch);  // 输出字符
    }

    // 关闭文件（读取完成）
    fclose(file);

    return 0;
}

/*如果要操作的文件和该.c文件在同一目录则只需要相对路径,其他则需要绝对路径*/
