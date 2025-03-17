#include <stdio.h>
#include <stdlib.h>

// 定义单链表结构
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建链表
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;
    ListNode *tail = head;

    for (int i = 1; i < size; i++) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 释放链表
void freeList(ListNode *head) {
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 重新排列链表：奇数索引节点在前，偶数索引节点在后
ListNode* oddEvenList(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *odd = head, *even = head->next, *even_head = even;
    
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head; // 连接奇数部分和偶数部分
    return head;
}

// 打印链表
void printList(ListNode *head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        ListNode *head = createList(arr, n);
        head = oddEvenList(head);
        printList(head);

        freeList(head);
    }
    return 0;
}
