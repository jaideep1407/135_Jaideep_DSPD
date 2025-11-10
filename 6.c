/*Implement Binary search tree(BST) with following Menu operations.
1.	Search an element in BST(Display NULL if not found, If found Display Found)
2.	Insert an element in BST
3.	Delete leaf element in BST
4.	Exit
*/
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
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
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
int isLeaf(struct Node* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (isLeaf(root)) {
            free(root);
            printf("Leaf node %d deleted.\n", key);
            return NULL;
        } else {
            printf("Node %d is not a leaf. Cannot delete.\n", key);
        }
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 3:
                printf("Enter leaf value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

/*Sample Output:
--- BST Menu ---
1. Search an element
2. Insert an element
3. Delete leaf element
4. Exit
Enter your choice: 2
Enter value to insert: 50

Enter your choice: 2
Enter value to insert: 30

Enter your choice: 2
Enter value to insert: 70

Enter your choice: 1
Enter value to search: 30
Found

Enter your choice: 3
Enter leaf value to delete: 30
Leaf node 30 deleted.

Enter your choice: 3
Enter leaf value to delete: 50
Node 50 is not a leaf. Cannot delete.
*/