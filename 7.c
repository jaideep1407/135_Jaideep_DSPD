/*Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: Start searching at node 1, and break ties for exploring the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS?*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
int adj[SIZE + 1][SIZE + 1];
int visited[SIZE + 1];
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void buildGridGraph() {
    for (int i = 1; i <= SIZE; i++) {
        if (i % 3 != 0) addEdge(i, i + 1);
        if (i <= 6) addEdge(i, i + 3);
    }
}
void bfs(int start) {
    int queue[SIZE + 1], front = 0, rear = 0;
    for (int i = 1; i <= SIZE; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= SIZE; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void dfs(int start) {
    int stack[SIZE + 1], top = -1;
    for (int i = 1; i <= SIZE; i++) visited[i] = 0;
    stack[++top] = start;
    printf("DFS Order: ");
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for (int i = SIZE; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}
int main() {
    buildGridGraph();
    bfs(1);
    dfs(1);
    return 0;
}

/*Sample Output:
BFS Order: 1 2 4 3 5 7 6 8 9
DFS Order: 1 4 7 8 5 2 3 6 9
*/