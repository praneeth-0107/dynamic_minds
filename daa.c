  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COURSE_ID 10
#define MAX_COURSE_NAME 50
#define MAX_OBJ_CODE 10
#define MAX_OBJ_NO 10
#define MAX_OBJ_DETAILS 100
#define MAX_COURSES 100
#define FILE_PATH "courses.txt"

typedef struct {
    int id;
    char cour_id[MAX_COURSE_ID];
    char name[MAX_COURSE_NAME];
    char cour_obj_code[MAX_OBJ_CODE];
    char cour_obj_no[MAX_OBJ_NO];
    char cour_obj_details[MAX_OBJ_DETAILS];
} Course;

// Function prototypes
void Dynamic_minds_course_objective_setting_create();
void Dynamic_minds_course_objective_setting_retrieve();
void Dynamic_minds_course_objective_setting_update();
void Dynamic_minds_course_objective_setting_delete();
void Dynamic_minds_course_objective_setting_searchCourseByCode();
void Dynamic_minds_course_objective_setting_listCoursesByObjectiveNo();
void Dynamic_minds_course_objective_setting_sortCoursesById();
void Dynamic_minds_course_objective_setting_clearInputBuffer();
bool Dynamic_minds_course_objective_setting_loadFromFile(Course courses[], int *count);
bool Dynamic_minds_course_objective_setting_storeToFile(const Course courses[], int count);
void Dynamic_minds_course_objective_setting_printCourseHeader();
void Dynamic_minds_course_objective_setting_printCourse(const Course *course);
void Dynamic_minds_course_objective_setting_handleError(const char *message);
void Dynamic_minds_course_objective_setting_Compare_Search_Algorithms();
void Dynamic_minds_course_objective_setting_Compare_Sort_Algorithms();
 void Dynamic_minds_course_objective_setting_displaysearchPseudocode();
void Dynamic_minds_course_objective_setting_displaysortPseudocode();
void Dynamic_minds_course_objective_setting_complexity_sorting();
void Dynamic_minds_course_objective_setting_complexity_searching();
void Dynamic_minds_course_objective_setting_searchCoursesByField();
void Dynamic_minds_course_objective_setting_sortCoursesByField();

int main() {
    int choice;
 Course courses[MAX_COURSES];
int count=0;

// Load courses from file at the start
    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found or error loading from file.\n");
    }
    do {
        printf("\nCourse Management System\n");
        printf("1. Create Course\n");
        printf("2. Retrieve Courses\n");
        printf("3. Update Course\n");
        printf("4. Delete Course\n");
        printf("5. Search Course by field\n");
        printf("6. Sort Courses by field\n");
        printf("7. Compare Searching Algorithms\n");
        printf("8. Compare Sorting Algorithms\n");
        printf("9. Display Searching Algorithm Pseudocode\n");
        printf("10. Display Sorting Algorithm Pseudocode\n");
        printf("11. Display Searching  Algorithm  Complexities\n");
        printf("12. Display Sorting Algorithm  Complexities\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            Dynamic_minds_course_objective_setting_clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        Dynamic_minds_course_objective_setting_clearInputBuffer();

        switch (choice) {
            case 1: Dynamic_minds_course_objective_setting_create(); break;
            case 2: Dynamic_minds_course_objective_setting_retrieve(); break;
            case 3: Dynamic_minds_course_objective_setting_update(); break;
            case 4: Dynamic_minds_course_objective_setting_delete(); break;
            case 5: Dynamic_minds_course_objective_setting_searchCoursesByField();break;
            case 6: Dynamic_minds_course_objective_setting_sortCoursesByField();break;
            case 7: Dynamic_minds_course_objective_setting_Compare_Search_Algorithms(); break;
            case 8: Dynamic_minds_course_objective_setting_Compare_Sort_Algorithms(); break;
            case 9: Dynamic_minds_course_objective_setting_displaysearchPseudocode(); break;
case 10: Dynamic_minds_course_objective_setting_displaysortPseudocode(); break;
            case 11: Dynamic_minds_course_objective_setting_complexity_searching(); break;
 case 12: Dynamic_minds_course_objective_setting_complexity_sorting(); break;
            case 13: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 13);

    return 0;
}

void Dynamic_minds_course_objective_setting_clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Dynamic_minds_course_objective_setting_handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void Dynamic_minds_course_objective_setting_printCourseHeader() {
    printf("\n%-5s %-10s %-10s %-10s %-50s\n", "ID", "Course ID", "Obj Code", "Obj No", "Obj Details");
    printf("%-5s %-10s %-10s %-10s %-50s\n", "----", "---------", "--------", "------", "----------");
}

void Dynamic_minds_course_objective_setting_printCourse(const Course *course) {
    printf("%-5d %-10s %-10s %-10s %-50s\n", course->id, course->cour_id, course->cour_obj_code, course->cour_obj_no, course->cour_obj_details);
}

bool Dynamic_minds_course_objective_setting_loadFromFile(Course courses[], int *count) {
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL) return false;

    *count = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &courses[*count].id, courses[*count].cour_id, courses[*count].cour_obj_code, courses[*count].cour_obj_no, courses[*count].cour_obj_details) == 5) {
        (*count)++;
    }
    fclose(file);
    return true;
}

