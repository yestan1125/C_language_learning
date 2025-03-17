#include <stdio.h>
#include <stdlib.h>

// 定义循环链表节点
typedef struct Node {
    int id;
    struct Node *next;
} Node;

// 创建单向循环链表
Node* createCircularList(int m) {
    Node *head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    Node *prev = head;

    for (int i = 2; i <= m; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->id = i;
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // 形成循环链表
    return head;
}

// 约瑟夫环算法，模拟猴子出圈
void josephus(int m, int n) {
    if (m == 0 || n == 0) return;

    Node *head = createCircularList(m);
    Node *prev = head;

    // 找到最后一个节点（它的 next 指向 head）
    while (prev->next != head) {
        prev = prev->next;
    }

    // 模拟出圈过程
    while (prev != prev->next) {
        // 找到待删除节点的前一个节点
        for (int i = 1; i < n; i++) {
            prev = prev->next;
        }
        
        // 要删除的节点
        Node *toDelete = prev->next;
        printf("%d ", toDelete->id);

        // 删除节点
        prev->next = toDelete->next;
        free(toDelete);
    }

    // 输出最后剩下的猴子
    printf("%d\n", prev->id);
    free(prev);
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2 && (m != 0 || n != 0)) {
        josephus(m, n);
    }
    return 0;
}
