#include <stdio.h>
#include <stdlib.h>

//定义链表结构体
typedef struct ListNode {
    int val ;
    struct ListNode *next;
}ListNode;

//创建一个新节点
ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL){
        printf("内存分配失败!\n");
        return NULL;
    }
    newNode ->val = value;
    newNode ->next = NULL;
    return newNode;
}

//在链表头部插入节点
ListNode* insertAtHead(ListNode* head, int value){
    ListNode* newNode = createNode(value);
    newNode ->next = head;
    return newNode;
}

//在链表尾部插入节点
ListNode* insertAtTail(ListNode* head, int value){
    ListNode* newNode = createNode(value);
    if (head == NULL){
        return newNode;
    }
    ListNode* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//根据值删除节点
ListNode* deleteNode(ListNode* head, int value){
    if(head == NULL){
        return head;
    }
    if(head->val == value){
        ListNode* temp = head;
        head = head->next;
        free (temp);
        return head;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr!= NULL && curr->val!= value){
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL){
        prev->next = curr->next;
        free(curr);
    }
    return head;
}

//遍历链表并打印节点值
void printList(ListNode* head){
    ListNode* temp = head;
    while(temp!= NULL){
        printf("%d", temp ->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(void){
    ListNode* head = NULL;
    //在头部插入节点
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    //在尾部插入节点
    head = insertAtTail(head, 7);
    //打印链表
    printList(head);
    //删除节点
    head = deleteNode(head, 2);
    head = deleteNode(head, 3);
    //再次打印链表
    printList(head);

    return 0;
}
