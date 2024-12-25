#include <stdio.h>
#include <stdlib.h>

//定义链表节点结构体
typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

//创建循环链表
ListNode* creatCircleList(int n){
    if (n <= 0) return 0;
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head -> val = 1;
    ListNode *prev = head;
    for(int i = 2; i <= n; i++){
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode -> val = i;
        prev -> next = newNode;
        prev = newNode;
    }
    prev -> next = head;
    return head;
}

//约瑟夫环算法实现
void josephus (int n, int m){
    ListNode *head = creatCircleList(n);
    ListNode *p = head;
    ListNode *prev;
    while (p -> next != p){
        for(int i = 1; i < m; i++){
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
       // printf("%d ",p->val);//每次报数的人
        free(p);
        p = prev -> next;
    }
    printf("%d\n", p->val);
    free(p);
}

int main(){
    int n;   //总人数
    int m;   //报数数字
    printf("please input the number");
    scanf("%d %d",&n, &m);
    josephus(n,m);
    return 0;
}