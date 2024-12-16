#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10


void bfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false}; 
    int queue[MAX_NODES], front = 0, rear = 0; 


    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {

        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}


void dfsUtil(int graph[MAX_NODES][MAX_NODES], int current, bool visited[], int num_nodes) {
    visited[current] = true;
    printf("%d ", current);

 
    for (int i = 0; i < num_nodes; i++) {
        if (graph[current][i] && !visited[i]) {
            dfsUtil(graph, i, visited, num_nodes);
        }
    }
}

void dfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false}; 
    printf("DFS Traversal: ");
    dfsUtil(graph, start, visited, num_nodes);
    printf("\n");
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    int start = 0;  
    int num_nodes = 5;

    bfs(graph, start, num_nodes);
    dfs(graph, start, num_nodes);

    return 0;
}
