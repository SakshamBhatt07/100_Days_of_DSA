/* Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->data = u;
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
