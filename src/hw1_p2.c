#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int cases = 0, n = 0, ops = 0;
    if (scanf("%d", &cases) != 1) return 1;
    for (int i = 0; i < cases; i++) {
        if (scanf("%d %d", &n, &ops) != 2) return 1;
        int *parent = malloc(n * sizeof(int)), *rank = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            parent[j] = -1;
            rank[j] = 0;
        }
        for (int j = 0; j < ops; j++) {
            char *op = malloc(6 * sizeof(char));
            if (scanf("%s", op) != 1) return 1;
            if (!strncmp(op, "union", 5)) {
                int arg1 = 0, arg2 = 0;
                if (scanf("%d %d", &arg1, &arg2) != 2) return 1;
                /* find root */
                while (parent[arg1] != -1) {
                    arg1 = parent[arg1];
                }
                while (parent[arg2] != -1) {
                    arg2 = parent[arg2];
                }
                if (arg1 != arg2) {
                    if (rank[arg1] < rank[arg2]) {
                        parent[arg1] = arg2;
                    }
                    else {
                        parent[arg2] = arg1;
                        if (rank[arg1] == rank[arg2])   rank[arg1]++;
                    }
                }
            }
            else if (!strncmp(op, "same", 4)) {
                int arg1 = 0, arg2 = 0;
                if (scanf("%d %d", &arg1, &arg2) != 2) return 1;
                /* find root */
                while (parent[arg1] != -1) {
                    arg1 = parent[arg1];
                }
                while (parent[arg2] != -1) {
                    arg2 = parent[arg2];
                }

                if (arg1 != arg2)   printf("false");
                else    printf("true");
                if (j + 1 != ops) printf("\n");
            }
            else {
                /* find root */
                int arg = 0;
                if (scanf("%d", &arg) != 1) return 1;
                while (parent[arg] != -1) {
                    arg = parent[arg];
                }

                printf("%d", arg);
                if (j + 1 != ops) printf("\n");
            }
            free(op);
        }
        free(parent);
        free(rank);
        if (i + 1 != cases) printf("\n");
    }
    return 0;
}
