#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建链表节点
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 释放链表
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// 合并两个非递减链表，结果为非递增链表
ListNode* mergeSortedLists(ListNode* l1, ListNode* l2) {
    ListNode* merged = NULL; // 结果链表头部
    
    while (l1 && l2) {
        ListNode* temp;
        if (l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }
        temp->next = merged;
        merged = temp;
    }
    
    while (l1) {
        ListNode* temp = l1;
        l1 = l1->next;
        temp->next = merged;
        merged = temp;
    }
    
    while (l2) {
        ListNode* temp = l2;
        l2 = l2->next;
        temp->next = merged;
        merged = temp;
    }
    
    return merged;
}

// 读取输入并创建链表
ListNode* readList(int size) {
    if (size == 0) return NULL;
    
    int val;
    scanf("%d", &val);
    ListNode* head = createNode(val);
    ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        scanf("%d", &val);
        current->next = createNode(val);
        current = current->next;
    }
    
    return head;
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        head = head->next;
        if (head) printf(" ");
    }
    printf("\n");
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        ListNode* list1 = readList(n);
        ListNode* list2 = readList(m);
        
        ListNode* merged = mergeSortedLists(list1, list2);
        printList(merged);
        
        freeList(merged);
    }
    return 0;
}
