#include <stdio.h>
#include <stdlib.h>


// Practice on memory allocation
// The program should prompt for a number of row and column for a stadium seating
// Next it should create and populate a dynamic array of integers

int main()
{
    int rows = 0;
    int columns = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    if (rows <= 0 || columns <=0){
        printf("Invalid size entered\n");
        return 1;
    }

    // Allocate memory given the dimensions entered by the user

    // ** means a pointer to a pointer
    // Step 1: Allocation of a 2D array of pointers - (2 dimensions)
    int **seats = (int **) malloc(rows * sizeof(int *));

    // Step 2: Allocate the data pointed to in each row
    for (int y = 0; y < rows; y++){
        seats[y] = (int *) malloc(columns * sizeof(int)); // Reserve some space of the (Heap memory)
    }

    // Add numbers to the grid of seats
    // These loops fill up the grid with consecutive numbers
    for (int y = 0; y < rows; y++)  
        for (int x = 0; x < columns; x++){
            seats[y][x] = x + 1 + (columns * y);
    }

    // Display the grid of seats
    // Add numbers to the grid of seats
    // These loops fill up the grid with consecutive numbers
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++){
            printf("%d ", seats[y][x]);
        }
        printf("\n");
    }

    // Step 1: Deallocate the data pointed to in each row
    for (int y = 0; y < rows; y++){
        free(seats[y]);
    }

    // Step 2: Deallocate / free the memory
    free(seats);

    return 0;
}