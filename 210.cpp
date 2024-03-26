#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void KruskalMST(struct Edge *edges, int V, int E);

// Find set of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Perform Union of two sets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges based on their weight
int compareEdges(const void *a, const void *b) {
    struct Edge *a_edge = (struct Edge *)a;
    struct Edge *b_edge = (struct Edge *)b;
    return a_edge->weight - b_edge->weight;
}

// Function to find the Minimum Spanning Tree (MST) of a graph
void KruskalMST(struct Edge *edges, int V, int E) {
    struct Edge resultMST[V]; // Array to store the MST edges
    int e = 0; // Index variable for resultMST
    int i = 0; // Index variable for sorted edges array

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding edges until there are V-1 edges in the resultMST
    while (e < V - 1 && i < E) {
        // Pick the smallest edge
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not form a cycle, include it in the resultMST and increment the index
        if (x != y) {
            resultMST[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of MST
    printf("Edges of Minimum Spanning Tree (MST):\n");
    for (int j = 0; j < e; j++)
        printf("%d -- %d  Weight: %d\n", resultMST[j].src, resultMST[j].dest, resultMST[j].weight);

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    // Create an array of edges
    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));

    // Input each edge details
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    // Find Minimum Spanning Tree (MST)
    KruskalMST(edges, V, E);

    free(edges);
    return 0;
}

