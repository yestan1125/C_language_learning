#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of nodes in the graph
#define MAX_NODES 100

// Queue structure
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    // 将队首指针设置为0，表示队列为空
    q->front = 0;
    // 将队尾指针设置为-1，表示队列为空
    q->rear = -1;
}

// Enqueue
void enqueue(Queue* q, int item) {
    // 如果队尾指针等于队列最大容量减一，表示队列已满
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        // 队尾指针后移一位，并将元素插入队尾
        q->items[++(q->rear)] = item;
    }
}

// Dequeue
int dequeue(Queue* q) {
    // 如果队首指针大于队尾指针，表示队列为空
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        // 返回-1表示队列为空
        return -1;
    } else {
        // 返回队首元素，并将队首指针后移一位
        return q->items[(q->front++)];
    }
}

// Check if the queue is empty
bool isQueueEmpty(Queue* q) {
    // 通过比较队首指针和队尾指针的位置来判断队列是否为空
    // 如果队首指针大于队尾指针，表示队列为空
    return q->front > q->rear;
}

// Breadth-First Search (BFS) algorithm
void bfs(int graph[MAX_NODES][MAX_NODES], int start, int target, int n) {
    // 创建一个布尔数组来跟踪已访问的节点，初始化为false
    bool visited[MAX_NODES] = {false};
    // 创建一个数组来存储最短路径中的父节点
    int parent[MAX_NODES];
    // 创建一个队列用于BFS
    Queue q;
    // 初始化队列
    initQueue(&q);
    
    // 将起始节点入队
    enqueue(&q, start);
    // 标记起始节点为已访问
    visited[start] = true;
    // 起始节点没有父节点，设置为-1
    parent[start] = -1;

    // 当队列不为空时，继续搜索
    while (!isQueueEmpty(&q)) {
        // 从队列中取出一个节点
        int node = dequeue(&q);

        // 如果找到了目标节点，输出路径
        if (node == target) {
            printf("The shortest path from node %d to node %d is: ", start, target);
            // 创建一个数组来存储路径
            int path[MAX_NODES];
            // 初始化路径长度为0
            int path_length = 0;
            // 从目标节点开始，回溯到起始节点，构建路径
            for (int v = target; v != -1; v = parent[v]) {
                path[path_length++] = v;
            }
            // 输出路径
            for (int i = path_length - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
            // 找到路径后返回
            return;
        }

        // 遍历当前节点的所有邻居
        for (int i = 0; i < n; i++) {
            // 如果存在边且邻居节点未被访问
            if (graph[node][i] == 1 && !visited[i]) {
                // 将邻居节点入队
                enqueue(&q, i);
                // 标记邻居节点为已访问
                visited[i] = true;
                // 设置邻居节点的父节点为当前节点
                parent[i] = node;
            }
        }
    }
    // 如果没有找到路径，输出提示信息
    printf("No path exists from node %d to node %d\n", start, target);
}

int main() {
    // Example graph represented by an adjacency matrix (unweighted graph)
    int graph[MAX_NODES][MAX_NODES] = {0};

    // Graph edges (undirected graph)
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[0][4] = 1;
    graph[4][0] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;

    int start = 0;  // Start node
    int target = 3;  // Target node
    int n = 5;  // Number of nodes in the graph

    // Call BFS to find the shortest path
    bfs(graph, start, target, n);

    return 0;
}