bool Dynamic_minds_course_objective_setting_storeToFile(const Course courses[], int count) {
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL) return false;

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s\n", courses[i].id, courses[i].cour_id, courses[i].cour_obj_code, courses[i].cour_obj_no, courses[i].cour_obj_details);
    }
    fclose(file);
    return true;
}

void Dynamic_minds_course_objective_setting_create() {
    Course newCourse;
    printf("Enter course ID (integer): ");
    if (scanf("%d", &newCourse.id) != 1) {
        Dynamic_minds_course_objective_setting_clearInputBuffer();
        printf("Invalid input. Course ID should be an integer.\n");
        return;
    }
    Dynamic_minds_course_objective_setting_clearInputBuffer();

    printf("Enter course code: ");
    fgets(newCourse.cour_id, MAX_COURSE_ID, stdin);
    strtok(newCourse.cour_id, "\n");

    printf("Enter objective code: ");
    fgets(newCourse.cour_obj_code, MAX_OBJ_CODE, stdin);
    strtok(newCourse.cour_obj_code, "\n");

    printf("Enter objective number: ");
    fgets(newCourse.cour_obj_no, MAX_OBJ_NO, stdin);
    strtok(newCourse.cour_obj_no, "\n");

    printf("Enter objective details: ");
    fgets(newCourse.cour_obj_details, MAX_OBJ_DETAILS, stdin);
    strtok(newCourse.cour_obj_details, "\n");

    FILE *file = fopen(FILE_PATH, "a");
    if (file == NULL) {
        Dynamic_minds_course_objective_setting_handleError("Error opening file for appending.");
    }

    fprintf(file, "%d,%s,%s,%s,%s\n", newCourse.id, newCourse.cour_id, newCourse.cour_obj_code, newCourse.cour_obj_no, newCourse.cour_obj_details);
    fclose(file);
    printf("Course added successfully.\n");
}

void Dynamic_minds_course_objective_setting_retrieve() {
    Course courses[MAX_COURSES];
    int count = 0;

    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    Dynamic_minds_course_objective_setting_printCourseHeader();
    for (int i = 0; i < count; i++) {
        Dynamic_minds_course_objective_setting_printCourse(&courses[i]);
    }
}

// Other function definitions continue below following similar corrections...


