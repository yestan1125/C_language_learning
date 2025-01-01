#include <stdio.h>
#include <stdlib.h>

// 定义队列结构体
typedef struct Queue {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// 创建一个新的队列
Queue* createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// 判断队列是否已满
int isQueueFull(Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// 判断队列是否为空
int isQueueEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

// 入队操作
void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("queue is full\n");
        return;
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

// 出队操作
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("queue is empty no output\n");
        return -1; // 返回一个特殊值表示错误
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return value;
}

// 获取队首元素
int frontElement(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("queue is empty have no head element\n");
        return -1; // 返回一个特殊值表示错误
    }
    return queue->data[queue->front];
}

// 释放队列内存
void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("the first element: %d\n", frontElement(queue));
    printf("element out of the queue: %d\n", dequeue(queue));
    printf("the first element: %d\n", frontElement(queue));

    freeQueue(queue);
    return 0;
}