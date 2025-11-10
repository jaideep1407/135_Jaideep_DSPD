/*This C program creates a linked list to store integer elements. It prompts the user to enter elements and add them to the list until the user enters 0. It then traverses the list and prints each element and "=>" until reaching the null pointer. Finally, it displays the number of nodes in the list.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value, count = 0;
    printf("Enter integers to add to the list (0 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) break;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        count++;
    }
    printf("\nLinked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);
    return 0;
}

/*Sample Output:
Enter integers to add to the list (0 to stop):
10
20
30
0

Linked List:
10 => 20 => 30 => NULL
Total number of nodes: 3
*/