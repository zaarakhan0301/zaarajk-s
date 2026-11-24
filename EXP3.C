#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
    char grade;
};

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice, searchId, found, i;
    float totalMarks, averageMarks;

main_menu:

    printf("\n=========================================\n");
    printf(" STUDENT GRADE & RESULT MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by ID\n");
    printf("4. Calculate Class Average\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice (1-5): ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        goto main_menu;
    }

    switch (choice)
    {
        case 1:
            if (count >= MAX_STUDENTS) {
                printf("Database is full!\n");
                goto main_menu;
            }

            printf("Enter Student ID: ");
            scanf("%d", &students[count].id);

            printf("Enter Student Name: ");
            scanf("%49s", students[count].name);

            printf("Enter Marks (out of 100): ");
            scanf("%f", &students[count].marks);

            if (students[count].marks < 0 ||
                students[count].marks > 100) {
                printf("Invalid marks!\n");
                goto main_menu;
            }

            if (students[count].marks >= 90)
                students[count].grade = 'A';
            else if (students[count].marks >= 75)
                students[count].grade = 'B';
            else if (students[count].marks >= 60)
                students[count].grade = 'C';
            else if (students[count].marks >= 40)
                students[count].grade = 'D';
            else
                students[count].grade = 'F';

            count++;
            printf("Student record added successfully!\n");
            goto main_menu;

        case 2:
            if (count == 0) {
                printf("No student records found!\n");
                goto main_menu;
            }

            printf("\nID\tName\tMarks\tGrade\n");

            for (i = 0; i < count; i++) {
                printf("%d\t%s\t%.2f\t%c\n",
                    students[i].id,
                    students[i].name,
                    students[i].marks,
                    students[i].grade);
            }
            goto main_menu;

        case 3:
            if (count == 0) {
                printf("No student records found!\n");
                goto main_menu;
            }

            printf("Enter Student ID to search: ");
            scanf("%d", &searchId);

            found = 0;

            for (i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    printf("\nRecord Found:\n");
                    printf("ID: %d\n", students[i].id);
                    printf("Name: %s\n", students[i].name);
                    printf("Marks: %.2f\n", students[i].marks);
                    printf("Grade: %c\n", students[i].grade);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student not found.\n");

            goto main_menu;

        case 4:
            if (count == 0) {
                printf("No records to calculate average!\n");
                goto main_menu;
            }

            totalMarks = 0;

            for (i = 0; i < count; i++)
                totalMarks += students[i].marks;

            averageMarks = totalMarks / count;

            printf("Total Students: %d\n", count);
            printf("Class Average: %.2f\n", averageMarks);
            goto main_menu;

        case 5:
            printf("Exiting program. Thank you!\n");
            exit(0);

        default:
            printf("Invalid choice! Select between 1 and 5.\n");
            goto main_menu;
    }

    return 0;
}