#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float m1, m2, m3;
    float total;
};

// Function to add student
void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter marks of 3 subjects: ");
    scanf("%f %f %f", &s.m1, &s.m2, &s.m3);

    s.total = s.m1 + s.m2 + s.m3;

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("✅ Student record added successfully!\n");
}

// Function to display all students
void displayStudents() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll: %d", s.roll);
        printf("\nName: %s", s.name);
        printf("\nMarks: %.2f %.2f %.2f", s.m1, s.m2, s.m3);
        printf("\nTotal: %.2f\n", s.total);
    }

    fclose(fp);
}

// Function to generate rank list
void rankList() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s[100];
    int count = 0, i, j;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    // Read all records
    while (fread(&s[count], sizeof(struct Student), 1, fp)) {
        count++;
    }
    fclose(fp);

    // Sort in descending order of total
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (s[i].total < s[j].total) {
                struct Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display rank list
    printf("\n--- Rank List ---\n");
    for (i = 0; i < count; i++) {
        printf("\nRank %d", i + 1);
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %.2f\n", s[i].total);
    }
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Generate Rank List");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                rankList();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
