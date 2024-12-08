#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define NUM_QUIZZES 4
#define NUM_STUDENTS 10
#define MAX_LINE_LENGTH 100


// Structure to hold student data
struct Student {
    char name[MAX_NAME_LENGTH];
    int quiz_grades[NUM_QUIZZES];
};

void printGradeReport(struct Student students[], int student_count);

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH]; // temporary storage
    struct Student students[NUM_STUDENTS];
    int student_count = 0;

    // Open the CSV file
    file = fopen("grades.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Skip header line
    fgets(line, MAX_LINE_LENGTH, file);

    // Read data line by line
    while (fgets(line, MAX_LINE_LENGTH, file) && student_count < NUM_STUDENTS) {
        char *token;
        
        // Get student name
        token = strtok(line, ","); // token is the first substring delimited by the comma in the string
        if (token != NULL) {
            strncpy(students[student_count].name, token, MAX_NAME_LENGTH - 1);
            // This line explicitly adds a null terminator at the end of the string
            students[student_count].name[MAX_NAME_LENGTH - 1] = '\0';
        }

        // Get quiz grades
        for (int i = 0; i < NUM_QUIZZES; i++) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                students[student_count].quiz_grades[i] = atoi(token);
            }
        }

        student_count++;
    }

    // Close the file
    fclose(file);

    // Print the grade report
    printGradeReport(students, student_count); // ????

    return 0;
}

// Function to print student grades to STDOUT
void printGradeReport(struct Student students[], int student_count) {

  // Print header
    printf("\nStudent Grade Report\n");
    printf("----------------------------------------\n");
    printf("Name            Quiz1  Quiz2  Quiz3  Quiz4\n");
    printf("----------------------------------------\n");

    // Print student data
    for (int i = 0; i < student_count; i++) {
        printf("%-15s", students[i].name);
        for (int j = 0; j < NUM_QUIZZES; j++) {
            printf("%-7d", students[i].quiz_grades[j]);
        }
        printf("\n");
    }

    printf("----------------------------------------\n");
}