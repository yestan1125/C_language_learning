#include "linkedlist.h"

// ========================= 单链表函数 ===========================
NodeList* insertHead(NodeList* head, int data) {
    NodeList* node = (NodeList*)malloc(sizeof(NodeList));
    node->data = data;
    node->next = head;
    return node;
}

NodeList* insertTail(NodeList* head, int data) {
    NodeList* node = (NodeList*)malloc(sizeof(NodeList));
    node->data = data;
    node->next = NULL;
    if (head == NULL) return node;

    NodeList* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
    return head;
}

NodeList* deleteByValue(NodeList* head, int data) {
    if (head == NULL) return NULL;
    if (head->data == data) {
        NodeList* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    NodeList* prev = head;
    NodeList* curr = head->next;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
    return head;
}

void printList(NodeList* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(NodeList* head) {
    while (head != NULL) {
        NodeList* temp = head;
        head = head->next;
        free(temp);
    }
}

// ======================= 双向链表函数 ===========================
DNodeList* insertHeadD(DNodeList* head, int data) {
    DNodeList* node = (DNodeList*)malloc(sizeof(DNodeList));
    node->data = data;
    node->next = head;
    node->prev = NULL;
    if (head != NULL) head->prev = node;
    return node;
}

DNodeList* insertTailD(DNodeList* head, int data) {
    DNodeList* node = (DNodeList*)malloc(sizeof(DNodeList));
    node->data = data;
    node->next = NULL;

    if (head == NULL) return node;

    DNodeList* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

void printListD(DNodeList* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeListD(DNodeList* head) {
    while (head != NULL) {
        DNodeList* temp = head;
        head = head->next;
        free(temp);
    }
}

// ====================== 循环链表函数 ===========================
CNodeList* insertHeadC(CNodeList* head, int data) {
    CNodeList* node = (CNodeList*)malloc(sizeof(CNodeList));
    node->data = data;
    node->next = head ? head : node;

    if (head == NULL) {
        return node;
    }

    CNodeList* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = node;
    return node;
}

int hasCycle(CNodeList* head) {
    if (head == NULL) return 0;
    CNodeList *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void printListC(CNodeList* head) {
    if (head == NULL) return;
    CNodeList* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void freeListC(CNodeList* head) {
    if (head == NULL) return;
    CNodeList* temp = head;
    CNodeList* nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}
