#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

void print_solution(int dist[][V]);
void floyd_warshall_static(int graph[][V]);
void floyd_warshall_dynamic(int graph[][V], int k);
int min_distance(int dist[], int spt_set[]);
void print_path(int parent[], int j);
void print_solution_dijkstra(int dist[], int n, int parent[]);
void dijkstra_static(int graph[V][V], int src);

int main() {
    int static_graph[V][V] = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    int dynamic_graph[V][V] = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, 6, INT_MAX, 0}
    };

    int choice, k;

    system("cls");

    printf("Menu:\n");
    printf("1) Shortest Path Static Graph Warshall\n");
    printf("2) Shortest Path Dynamic Graph Warshall\n");
    printf("3) Shortest Path Static Graph Dijkstra\n");
    printf("4) Shortest Path Dynamic Graph Dijkstra\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            floyd_warshall_static(static_graph);
            break;
        case 2:
            printf("Masukkan nilai K: ");
            scanf("%d", &k);
            floyd_warshall_dynamic(dynamic_graph, k);
            break;
        case 3:
            dijkstra_static(static_graph, 0);
            break;
        case 4:
            dijkstra_static(dynamic_graph, 0);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }

    return 0;
}

void print_solution(int dist[][V]) {
    printf("Jarak terpendek antara setiap pasangan simpul:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall_static(int graph[][V]) {
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    print_solution(dist);
}

void floyd_warshall_dynamic(int graph[][V], int k) {
    int dist[V][V], i, j, l;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (l = 0; l < k; l++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][l] != INT_MAX && dist[l][j] != INT_MAX
                    && dist[i][l] + dist[l][j] < dist[i][j])
                    dist[i][j] = dist[i][l] + dist[l][j];
            }
        }
    }

    print_solution(dist);
}

int min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (spt_set[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void print_path(int parent[], int j) {
    if (parent[j] == -1)
        return;

    print_path(parent, parent[j]);

    printf("%d ", j);
}

void print_solution_dijkstra(int dist[], int n, int parent[]) {
    int src = 0;
    printf("Simpul\t\tJarak\t\tPath");
    for (int i = 1; i < V; i++) {
        printf("\n%d -> %d \t\t%d\t\t%d ", src, i, dist[i], src);
        print_path(parent, i);
    }
}

void dijkstra_static(int graph[V][V], int src) {
    int dist[V];
    int spt_set[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
        parent[0] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set);

        spt_set[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    print_solution_dijkstra(dist, V, parent);
}