// Update an existing course
void Dynamic_minds_course_objective_setting_update() {
    Course courses[MAX_COURSES];
    int count = 0;

    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    int courseId;
    printf("Enter the course ID to update: ");
    if (scanf("%d", &courseId) != 1) {
        Dynamic_minds_course_objective_setting_clearInputBuffer();
        printf("Invalid input. Course ID should be an integer.\n");
        return;
    }
    Dynamic_minds_course_objective_setting_clearInputBuffer();

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (courses[i].id == courseId) {
            found = true;

            printf("Enter new course code: ");
            fgets(courses[i].cour_id, MAX_COURSE_ID, stdin);
            strtok(courses[i].cour_id, "\n");

            printf("Enter new objective code: ");
            fgets(courses[i].cour_obj_code, MAX_OBJ_CODE, stdin);
            strtok(courses[i].cour_obj_code, "\n");

            printf("Enter new objective number: ");
            fgets(courses[i].cour_obj_no, MAX_OBJ_NO, stdin);
            strtok(courses[i].cour_obj_no, "\n");

            printf("Enter new objective details: ");
            fgets(courses[i].cour_obj_details, MAX_OBJ_DETAILS, stdin);
            strtok(courses[i].cour_obj_details, "\n");

            if (Dynamic_minds_course_objective_setting_storeToFile(courses, count)) {
                printf("Course updated successfully.\n");
            } else {
                printf("Error updating course.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Course ID not found.\n");
    }
}

// Delete a course from the file
void Dynamic_minds_course_objective_setting_delete() {
   Course courses[MAX_COURSES];
    int count = 0;

    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    int courseId;
    printf("Enter the course ID to delete: ");
    if (scanf("%d", &courseId) != 1) {
        Dynamic_minds_course_objective_setting_clearInputBuffer();
        printf("Invalid input. Course ID should be an integer.\n");
        return;
    }
    Dynamic_minds_course_objective_setting_clearInputBuffer();

    bool found = false;
    int newCount = 0;
    for (int i = 0; i < count; i++) {
        if (courses[i].id != courseId) {
            courses[newCount++] = courses[i];
        } else {
            found = true;
        }
    }

    if (found && Dynamic_minds_course_objective_setting_storeToFile(courses, newCount)) {
        printf("Course deleted successfully.\n");
    } else if (!found) {
        printf("Course ID not found.\n");
    } else {
        printf("Error deleting course.\n");
    }

}

// Search for a course by objective code
void Dynamic_minds_course_objective_setting_searchCourseByCode() {
    Course courses[MAX_COURSES];
    int count = 0;

    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    char objCode[MAX_OBJ_CODE];
    printf("Enter the objective code to search: ");
    fgets(objCode, MAX_OBJ_CODE, stdin);
    strtok(objCode, "\n");

    Dynamic_minds_course_objective_setting_printCourseHeader();
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(courses[i].cour_obj_code, objCode) == 0) {
            Dynamic_minds_course_objective_setting_printCourse(&courses[i]);
            found = true;
        }
    }

    if (!found) {
        printf("No course found with the given objective code.\n");
    }

}

// List all courses by objective number
void Dynamic_minds_course_objective_setting_listCoursesByObjectiveNo() {
    Course courses[MAX_COURSES];
    int count = 0;

    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    char objNo[MAX_OBJ_NO];
    printf("Enter the objective number to list courses: ");
    fgets(objNo, MAX_OBJ_NO, stdin);
    strtok(objNo, "\n");

    Dynamic_minds_course_objective_setting_printCourseHeader();
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(courses[i].cour_obj_no, objNo) == 0) {
            Dynamic_minds_course_objective_setting_printCourse(&courses[i]);
            found = true;
        }
    }

    if (!found) {
        printf("No courses found with the given objective number.\n");
    }
}

// Sort courses by ID
void Dynamic_minds_course_objective_setting_sortCoursesById() {
Course courses[MAX_COURSES];
    int count = 0;

    // Load courses from the file
    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    // Bubble Sort to sort courses by ID
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (courses[j].id > courses[j + 1].id) {
                Course temp = courses[j];
                courses[j] = courses[j + 1];
                courses[j + 1] = temp;
            }
        }
    }

     
    
}



// Compare searching algorithms
void Dynamic_minds_course_objective_setting_Compare_Search_Algorithms() {
    printf("Comparing Linear Search and Binary Search algorithms on course list:\n");

    printf("Linear Search:\n");
    printf("Time Complexity: O(n)\n");

    printf("\nBinary Search:\n");
    printf("Time Complexity: O(log n) (after sorting O(n log n))\n");
}

// Compare sorting algorithms
void Dynamic_minds_course_objective_setting_Compare_Sort_Algorithms() {
    printf("Comparing Bubble Sort and Quick Sort algorithms on course list:\n");

    printf("Bubble Sort:\n");
    printf("Time Complexity: O(n^2)\n");

    printf("\nQuick Sort:\n");
    printf("Time Complexity: O(n log n)\n");
}

// Display pseudocode for both search and sorting algorithms
void Dynamic_minds_course_objective_setting_displaysearchPseudocode() {
    printf("\nPseudocode for Searching and Sorting Algorithms:\n");

    printf("\nLinear Search:\n");
    printf("1. For each item in list, compare it with the target.\n");
    printf("2. If a match is found, return the index.\n");
    printf("3. If not found after checking all items, return -1.\n");

    printf("\nBinary Search:\n");
    printf("1. Sort the list if it is not already sorted.\n");
    printf("2. Set 'low' to the start and 'high' to the end of the list.\n");}
