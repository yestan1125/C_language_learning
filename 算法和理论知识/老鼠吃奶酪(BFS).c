#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int n, k;
int cheese[MAX_N][MAX_N];  // 存储奶酪数量
int visited[MAX_N][MAX_N];  // 记录是否访问过

// 四个方向的偏移量，分别表示上、下、左、右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS 队列
typedef struct {
    int x, y, cheese_sum;
} State;

State queue[MAX_N * MAX_N];
int front, rear;

void bfs() {
    // 初始化 BFS 队列
    front = 0;
    rear = 0;
    queue[rear++] = (State){0, 0, cheese[0][0]};  // 从 (0, 0) 开始
    visited[0][0] = 1;  // 标记 (0, 0) 已经访问过

    int max_cheese = cheese[0][0];  // 初始化最大奶酪总量

    while (front < rear) {
        State current = queue[front++];
        
        // 试图在四个方向上移动
        for (int dir = 0; dir < 4; dir++) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];

            // 检查是否越界
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 计算当前位置奶酪总量
            int new_cheese_sum = current.cheese_sum + cheese[nx][ny];

            // 如果这个地方的奶酪多于当前地方且没有超过最大步数限制
            if (cheese[nx][ny] > cheese[current.x][current.y] && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                queue[rear++] = (State){nx, ny, new_cheese_sum};
                max_cheese = (new_cheese_sum > max_cheese) ? new_cheese_sum : max_cheese;
            }
        }
    }

    printf("%d\n", max_cheese);
}

int main() {
    // 输入
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cheese[i][j]);
        }
    }

    // BFS 计算最大奶酪总量
    memset(visited, 0, sizeof(visited));  // 清空访问记录
    bfs();

    return 0;
}
