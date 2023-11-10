#include <stdio.h>
#include "SDB.h"

student database[MAX_STUDENTS];
uint8 usedSize = 0;

// Function to check if the student database is full
bool SDB_IsFull() {
    return usedSize >= MAX_STUDENTS;  // Return true if the database is full
}

// Function to get the number of used entries in the database
uint8 SDB_GetUsedSize() {
    return usedSize;  // Return the number of used entries in the database
}

// Function to add a new entry to the database
bool SDB_AddEntry() {
    if (usedSize >= MAX_STUDENTS) {
        return false;  // Return false if the database is already full
    }

    student newStudent;
    printf("Enter Student ID: ");
    scanf("%u", &(newStudent.Student_ID));
    printf("Enter Student Year: ");
    scanf("%u", &(newStudent.Student_year));
    printf("Enter Course 1 ID: ");
    scanf("%u", &(newStudent.Course1_ID));
    printf("Enter Course 1 Grade: ");
    scanf("%u", &(newStudent.Course1_grade));
    printf("Enter Course 2 ID: ");
    scanf("%u", &(newStudent.Course2_ID));
    printf("Enter Course 2 Grade: ");
    scanf("%u", &(newStudent.Course2_grade));
    printf("Enter Course 3 ID: ");
    scanf("%u", &(newStudent.Course3_ID));
    printf("Enter Course 3 Grade: ");
    scanf("%u", &(newStudent.Course3_grade));

    database[usedSize] = newStudent;  // Add the new student to the database
    usedSize++;  // Increment the used size counter

    return true;  // Return true to indicate successful addition of the entry
}

// Function to delete an entry from the database based on ID
void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < usedSize - 1; j++) {
                database[j] = database[j + 1];
            }
            usedSize--;
            printf("Student with ID %u deleted.\n", id);
            return;
        }
    }

    printf("Student with ID %u not found.\n", id);
}

// Function to read and display the details of a student entry based on ID
bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u\n", database[i].Course1_ID);
            printf("Course 1 Grade: %u\n", database[i].Course1_grade);
            printf("Course 2 ID: %u\n", database[i].Course2_ID);
            printf("Course 2 Grade: %u\n", database[i].Course2_grade);
            printf("Course 3 ID: %u\n", database[i].Course3_ID);
            printf("Course 3 Grade: %u\n", database[i].Course3_grade);
            return true;
        }
    }

    printf("Student with ID %u not found.\n", id);
    return false;
}

void SDB_GetList(uint8* count, uint32* list) {
    // Set the count variable to the number of used entries in the database
    *count = usedSize;

    // Iterate over each used entry in the database
    for (uint8 i = 0; i < usedSize; i++) {
        // Assign the student ID of each entry to the corresponding element in the list array
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}