void Dynamic_minds_course_objective_setting_displaysortPseudocode()
{
     
    printf("\nBubble Sort:\n");
    printf("1. Repeat from the start of the list to its end:\n");
    printf("   a. For each adjacent pair, if the first is greater than the second, swap them.\n");
    printf("   b. Stop if no swaps are made in the pass.\n");

    printf("\nQuick Sort:\n");
    printf("1. Choose a pivot item and partition the list around it.\n");
    printf("2. Recursively quick sort left and right partitions until list is sorted.\n");
printf("3. While low <= high:\n");
    printf("   a. Set 'mid' to (low + high) / 2.\n");
    printf("   b. If mid is the target, return index.\n");
    printf("   c. If target < mid, set high = mid - 1.\n");
    printf("   d. If target > mid, set low = mid + 1.\n");


}

// Display time and space complexity for each algorithm
void Dynamic_minds_course_objective_setting_complexity_sorting() {
    printf("\nTime and Space Complexities:\n");

    printf("\nLinear Search:\n");
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(1)\n");

    printf("\nBinary Search:\n");
    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");} 

void Dynamic_minds_course_objective_setting_complexity_searching() {
    printf("\nBubble Sort:\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");

    printf("\nQuick Sort:\n");
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(log n)\n");
}

 
// Sorting function based on selected field
 
void Dynamic_minds_course_objective_setting_searchCoursesByField() {
    Course courses[MAX_COURSES];
    int count = 0;

    // Load courses from file
    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    int choice;
    char searchTerm[MAX_COURSE_NAME];
    printf("Select field to search by:\n");
    printf("1. Course ID\n2. Name\n3. Objective Code\n4. Objective Number\n5. Objective Details\n");
    if (scanf("%d", &choice) != 1) {
        Dynamic_minds_course_objective_setting_clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    Dynamic_minds_course_objective_setting_clearInputBuffer();
    printf("Enter search term: ");
    fgets(searchTerm, MAX_COURSE_NAME, stdin);
    strtok(searchTerm, "\n");

    bool found = false;
    Dynamic_minds_course_objective_setting_printCourseHeader();
    for (int i = 0; i < count; i++) {
        bool match = false;
        switch (choice) {
            case 1: match = (courses[i].id == atoi(searchTerm)); break;
            case 2: match = (strcmp(courses[i].name, searchTerm) == 0); break;
            case 3: match = (strcmp(courses[i].cour_obj_code, searchTerm) == 0); break;
            case 4: match = (strcmp(courses[i].cour_obj_no, searchTerm) == 0); break;
            case 5: match = (strcmp(courses[i].cour_obj_details, searchTerm) == 0); break;
            default:
                printf("Invalid choice.\n");
                return;
        }
        if (match) {
            Dynamic_minds_course_objective_setting_printCourse(&courses[i]);
            found = true;
        }
    }
    if (!found) printf("No courses found.\n");
}

// Implement the rest of your helper functions here
void Dynamic_minds_course_objective_setting_sortCoursesByField() {
    Course courses[MAX_COURSES];
    int count = 0;

    // Load courses from file
    if (!Dynamic_minds_course_objective_setting_loadFromFile(courses, &count)) {
        printf("No courses found.\n");
        return;
    }

    int choice;
    printf("Select field to sort by:\n");
    printf("1. Course ID\n2. Name\n3. Objective Code\n4. Objective Number\n5. Objective Details\n");
    if (scanf("%d", &choice) != 1) {
        Dynamic_minds_course_objective_setting_clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    Dynamic_minds_course_objective_setting_clearInputBuffer();

    // Perform bubble sort based on the selected field
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            bool swap = false;
            switch (choice) {
                case 1: swap = (courses[j].id > courses[j + 1].id); break;
                case 2: swap = (strcmp(courses[j].name, courses[j + 1].name) > 0); break;
                case 3: swap = (strcmp(courses[j].cour_obj_code, courses[j + 1].cour_obj_code) > 0); break;
                case 4: swap = (strcmp(courses[j].cour_obj_no, courses[j + 1].cour_obj_no) > 0); break;
                case 5: swap = (strcmp(courses[j].cour_obj_details, courses[j + 1].cour_obj_details) > 0); break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            if (swap) {
                Course temp = courses[j];
                courses[j] = courses[j + 1];
                courses[j + 1] = temp;
            }
        }
    }

    printf("Courses sorted successfully.\n");
    Dynamic_minds_course_objective_setting_printCourseHeader();
    for (int i = 0; i < count; i++) {
        Dynamic_minds_course_objective_setting_printCourse(&courses[i]);
    }
}
