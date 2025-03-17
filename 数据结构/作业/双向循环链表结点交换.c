#include <stdio.h>
#include <stdlib.h>

// 双向循环链表节点结构
typedef struct DListNode {
    int val;
    struct DListNode *prev, *next;
} DListNode;

// 创建双向循环链表
DListNode* createDList(int arr[], int size) {
    if (size == 0) return NULL;
    
    DListNode *head = (DListNode*)malloc(sizeof(DListNode));
    head->val = arr[0];
    head->next = head;
    head->prev = head;
    
    DListNode *tail = head;
    for (int i = 1; i < size; i++) {
        DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));
        newNode->val = arr[i];
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    return head;
}

// 释放双向循环链表
void freeDList(DListNode *head) {
    if (!head) return;
    DListNode *curr = head, *nextNode;
    do {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    } while (curr != head);
}

// 交换 p 指向的结点及其前驱结点
DListNode* swapNodes(DListNode *head, int pos) {
    if (!head || pos <= 1) return head; // 不能交换第一个节点
    
    DListNode *p = head;
    for (int i = 1; i < pos; i++) {
        p = p->next;
        if (p == head) return head; // 防止越界
    }
    
    DListNode *prev = p->prev;
    if (prev == head && head->next == head) return head; // 只有一个节点
    
    // 交换前驱和当前节点
    prev->prev->next = p;
    p->next->prev = prev;
    prev->next = p->next;
    p->prev = prev->prev;
    p->next = prev;
    prev->prev = p;
    
    // 如果交换的是头结点，则调整头指针
    if (head == prev) head = p;
    
    return head;
}

// 打印双向循环链表
void printDList(DListNode *head) {
    if (!head) {
        printf("\n");
        return;
    }
    DListNode *curr = head;
    do {
        printf("%d", curr->val);
        curr = curr->next;
        if (curr != head) printf(" ");
    } while (curr != head);
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        int pos;
        scanf("%d", &pos);
        
        DListNode* head = createDList(arr, n);
        head = swapNodes(head, pos);
        printDList(head);
        
        freeDList(head);
    }
    return 0;
}
/*利用双向循环链表表示一个整数序列，指定一个结点位置用p指向该结点，交换p所指向的结点及其前驱结点的顺序*/
