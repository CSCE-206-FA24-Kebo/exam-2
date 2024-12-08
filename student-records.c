#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct Student {
    int id;
    float gpa;
    char major[50];
};

// Function prototypes
void sortByID(struct Student* students, int size);
void sortByGPA(struct Student* students, int size);
void printStudents(struct Student* students, int size);
void swapStudents(struct Student* a, struct Student* b);

int main() {
    // Allocate memory for 6 students
    struct Student* students = (struct Student*)malloc(6 * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize student data
    students[0] = (struct Student){103, 3.8, "Computer Science"};
    students[1] = (struct Student){101, 3.5, "Mathematics"};
    students[2] = (struct Student){106, 3.9, "Physics"};
    students[3] = (struct Student){102, 3.2, "Chemistry"};
    students[4] = (struct Student){105, 3.6, "Engineering"};
    students[5] = (struct Student){104, 3.7, "Biology"};

    // Print original list
    printf("Original Student List:\n");
    printf("--------------------\n");
    printStudents(students, 6);

    // Sort and print by ID
    sortByID(students, 6);
    printf("\nStudents Sorted by ID:\n");
    printf("--------------------\n");
    printStudents(students, 6);

    // Sort and print by GPA
    sortByGPA(students, 6);
    printf("\nStudents Sorted by GPA:\n");
    printf("--------------------\n");
    printStudents(students, 6);

    // Free allocated memory
    free(students);
    return 0;
}

// Function to swap two students
void swapStudents(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort students by ID (using bubble sort)
void sortByID(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to sort students by GPA (using bubble sort)
void sortByGPA(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {  // Note: sorting in descending order
                swapStudents(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to print all student records
void printStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d | GPA: %.1f | Major: %s\n", 
               students[i].id, 
               students[i].gpa, 
               students[i].major);
    }
}