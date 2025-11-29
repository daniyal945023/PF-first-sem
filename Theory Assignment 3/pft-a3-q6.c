#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 100
#define MAX_BATCH 20
#define MAX_MEMB_TYPE 10
#define DATE_FORMAT 11  
#define INITIAL_CAPACITY 10
#define BINARY_FILE "members.dat"
#define TEMP_FILE "temp_members.dat"


typedef struct {
    int studentID;                   
    char fullName[MAX_NAME];          
    char batch[MAX_BATCH];            
    char membershipType[MAX_MEMB_TYPE]; 
    char registrationDate[DATE_FORMAT]; 
    char dateOfBirth[DATE_FORMAT];     
    char interestIn[MAX_MEMB_TYPE];     
} Student;


typedef struct {
    Student *records;      
    int count;            
    int capacity;         
} Database;


Database* initDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    if (db == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for database structure\n");
        exit(EXIT_FAILURE);
    }

    db->records = (Student *)malloc(INITIAL_CAPACITY * sizeof(Student));
    if (db->records == NULL) {
        fprintf(stderr, "Error: Failed to allocate initial records array\n");
        free(db);
        exit(EXIT_FAILURE);
    }

    db->count = 0;
    db->capacity = INITIAL_CAPACITY;
    return db;
}


void loadDatabase(Database *db, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Info: No existing database found. Starting fresh.\n");
        return;
    }

    Student temp;
    int recordsLoaded = 0;

    
    while (fread(&temp, sizeof(Student), 1, fp) == 1) {
       
        if (db->count >= db->capacity) {
            int newCapacity = db->capacity * 2;
            Student *newRecords = (Student *)realloc(db->records, newCapacity * sizeof(Student));
            
            if (newRecords == NULL) {
                fprintf(stderr, "Error: Failed to expand database capacity\n");
                fclose(fp);
                return;
            }
            
            db->records = newRecords;
            db->capacity = newCapacity;
        }

        db->records[db->count++] = temp;
        recordsLoaded++;
    }

    fclose(fp);
    printf("Loaded %d records from database\n", recordsLoaded);
}


void saveDatabase(Database *db, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s' for writing\n", filename);
        return;
    }

    int recordsSaved = 0;
    
    
    for (int i = 0; i < db->count; i++) {
        if (fwrite(&db->records[i], sizeof(Student), 1, fp) != 1) {
            fprintf(stderr, "Error: Failed to write record %d to file\n", i);
            fclose(fp);
            return;
        }
        recordsSaved++;
    }

    fclose(fp);
    printf("Saved %d records to database\n", recordsSaved);
}


int isStudentIDExists(Database *db, int studentID) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].studentID == studentID) {
            return 1;  
        }
    }
    return 0; 
}


void addStudent(Database *db, Student s, const char *filename) {
    
    if (isStudentIDExists(db, s.studentID)) {
        printf("Error: Student ID %d already exists. Duplicate registration denied.\n", s.studentID);
        return;
    }

   
    if (db->count >= db->capacity) {
        int newCapacity = db->capacity * 2;
        Student *newRecords = (Student *)realloc(db->records, newCapacity * sizeof(Student));
        
        if (newRecords == NULL) {
            fprintf(stderr, "Error: Failed to expand database capacity\n");
            return;
        }
        
        db->records = newRecords;
        db->capacity = newCapacity;
        printf("Database expanded to capacity %d\n", newCapacity);
    }

   
    db->records[db->count++] = s;
    printf("✓ Student %s (ID: %d) added successfully\n", s.fullName, s.studentID);

    
    saveDatabase(db, filename);
}


int findStudentIndex(Database *db, int studentID) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].studentID == studentID) {
            return i;
        }
    }
    return -1;
}


