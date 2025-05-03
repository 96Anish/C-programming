#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 1. Insert
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value); // creates and returns new node
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root; // return the updated root
}


// 2. Preorder
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 3. Inorder
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 4. Postorder
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// 5. Search
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// 6. Delete
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 7. Other Functions

// a. Highest (Max) in BST
int findMax(Node* root) {
    if (root == NULL) return -1;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

// b. Count Leaf Nodes
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// c. Count Nodes with One Child
int countOneChild(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL))
        count = 1;
    return count + countOneChild(root->left) + countOneChild(root->right);
}

// d. Count Internal Nodes (nodes with at least one child, excluding leaf nodes)
int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Menu
int main() {
    Node* root = NULL;
    int choice, value;
    Node* temp;
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Delete\n");
        printf("7. Find Highest (Max)\n8. Count Leaf Nodes\n9. Count One Child Nodes\n10. Count Internal Nodes\n0. Exit\n");
        printf("Enter your choice: ");
        //scanf("%d", &choice);
	while(1)
	{
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice) {
            case 1:
    				printf("Enter value to insert: ");
    				scanf("%d", &value);  // make sure scanf is reading an integer correctly
    				root = insert(root, value);
    				break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp)
                    printf("Found %d\n", temp->data);
                else
                    printf("Not found.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 7:
                printf("Highest (Max) value: %d\n", findMax(root));
                break;
            case 8:
                printf("Leaf nodes count: %d\n", countLeafNodes(root));
                break;
            case 9:
                printf("One child nodes count: %d\n", countOneChild(root));
                break;
            case 10:
                printf("Internal nodes count: %d\n", countInternalNodes(root));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    }
    return 0;
}

