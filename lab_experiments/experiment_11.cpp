#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX


int findMinDistance(int dist[], int visited[], int num_nodes) {
    int min = INF, min_index;

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}


void dijkstra(int graph[MAX_NODES][MAX_NODES], int source, int num_nodes) {
    int dist[MAX_NODES];    
    int visited[MAX_NODES];   
  
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    
    dist[source] = 0;

    
    for (int count = 0; count < num_nodes - 1; count++) {
        int u = findMinDistance(dist, visited, num_nodes); 
        visited[u] = 1;

        
        for (int v = 0; v < num_nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < num_nodes; i++) {
        if (dist[i] == INF) {
            printf("Node %d: INF\n", i);
        } else {
            printf("Node %d: %d\n", i, dist[i]);
        }
    }
}


int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {0, 0, 0, 0, 9, 0}
    };

    int source = 0;
    int num_nodes = 6;

    dijkstra(graph, source, num_nodes);

    return 0;
}
