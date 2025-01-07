#include <stdio.h>
#include <stdlib.h>

// 定义图的结构
#define MAX_VERTICES 100

// 邻接表的结构
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];  // 邻接表数组
    int numVertices;              // 图的顶点数
} Graph;

// 创建一个图
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// 向图中添加边
void addEdge(Graph* graph, int src, int dest) {
    // 添加从src到dest的边
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // 添加从dest到src的边（无向图）
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// 深度优先搜索DFS
void DFS(Graph* graph, int startVertex, int* visited) {
    // 标记当前节点为已访问
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    // 访问邻接的节点
    Node* adjList = graph->adjList[startVertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    int visited[MAX_VERTICES] = {0};  // 初始化访问标记数组

    printf("深度优先搜索（DFS）遍历结果: ");
    DFS(graph, 0, visited);  // 从节点0开始DFS
    printf("\n");

    return 0;
}
/*just a very easy example*/
