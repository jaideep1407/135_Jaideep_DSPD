/*Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true 
• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
• Continue until you find the value, or until the start reaches the end, 	
*/
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Array is empty. Returning NULL.\n");
        return 0;
    }
    int arr[n];
    printf("Enter %d sorted elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int value;
    printf("Enter the value to find: ");
    scanf("%d",&value);
    int start=0;
    int end=n-1;
    int found=0;
    while(start<=end){
        int mid=(start + end)/2;
        printf("Middle value: %d\n",arr[mid]);
        if(arr[mid]==value){
            found=1;
            break;
        }else if(value>arr[mid]){
            start=mid+1;
            printf("Adjusting start to index %d\n",start);
        }else{
            end=mid-1;
            printf("Adjusting end to index %d\n",end);
        }
    }
    if(found){
        printf("Value found: %d\n",value);
    }else{
        printf("Value not found. Returning NULL.\n");
    }
    return 0;
}

/*Sample Output:
Enter number of elements: 5
Enter 5 sorted elements:
10 20 30 40 50
Enter the value to find: 40
Middle value: 30
Adjusting start to index 3
Middle value: 40
Value found: 40
*/