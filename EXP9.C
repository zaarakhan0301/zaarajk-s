#include <stdio.h>

struct student_record
{
    char name[50];
    int roll_number;
    float total_marks;
};

int main()
{
    struct student_record s[5];
    int i, topper = 0;

    for (i = 0; i < 5; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter name: ");
        scanf("%49s", s[i].name);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll_number);

        printf("Enter total marks: ");
        scanf("%f", &s[i].total_marks);

        if (s[i].total_marks > s[topper].total_marks)
            topper = i;
    }

    printf("\nStudent Records:\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nName: %s", s[i].name);
        printf("\nRoll Number: %d", s[i].roll_number);
        printf("\nTotal Marks: %.2f\n", s[i].total_marks);
    }

    printf("\nTopper Details:\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll Number: %d\n", s[topper].roll_number);
    printf("Marks: %.2f\n", s[topper].total_marks);

    return 0;
}