#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent;
    int rank;
};


int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void KruskalMST(struct Edge *edges, int V, int E);


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


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


int compareEdges(const void *a, const void *b) {
    struct Edge *a_edge = (struct Edge *)a;
    struct Edge *b_edge = (struct Edge *)b;
    return a_edge->weight - b_edge->weight;
}


void KruskalMST(struct Edge *edges, int V, int E) {
    struct Edge resultMST[V]; 
    int e = 0; 
    int i = 0; 

   
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));


    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

   
    while (e < V - 1 && i < E) {
        
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        
        if (x != y) {
            resultMST[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

   
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

   
    struct Edge *edges = (struct Edge *)malloc(E * sizeof(struct Edge));

   
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

   
    KruskalMST(edges, V, E);

    free(edges);
    return 0;
}
