#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 单链表节点结构
typedef struct ListNode {
    char val;
    struct ListNode *next;
} ListNode;

// 创建单链表
ListNode* createList(char arr[], int size) {
    ListNode *head = (ListNode*)malloc(sizeof(ListNode)); // 头结点
    head->next = NULL;
    ListNode *tail = head;
    
    for (int i = 0; i < size; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 释放单链表
void freeList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        ListNode *nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

// 获取链表长度
int getLength(ListNode *head) {
    int len = 0;
    ListNode *curr = head->next;
    while (curr) {
        len++;
        curr = curr->next;
    }
    return len;
}

// 查找共同后缀起始位置的结点
ListNode* findCommonSuffix(ListNode *str1, ListNode *str2) {
    int len1 = getLength(str1), len2 = getLength(str2);
    ListNode *p1 = str1->next, *p2 = str2->next;
    
    // 对齐较长链表的指针
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++) p2 = p2->next;
    }
    
    // 找到共同后缀起始位置
    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        char arr1[n], arr2[m];
        for (int i = 0; i < n; i++) scanf(" %c", &arr1[i]);
        for (int i = 0; i < m; i++) scanf(" %c", &arr2[i]);
        
        ListNode *str1 = createList(arr1, n);
        ListNode *str2 = createList(arr2, m);
        
        ListNode *commonNode = findCommonSuffix(str1, str2);
        if (commonNode) printf("%c\n", commonNode->val);
        
        freeList(str1);
        freeList(str2);
    }
    return 0;
}
