#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // 哈希表大小

// 哈希表节点结构体
typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

// 哈希表结构体
typedef struct HashTable {
    Node *table[TABLE_SIZE];  // 哈希表数组，每个元素是链表的头指针
} HashTable;

// 哈希函数：使用除法法则，将key映射到0到TABLE_SIZE-1之间
int hash(int key) {
    return key % TABLE_SIZE;
}

// 创建哈希表
HashTable* createHashTable() {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;  // 初始化每个哈希桶为空
    }
    return ht;
}

// 插入数据到哈希表
void insert(HashTable *ht, int key, int value) {
    int index = hash(key);  // 计算哈希值
    Node *newNode = (Node *)malloc(sizeof(Node));  // 创建新节点
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // 如果桶内为空，直接插入
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        // 如果桶内已经有元素，插入到链表头部
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

// 查找哈希表中的元素
int search(HashTable *ht, int key) {
    int index = hash(key);
    Node *current = ht->table[index];

    // 遍历链表，查找指定key
    while (current != NULL) {
        if (current->key == key) {
            return current->value;  // 找到键对应的值
        }
        current = current->next;
    }

    return -1;  // 未找到
}

// 删除哈希表中的元素
void deleteKey(HashTable *ht, int key) {
    int index = hash(key);
    Node *current = ht->table[index];
    Node *prev = NULL;

    // 遍历链表，找到要删除的节点
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                // 删除的是链表头部节点
                ht->table[index] = current->next;
            } else {
                // 删除的是链表中的中间节点
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Key %d not found for deletion.\n", key);
}

// 打印哈希表
void printHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        printf("Bucket %d: ", i);
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// 释放哈希表内存
void freeHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

// 主函数：测试哈希表操作
int main() {
    // 创建哈希表
    HashTable *ht = createHashTable();

    // 插入一些数据
    insert(ht, 1, 100);
    insert(ht, 2, 200);
    insert(ht, 11, 1100);
    insert(ht, 22, 2200);
    insert(ht, 5, 500);

    // 打印哈希表内容
    printHashTable(ht);

    // 查找数据
    int value = search(ht, 11);
    if (value != -1) {
        printf("Found key 11 with value %d.\n", value);
    } else {
        printf("Key 11 not found.\n");
    }

    // 删除数据
    deleteKey(ht, 2);
    deleteKey(ht, 22);

    // 打印哈希表内容
    printHashTable(ht);

    // 释放哈希表内存
    freeHashTable(ht);

    return 0;
}
