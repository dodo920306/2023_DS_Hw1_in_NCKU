#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void * a, const void * b);

struct Edge {
    int s;
    int t;
    int cost;
};

int cmpfunc(const void * a, const void * b)
{
   return (((struct Edge*)a)->cost - ((struct Edge*)b)->cost);
}

int main(int argc, char* argv[]) {
    int v = 0, e = 0;
    if (scanf("%d %d", &v, &e) != 2)    return 1;
    int *parent = malloc(v * sizeof(int)), *rank = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    struct Edge *edges = malloc(e * sizeof(struct Edge));
    for (int i = 0, s = 0, t = 0, cost = 0; i < e; i++) {
        if (scanf("%d %d %d", &s, &t, &cost) != 3)  return 1;
        edges[i].s = s;
        edges[i].t = t;
        edges[i].cost = cost;
        s = 0, t = 0, cost = 0;
    }

    qsort(edges, e, sizeof(edges[0]), cmpfunc);

    unsigned long long sum = 0;
    for (int i = 0; i < e; i++) {
        int s = edges[i].s, t = edges[i].t, cost = edges[i].cost;
        /* find root */
        while (parent[s] != -1) {
            s = parent[s];
        }
        while (parent[t] != -1) {
            t = parent[t];
        }
        /* build set */
        if (s != t) {
            if (rank[s] < rank[t]) {
                parent[s] = t;
            }
            else {
                parent[t] = s;
                if (rank[s] == rank[t])   rank[s]++;
            }
            sum += cost;
        }
    }
    free(parent);
    free(rank);
    free(edges);
    printf("%lld\n", sum);
    return 0;
}
