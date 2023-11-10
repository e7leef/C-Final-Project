#include<stdio.h>
#include "SDB.h"
#include "STD.h"

void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("\n1. Add Entry\n");
        printf("2. Get Used Size in Database\n");
        printf("3. Read Student Data\n");
        printf("4. Get the List of All Student IDs\n");
        printf("5. Check if ID Exists\n");
        printf("6. Delete Entry\n");
        printf("7. Check if Database is Full\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: \n");
        scanf("%hhu", &choice);

        SDB_action(choice);

        if (choice == 8) {
            printf("Exiting the application.\n");
            return;
        }
    }
}

void SDB_action(uint8 choice) {
    switch (choice) {
        case 1: {
            if (SDB_AddEntry()) {
                printf("Entry added successfully.\n");
            } else {
                printf("Database is full. Cannot add more entries.\n");
            }
            break;
        }
        case 2: {
            printf("Used size in the database: %hhu\n", SDB_GetUsedSize());
            break;
        }
        case 3: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id)) {
                printf("Student data retrieved successfully.\n");
            }
            break;
        }
        case 4: {
            uint8 count;
            uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of all student IDs:\n");
            for (uint8 i = 0; i < count; i++) {
                printf("%u\n", list[i]);
            }
            break;
        }
        case 5: {
            uint32 id;
            printf("Enter Student ID: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("Student ID exists in the database.\n");
            } else {
                printf("Student ID does not exist in the database.\n");
            }
            break;
        }
        case 6: {
            uint32 deleteId;
            printf("Enter Student ID to delete: ");
            scanf("%u", &deleteId);
            SDB_DeleteEntry(deleteId);
            break;
        }
        case 7: {
            if (SDB_IsFull()) {
                printf("The database is full.\n");
            } else {
                printf("The database is not full.\n");
            }
            break;
        }
        default: {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
