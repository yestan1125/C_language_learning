#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链表节点结构体
typedef struct ListNode {
    char val;
    struct ListNode *next;
} ListNode;

// 创建新节点
ListNode* createNode(char val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 根据输入创建链表
ListNode* createLinkedList(int n) {
    ListNode *dummy = createNode('\0');
    ListNode *current = dummy;
    for (int i = 0; i < n; i++) {
        char val;
        scanf(" %c", &val);
        current->next = createNode(val);
        current = current->next;
    }
    return dummy->next;
}

// 计算链表长度
int getLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

// 找到共同后缀的起始位置
char findCommonSuffixStart(ListNode* str1, ListNode* str2) {
    int len1 = getLength(str1);
    int len2 = getLength(str2);

    ListNode *p1 = str1;
    ListNode *p2 = str2;

    // 让较长的链表先走差值步
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff > 0) {
            p1 = p1->next;
            diff--;
        }
    } else {
        int diff = len2 - len1;
        while (diff > 0) {
            p2 = p2->next;
            diff--;
        }
    }

    // 同时遍历两个链表，找到共同后缀的起始位置
    while (p1 && p2) {
        if (p1->val == p2->val) {
            return p1->val;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return '\0';
}

// 释放链表内存
void freeLinkedList(ListNode* head) {
    ListNode* current = head;
    ListNode* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        ListNode* str1 = createLinkedList(n);
        ListNode* str2 = createLinkedList(m);

        char result = findCommonSuffixStart(str1, str2);
        printf("%c\n", result);

        freeLinkedList(str1);
        freeLinkedList(str2);
    }

    return 0;
}
