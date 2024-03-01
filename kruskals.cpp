#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_VERTICES 100
struct Edge {
int src, dest, weight;
};
struct Subset {
int parent;
int rank;
};
int find(Subset subsets[], int i) {
if (subsets[i].parent != i)
subsets[i].parent = find(subsets, subsets[i].parent);
return subsets[i].parent;
}
void Union(Subset subsets[], int x, int y) {
int xroot = find(subsets, x);
int yroot = find(subsets, y);
if(subsets[xroot].rank < subsets[yroot].rank)
subsets[xroot].parent = yroot;
else if (subsets[xroot].rank > subsets[yroot].rank)
subsets[yroot].parent = xroot;
else
{
subsets[yroot].parent = xroot;
subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(Edge edges[], int V, int E) {
Edge result[V];
int e = 0;
int i = 0;
qsort(edges, E, sizeof(edges[0]), myComp);
Subset* subsets = new Subset[V];
for(int v = 0; v < V; v++)
{
subsets[v].parent = v;
subsets[v].rank = 0;
}
while (e < V - 1 && i < E) {
Edge next_edge = edges[i++];
int x = find(subsets, next_edge.src);
int y = find(subsets, next_edge.dest);
if (x != y) {
result[e++] = next_edge;
Union(subsets, x, y);
}
}
cout << "Edges in the MST:" << endl;
for (i = 0; i < e; i++) {
cout << result[i].src << " -- " << result[i].dest << " with weight " << result[i].weight << endl;
}
delete[] subsets;
}

int main() {
int V = 4;
int E = 5;
Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
};
KruskalMST(edges, V, E);
return 0;
}
