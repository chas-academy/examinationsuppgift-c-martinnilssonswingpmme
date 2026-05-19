#include <stdio.h>
#include <ctype.h> // For character handling functions like toupper and tolower

#define STUDENTS 5 // Number of students in the group (Constant value)
#define TESTS 13 // Number of tests each student has taken (Constant value)

// function to capitalize the first letter of a name and make the rest lowercase
// toupper and tolower functions from <ctype.h> are used to convert characters to uppercase and lowercase respectively
void capitalize(char name[]) {
    name[0] = toupper(name[0]);

    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
    // Arrays to hold student names and their test scores
    char names[STUDENTS][11]; // 10 characters + null terminator = 11 characters
    int scores[STUDENTS][TESTS];

    // Array to hold the average score for each student and the total average for the group
    double studentAverage[STUDENTS];
    double totalAverage = 0.0;

    // Read input
    // For each student, read their name and test scores, calculate their average, and update the total average
    for (int i = 0; i < STUDENTS; i++) {
        scanf("%10s", names[i]); // Read the student's name (up to 10 characters)  

        // Variable to hold the sum of test scores for the current student
        int sum = 0;

        // Read test scores for the current student and calculate the sum
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]); // Read the test score for the current student
            sum += scores[i][j]; // Add the test score to the sum for the current student
        }

        // Calculate average for the current student and add it to the total average
        studentAverage[i] = (double)sum / TESTS;
        totalAverage += studentAverage[i];

        // Capitalize the student's name
        capitalize(names[i]);
    }

    // Calculate group average
    totalAverage /= STUDENTS;

    // Find student with highest average
    int bestIndex = 0;

    for (int i = 1; i < STUDENTS; i++) {
        if (studentAverage[i] > studentAverage[bestIndex]) { // If the current student's average is higher than the best average found so far, update the best index
            bestIndex = i; // Update the index of the student with the highest average
        }
    }

    // Print best student
    printf("%s\n", names[bestIndex]);

    // Print students below group average
    for (int i = 0; i < STUDENTS; i++) {
        if (studentAverage[i] < totalAverage) {
            printf("%s\n", names[i]); // Print the name of the student if their average score is below the group average
        }
    }

    return 0;
}

