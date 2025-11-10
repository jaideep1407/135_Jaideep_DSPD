/*Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.
*/
#include <stdio.h>
#define MAX 100
char queue[MAX];
int front = -1, rear = -1;
void insert(char ch) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'\n", ch);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = ch;
        printf("Inserted '%c' into queue.\n", ch);
    }
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        printf("Deleted '%c' from queue.\n", queue[front++]);
    }
}
void demonstrateOverflowUnderflow() {
    printf("Demonstrating Overflow:\n");
    for (int i = 0; i <= MAX; i++) {
        insert('A' + (i % 26));
    }
    printf("Demonstrating Underflow:\n");
    for (int i = 0; i <= MAX; i++) {
        delete();
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents (front to rear):\n");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice;
    char ch;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow/Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;
            case 2:
                delete();
                break;
            case 3:
                demonstrateOverflowUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

/*Sample Output:
--- Queue Menu ---
1. Insert an Element
2. Delete an Element
3. Demonstrate Overflow/Underflow
4. Display Queue
5. Exit
Enter your choice: 1
Enter character to insert: A
Inserted 'A' into queue.

Enter your choice: 4
Queue contents (front to rear):
A
*/