#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* buildTree() {
    int data;
    printf("\n\tEnter data (-1 for NULL): ");
    scanf("%d", &data);
    
    if (data == -1)
        return NULL;

    struct node* root = createNode(data);

    printf("\n\tLeft child of %d:\n", data);
    root->left = buildTree();

    printf("\n\tRight child of %d:\n", data);
    root->right = buildTree();

    return root;
}

void preOrder(struct node* root) {
    if (root == NULL)
        return;

   
    printf("%d ", root->data);
    
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    struct node* root = buildTree();
    printf("\nPre-order Traversal: ");
    preOrder(root);
    printf("\n");
    return 0;
}

