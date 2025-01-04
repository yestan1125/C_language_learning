#include <stdio.h>

int main()
{
    int m , n;
    scanf("%d %d", &m, &n);
    int book[m];//字典
    for(int i = 0; i<m; i++)
    {
        book[i] = 0;
    }
    int word[n];//输入的单词
    for(int i = 0; i<n; i++)
    {
       scanf("%d", &word[i]);
    }
    int count = 0;//计数器
    int head = 0 , tail = 0;//字典头尾指针
    for(int i = 0; i<n; i++){
        int found = 0;//是否找到
        for(int j = head; j<=tail; j++){//从字典的头到尾
            if(book[j%m] == word[i]){
                found = 1;
                break;
            }
        }
        if(!found){
            count++;//计数器加一
            book[tail%m] = book[i];//写入字典
            tail++;//字典尾部指针后移
            if(tail-head == m){//字典满了
                head++;//字典头部指针后移
        }
    }
    }
    printf("%d\n", count);
    return 0;
}
