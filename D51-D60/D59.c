/* Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int find(int in[], int start, int end, int value) {
    int i;
    for(i = start; i <= end; i++) {
        if(in[i] == value)
            return i;
    }
    return -1;
}

struct node* build(int in[], int post[], int start, int end, int *pindex) {
    if(start > end)
        return NULL;

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = post[*pindex];
    (*pindex)--;

    if(start == end)
        return newnode;

    int pos = find(in, start, end, newnode->data);

    newnode->right = build(in, post, pos + 1, end, pindex);
    newnode->left = build(in, post, start, pos - 1, pindex);

    return newnode;
}

void preorder(struct node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int in[n], post[n];

    for(i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for(i = 0; i < n; i++)
        scanf("%d", &post[i]);

    int pindex = n - 1;

    struct node* root = build(in, post, 0, n - 1, &pindex);

    preorder(root);

    return 0;
}
