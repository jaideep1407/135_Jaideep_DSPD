/*Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
a. Push an Element on to Stack 
b. Pop an Element from Stack 
c. Demonstrate how Stack can be used to check Palindrome 
d. Demonstrate Overflow and Underflow situations on Stack 
e. Display the status of Stack 
f. Exit 
Support the program with appropriate functions for each of the above operations.
*/
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int value){
    if(top==MAX-1){
        printf("Stack Overflow!\n");
    }else{
        top++;
        stack[top]=value;
        printf("%d pushed onto stack.\n",value);
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
    }else{
        printf("%d popped from stack.\n",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty.\n");
    }else{
        printf("Stack contents:\n");
        int i;
        for(i=top;i>=0;i--){
            printf("%d\n", stack[i]);
        }
    }
}
void checkPalindrome(){
    int num,temp,digit,rev=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    temp=num;
    while(temp>0){
        digit=temp%10;
        rev=rev*10+digit;
        temp/=10;
    }
    if(rev==num){
        printf("Palindrome!\n");
    }else{
        printf("Not a palindrome.\n");
    }
}
int main(){
    int choice,value;
    while (1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n
                2. Pop\n
                3. Check Palindrome\n
                4. Display\n
                5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

/*Sample Output
--- Stack Menu ---
1. Push
2. Pop
3. Check Palindrome
4. Display
5. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed onto stack.

Enter your choice: 3
Enter a number: 121
Palindrome!
*/