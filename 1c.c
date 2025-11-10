/*Write a program which creates a structure Student which must have the attribute Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort*/
#include<stdio.h>
#include<string.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};
int main(){
    int n,i,j;
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct Student s[n];
    for(i=0;i<n;i++){
        printf("\nEnter details for student %d:\n",i + 1);
        printf("Roll Number: ");
        scanf("%d",&s[i].rollNo);
        printf("Name: ");
        scanf("%c", s[i].name);
        printf("Age: ");
        scanf("%d",&s[i].age);
        printf("Average Marks: ");
        scanf("%f",&s[i].avgMarks);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(s[j].avgMarks<s[j + 1].avgMarks){
                struct Student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    printf("\nStudents sorted by Average Marks (Descending):\n");
    for(i=0;i<n;i++){
        printf("\nRoll No: %d\n",s[i].rollNo);
        printf("Name: %s\n",s[i].name);
        printf("Age: %d\n",s[i].age);
        printf("Average Marks:%.2f\n",s[i].avgMarks);
    }
    return 0;
}

/*Sample Output:
Enter number of students: 3

Enter details for student 1:
Roll Number: 101
Name: Ayan
Age: 20
Average Marks: 85.5

Enter details for student 2:
Roll Number: 102
Name: Jaideep
Age: 21
Average Marks: 92.0

Enter details for student 3:
Roll Number: 103
Name: Kshitij
Age: 19
Average Marks: 78.0

Students sorted by Average Marks (Descending):

Roll No: 102
Name: Rahul
Age: 21
Average Marks: 92.00

Roll No: 101
Name: Aditi
Age: 20
Average Marks: 85.50

Roll No: 103
Name: Meena
Age: 19
Average Marks: 78.00
*/