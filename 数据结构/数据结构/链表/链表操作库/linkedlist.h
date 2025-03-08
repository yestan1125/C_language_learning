#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// ================== 单链表结构 ==================
typedef struct NodeList {
    int data;
    struct NodeList* next;
} NodeList;

// ================== 双向链表结构 ==================
typedef struct DNodeList {
    int data;
    struct DNodeList* next;
    struct DNodeList* prev;
} DNodeList;

// ================== 单向循环链表结构 ==================
typedef struct CNodeList {
    int data;
    struct CNodeList* next;
} CNodeList;

// ========== 单链表函数 ==========
NodeList* insertHead(NodeList* head, int data);
NodeList* insertTail(NodeList* head, int data);
NodeList* deleteByValue(NodeList* head, int data);
NodeList* reverseList(NodeList* head);
void printList(NodeList* head);
void freeList(NodeList* head);

// ========== 双向链表函数 ==========
DNodeList* insertHeadD(DNodeList* head, int data);
DNodeList* insertTailD(DNodeList* head, int data);
DNodeList* deleteByValueD(DNodeList* head, int data);
DNodeList* reverseListD(DNodeList* head);
void printListD(DNodeList* head);
void freeListD(DNodeList* head);

// ========== 循环链表函数 ==========
CNodeList* insertHeadC(CNodeList* head, int data);
CNodeList* insertTailC(CNodeList* head, int data);
CNodeList* deleteByValueC(CNodeList* head, int data);
int hasCycle(CNodeList* head);
void printListC(CNodeList* head);
void freeListC(CNodeList* head);

#endif
