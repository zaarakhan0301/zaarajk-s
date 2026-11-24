#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee e;
    FILE *fp;
    int choice;

    do
    {
        printf("\n\n--- Employee Database ---");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                fp = fopen("/tmp/employee.txt", "a");

                if (fp == NULL)
                {
                    printf("Unable to open file!");
                    break;
                }

                printf("Enter Employee ID: ");
                scanf("%d", &e.id);

                printf("Enter Employee Name: ");
                scanf("%49s", e.name);

                printf("Enter Salary: ");
                scanf("%f", &e.salary);

                fprintf(fp, "%d %s %.2f\n",
                        e.id, e.name, e.salary);

                fclose(fp);

                printf("Employee added successfully!");
                break;

            case 2:
                fp = fopen("/tmp/employee.txt", "r");

                if (fp == NULL)
                {
                    printf("No employee records found!");
                    break;
                }

                printf("\n--- Employee Records ---\n");

                while (fscanf(fp, "%d %49s %f",
                       &e.id, e.name, &e.salary) == 3)
                {
                    printf("\nID: %d", e.id);
                    printf("\nName: %s", e.name);
                    printf("\nSalary: %.2f\n", e.salary);
                }

                fclose(fp);
                break;

            case 3:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while (choice != 3);

    return 0;
}