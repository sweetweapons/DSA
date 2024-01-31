#include<stdio.h>

// Define a structure for a student
struct Student {
    char name[50];
    int grades[5]; // assuming 5 subjects
    float gpa;
};

// Function to calculate GPA based on grades
float calculateGPA(struct Student* student) {
    float totalPoints = 0.0;
    int totalSubjects = 5; // for 5 subjects
    
    for (int i = 0; i < totalSubjects; i++) {
        totalPoints = totalPoints + student->grades[i];
    }
    
    // Calculate GPA
    student->gpa = totalPoints / totalSubjects;
    
    return student->gpa;
}

// Function to display student details
void displayStudent(struct Student* student) {
    printf("Student name: %s\n", student->name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->grades[i]);
    }
    printf("\n");
    printf("GPA: %.2f\n", student->gpa);
}

// Function to update grades
void updateGrades(struct Student* student) {
    printf("Enter new grades for the student:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter the grade for Subject %d: ", i + 1);
        scanf("%d", &student->grades[i]);
    }
}

int main() {
    // Create a student
    struct Student student1;
    
    // Input the student details
    printf("Enter the student name: ");
    scanf("%s", student1.name);
    
    // Input initial grades
    printf("Enter grades for the student:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter the grade for Subject %d: ", i + 1);
        scanf("%d", &student1.grades[i]);
    }
    
    // Calculate and display initial GPA
    calculateGPA(&student1);
    displayStudent(&student1);
    
    // Update grades
    updateGrades(&student1);
    
    // Recalculate and display GPA after updating grades
    calculateGPA(&student1);
    displayStudent(&student1);
    
    return 0;
}
