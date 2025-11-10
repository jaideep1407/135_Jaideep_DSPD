/*Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , Preorder and Post Order and  Search an element in Binary Tree(Display NULL if not found, If found Display Found)*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}
int main() {
    struct Node* root = NULL;
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n\nEnter value to search: ");
    scanf("%d", &key);
    search(root, key);
    return 0;
}

/*Sample Output:
Enter number of nodes: 5
Enter 5 values:
30 20 40 10 25

Inorder Traversal: 10 20 25 30 40
Preorder Traversal: 30 20 10 25 40
Postorder Traversal: 10 25 20 40 30

Enter value to search: 25
Found
*/