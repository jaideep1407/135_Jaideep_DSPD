/*Assume that you have a seven-slot closed hash table (the slots are numbered o through 6) Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.*/
#include <stdio.h>
#define SIZE 7
void insert(int hashTable[], int key) {
    int index = key % SIZE;
    int originalIndex = index;
    int i = 0;
    while (hashTable[index] != -1) {
        i++;
        index = (originalIndex + i) % SIZE;
        if (i == SIZE) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}
void display(int hashTable[]) {
    int i;
    printf("Final Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Slot %d: %d\n", i, hashTable[i]);
    }
}
int main() {
    int i;
    int hashTable[SIZE];
    int keys[] = {10, 20, 5, 15, 7, 32, 18}; 
    int n = sizeof(keys) / sizeof(keys[0]);
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    for (i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }
    display(hashTable);
    return 0;
}

/*Sample Output:
Final Hash Table:
Slot 0: 7
Slot 1: 15
Slot 2: 18
Slot 3: 10
Slot 4: 32
Slot 5: 5
Slot 6: 20
*/