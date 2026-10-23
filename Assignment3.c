#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    int marks;
};

void acceptStudents(struct Student s[100], int n){

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &s[i].rollNumber);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &s[i].marks);
    }

}

void displayStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %d\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

void insertionsort(struct Student students[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].rollNumber > key.rollNumber) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

void selectionsort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minpos = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j].rollNumber < students[minpos].rollNumber) {
                minpos = j;
            }
        }
        if (minpos != i) {
            struct Student temp = students[i];
            students[i] = students[minpos];
            students[minpos] = temp;
        }
    }
}

void shellsort(struct Student students[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Student key = students[i];
            int j = i;
            while (j >= gap && students[j - gap].rollNumber > key.rollNumber) {
                students[j] = students[j - gap];
                j -= gap;
            }
            students[j] = key;
        }
    }
}

int linearsearch(struct Student students[], int n, int rollNumber) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

int binarysearch(struct Student students[], int n, int rollNumber) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + high / 2;
        if (students[mid].rollNumber == rollNumber) {
            return mid;
        } else if (students[mid].rollNumber < rollNumber) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int menu() {
    int choice;
    printf("Menu:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Linear Search\n");
    printf("5. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Student s[100];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    acceptStudents(s,n);
    displayStudents(s,n);

    int choice = menu();
    int rollNumber;
    int index;

    switch (choice) {
        case 1:
            insertionsort(s, n);
            displayStudents(s, n);
            break;
        case 2:
            selectionsort(s, n);
            displayStudents(s, n);
            break;
        case 3:
            shellsort(s, n);
            displayStudents(s, n);
            break;
        case 4:
            printf("Enter roll number to search: ");
            scanf("%d", &rollNumber);
            index = linearsearch(s, n, rollNumber);
            if (index != -1) {
                printf("Student found at index %d\n", index);
                printf("Name: %s, Roll Number: %d, Marks: %d\n", s[index].name, s[index].rollNumber, s[index].marks);
            } else {
                printf("Student with roll number %d not found.\n", rollNumber);
            }
            break;
        case 5:
            insertionsort(s, n);
            printf("Enter roll number to search: ");
            scanf("%d", &rollNumber);
            index = binarysearch(s, n, rollNumber);
            if (index != -1) {
                printf("Student found at index %d\n", index);
                printf("Name: %s, Roll Number: %d, Marks: %d\n", s[index].name, s[index].rollNumber, s[index].marks);
            } else {
                printf("Student with roll number %d not found.\n", rollNumber);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
