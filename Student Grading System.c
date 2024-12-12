/*
Solution Plan:
1. Define a structure `Student` to store student details (ID, name, grades, and average).
2. Implement functions to:
   - Add a student.
   - Display student details and grades.
   - Calculate the average grade for each student.
3. Use a menu-driven interface to allow the user to interact with the system.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_GRADES 5

// Define the structure for storing student details
typedef struct {
    int id;
    char name[50];
    float grades[MAX_GRADES];
    float average;
} Student;

Student students[MAX_STUDENTS]; // Array to store students
int studentCount = 0;          // Tracks the number of students

// Function to calculate the average grade of a student
void calculateAverage(Student *student) {
    float sum = 0.0;
    for (int i = 0; i < MAX_GRADES; i++) {
        sum += student->grades[i];
    }
    student->average = sum / MAX_GRADES;
}

// Function to add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    Student newStudent;

    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    getchar(); // Consume newline character

    printf("Enter Student Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline character

    printf("Enter %d grades: \n", MAX_GRADES);
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%f", &newStudent.grades[i]);
    }

    calculateAverage(&newStudent);
    students[studentCount++] = newStudent;

    printf("Student added successfully!\n\n");
}

// Function to display student details
void displayStudents() {
    if (studentCount == 0) {
        printf("No students available to display!\n\n");
        return;
    }

    printf("\n--- Student Details ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grades: ");
        for (int j = 0; j < MAX_GRADES; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\nAverage Grade: %.2f\n\n", students[i].average);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Student Grade Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
