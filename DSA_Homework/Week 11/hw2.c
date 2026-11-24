
#include <stdio.h>
#include <limits.h>

#define N 6

int graph[N][N] = {

    {0, 7, 5, 0, 0, 1},
    {7, 0, 1, 1, 3, 0},
    {5, 1, 0, 2, 1, 0},
    {0, 1, 2, 0, 0, 7},
    {0, 3, 1, 0, 0, 2},
    {1, 0, 0, 7, 2, 0}

};


// DIJKSTRA ALGORITHM

void dijkstra(int graph[N][N], int start,
              int distance[N], int path[N]) {

    int known[N] = {0};
    int i, j, v, u, min;

    for(i = 0; i < N; i++) {
        distance[i] = INT_MAX;
        path[i] = -1;
    }

    distance[start] = 0;

    for(i = 0; i < N; i++) {

        min = INT_MAX;
        u = -1;

        // Find minimum distance node

        for(j = 0; j < N; j++) {

            if(known[j] == 0 && distance[j] < min) {

                min = distance[j];
                u = j;

            }
        }

        if(u == -1)
            break;

        known[u] = 1;

        // Update neighboring nodes

        for(v = 0; v < N; v++) {

            if(graph[u][v] != 0 && known[v] == 0) {

                if(distance[u] + graph[u][v] < distance[v]) {

                    distance[v] = distance[u] + graph[u][v];

                    path[v] = u;

                }
            }
        }
    }
}


// PRINT SHORTEST PATH

void printPath(int path[N], int start, int end) {

    int stack[N];
    int top = -1;
    int current;

    current = end;

    // Read path backwards

    while(current != -1) {

        stack[++top] = current;

        if(current == start)
            break;

        current = path[current];

    }

    // Check path availability

    if(top == -1 || stack[top] != start) {

        printf("No path");
        return;

    }

    // Print path in correct order

    while(top >= 0) {

        printf("%c", stack[top--] + 'A');

        if(top >= 0)
            printf(" -> ");

    }
}


// MAIN FUNCTION

int main() {

    int distance[N];
    int path[N];

    int centralNode;
    int minTotal;

    int i, j;
    int total;

    int dist[N];
    int previous[N];


    // RUN DIJKSTRA FROM A

    dijkstra(graph, 0, distance, path);

    printf("A to B route: ");
    printPath(path, 0, 1);
    printf("\nDistance: %d\n", distance[1]);

    printf("\nA to D route: ");
    printPath(path, 0, 3);
    printf("\nDistance: %d\n", distance[3]);


    // CENTRAL NODE DETECTION

    centralNode = -1;
    minTotal = INT_MAX;

    for(i = 0; i < N; i++) {

        // Run Dijkstra from each node

        dijkstra(graph, i, dist, previous);

        total = 0;

        // Calculate total shortest path cost

        for(j = 0; j < N; j++) {

            if(dist[j] != INT_MAX) {

                total += dist[j];

            }
        }

        printf("Total cost from %c: %d\n",
               'A' + i, total);

        // Find central node

        if(total < minTotal) {

            minTotal = total;
            centralNode = i;

        }
    }

    printf("\nCentral Node: %c\n", 'A' + centralNode);

    printf("Minimum Total Cost: %d\n", minTotal);


    return 0;
}