void updateStudent(Database *db, int studentID, const char *filename) {
    int index = findStudentIndex(db, studentID);
    
    if (index == -1) {
        printf("Error: Student with ID %d not found\n", studentID);
        return;
    }

    printf("\nCurrent record:\n");
    printf("Name: %s\n", db->records[index].fullName);
    printf("Batch: %s\n", db->records[index].batch);
    printf("Membership Type: %s\n", db->records[index].membershipType);
    printf("Interest In: %s\n", db->records[index].interestIn);

    int choice;
    printf("\nWhat would you like to update?\n");
    printf("1. Batch\n2. Membership Type\n3. Interest In\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();  

    switch (choice) {
        case 1: {
            printf("Enter new batch (CS/SE/Cyber Security/AI): ");
            fgets(db->records[index].batch, MAX_BATCH, stdin);
            db->records[index].batch[strcspn(db->records[index].batch, "\n")] = 0;
            break;
        }
        case 2: {
            printf("Enter new membership type (IEEE/ACM): ");
            fgets(db->records[index].membershipType, MAX_MEMB_TYPE, stdin);
            db->records[index].membershipType[strcspn(db->records[index].membershipType, "\n")] = 0;
            break;
        }
        case 3: {
            printf("Enter interest (IEEE/ACM/Both): ");
            fgets(db->records[index].interestIn, MAX_MEMB_TYPE, stdin);
            db->records[index].interestIn[strcspn(db->records[index].interestIn, "\n")] = 0;
            break;
        }
        default:
            printf("Invalid choice\n");
            return;
    }

    printf("✓ Record updated successfully\n");
    saveDatabase(db, filename);
}


void deleteStudent(Database *db, int studentID, const char *filename) {
    int index = findStudentIndex(db, studentID);
    
    if (index == -1) {
        printf("Error: Student with ID %d not found\n", studentID);
        return;
    }

    printf("Deleting record for: %s (ID: %d)\n", db->records[index].fullName, studentID);

   
    for (int i = index; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->count--;
    printf("✓ Record deleted successfully\n");
    saveDatabase(db, filename);
}


void displayAllStudents(Database *db) {
    if (db->count == 0) {
        printf("No records found in database\n");
        return;
    }

    printf("ALL STUDENT RECORDS\n");
    printf("%-8s %-25s %-18s %-12s %-15s %-15s %-10s\n",
           "ID", "Name", "Batch", "Membership", "Reg. Date", "DOB", "Interest");
    

    for (int i = 0; i < db->count; i++) {
        printf("%-8d %-25s %-18s %-12s %-15s %-15s %-10s\n",
               db->records[i].studentID,
               db->records[i].fullName,
               db->records[i].batch,
               db->records[i].membershipType,
               db->records[i].registrationDate,
               db->records[i].dateOfBirth,
               db->records[i].interestIn);
    }
   
    printf("Total Records: %d\n\n", db->count);
}


void generateBatchReport(Database *db) {
    if (db->count == 0) {
        printf("No records found in database\n");
        return;
    }

    printf("BATCH-WISE REPORT\n");

    const char *batches[] = {"CS", "SE", "Cyber Security", "AI"};
    const char *interests[] = {"IEEE", "ACM", "Both"};

    for (int b = 0; b < 4; b++) {
        printf("%s Batch\n", batches[b]);
        int batchCount = 0;

        for (int interest = 0; interest < 3; interest++) {
            printf("\nInterest: %s\n", interests[interest]);
            int count = 0;

            for (int i = 0; i < db->count; i++) {
                if (strcmp(db->records[i].batch, batches[b]) == 0 &&
                    strcmp(db->records[i].interestIn, interests[interest]) == 0) {
                    printf(" %s (ID: %d) %s\n",
                           db->records[i].fullName,
                           db->records[i].studentID,
                           db->records[i].membershipType);
                    count++;
                }
            }

            if (count == 0) {
                printf(" No students\n");
            } else {
                batchCount += count;
            }
        }

        if (batchCount == 0) {
            printf("No students in this batch\n");
        } else {
            printf("Total in batch: %d\n", batchCount);
        }
    }
    
}


Student getStudentInput() {
    Student s;
    
    printf("\nEnter Student Information\n");
    
    printf("Student ID:");
    scanf("%d", &s.studentID);
    getchar();

    printf("Full Name:");
    fgets(s.fullName, MAX_NAME, stdin);
    s.fullName[strcspn(s.fullName, "\n")] = 0;

    printf("Batch(CS/SE/Cyber Security/AI):");
    fgets(s.batch, MAX_BATCH, stdin);
    s.batch[strcspn(s.batch, "\n")] = 0;

    printf("Membership Type (IEEE/ACM):");
    fgets(s.membershipType, MAX_MEMB_TYPE, stdin);
    s.membershipType[strcspn(s.membershipType, "\n")] = 0;

    printf("Registration Date (YYYY-MM-DD): ");
    fgets(s.registrationDate, DATE_FORMAT, stdin);
    s.registrationDate[strcspn(s.registrationDate, "\n")] = 0;

    printf("Date of Birth (YYYY-MM-DD):");
    fgets(s.dateOfBirth, DATE_FORMAT, stdin);
    s.dateOfBirth[strcspn(s.dateOfBirth, "\n")] = 0;

    printf("Interest (IEEE/ACM/Both):");
    fgets(s.interestIn, MAX_MEMB_TYPE, stdin);
    s.interestIn[strcspn(s.interestIn, "\n")] = 0;

    return s;
}


void displayMenu() {
    printf("\nIEEE/ACM MEMBERSHIP REGISTRATION SYSTEM\n");
    printf("1. Register New Student\n");
    printf("2. Update Student Record\n");
    printf("3. Delete Student Record\n");
    printf("4. View All Students\n");
    printf("5. Generate Batch-wise Report\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}


void freeDatabase(Database *db) {
    if (db != NULL) {
        free(db->records);
        free(db);
    }
    printf("Database cleaned up, memory freed\n");
}


int main() {
    Database *db = initDatabase();
    
    
    loadDatabase(db, BINARY_FILE);

    int choice;
    int running = 1;

    while (running) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1: {
                Student newStudent = getStudentInput();
                addStudent(db, newStudent, BINARY_FILE);
                break;
            }
            case 2: {
                printf("Enter Student ID to update: ");
                int id;
                scanf("%d", &id);
                getchar();
                updateStudent(db, id, BINARY_FILE);
                break;
            }
            case 3: {
                printf("Enter Student ID to delete: ");
                int id;
                scanf("%d", &id);
                getchar();
                deleteStudent(db, id, BINARY_FILE);
                break;
            }
            case 4: {
                displayAllStudents(db);
                break;
            }
            case 5: {
                generateBatchReport(db);
                break;
            }
            case 6: {
                printf("Saving database before exit...\n");
                saveDatabase(db, BINARY_FILE);
                freeDatabase(db);
                printf("Thank you for using IEEE/ACM Registration System!\n");
                running = 0;
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}