#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE_LENGTH 1024
#define INITIAL_CAPACITY 5


typedef struct {
    char **lines;       
    int count;         
    int capacity;       
} TextEditor;


 
TextEditor* initEditor() {
    TextEditor *editor = (TextEditor *)malloc(sizeof(TextEditor));
    if (editor == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for editor structure\n");
        exit(EXIT_FAILURE);
    }

    
    editor->lines = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (editor->lines == NULL) {
        fprintf(stderr, "Error: Failed to allocate initial lines array\n");
        free(editor);
        exit(EXIT_FAILURE);
    }

    editor->count = 0;
    editor->capacity = INITIAL_CAPACITY;
    return editor;
}


void insertLine(TextEditor *editor, int index, const char *text) {
    
    if (index < 0 || index > editor->count) {
        fprintf(stderr, "Error: Invalid index %d (valid range: 0 to %d)\n", index, editor->count);
        return;
    }

   
    if (strlen(text) >= MAX_LINE_LENGTH) {
        fprintf(stderr, "Error: Line too long (max %d characters)\n", MAX_LINE_LENGTH - 1);
        return;
    }


    if (editor->count >= editor->capacity) {
        int newCapacity = editor->capacity * 2;  
        char **temp = (char **)realloc(editor->lines, newCapacity * sizeof(char *));
        
        if (temp == NULL) {
            fprintf(stderr, "Error: Failed to expand lines array to capacity %d\n", newCapacity);
            return;
        }
        
        editor->lines = temp;
        editor->capacity = newCapacity;
        printf("Expanded array capacity to %d\n", newCapacity);
    }

    
    for (int i = editor->count; i > index; i--) {
        editor->lines[i] = editor->lines[i - 1];
    }

    
    editor->lines[index] = (char *)malloc(strlen(text) + 1);
    if (editor->lines[index] == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for line at index %d\n", index);
        return;
    }

   
    strcpy(editor->lines[index], text);
    editor->count++;
    printf("Inserted line at index %d: \"%s\"\n", index, text);
}


void deleteLine(TextEditor *editor, int index) {

    if (index < 0 || index >= editor->count) {
        fprintf(stderr, "Error: Invalid index %d (valid range: 0 to %d)\n", index, editor->count - 1);
        return;
    }

    
    free(editor->lines[index]);

    
    for (int i = index; i < editor->count - 1; i++) {
        editor->lines[i] = editor->lines[i + 1];
    }

    editor->count--;
    printf("Deleted line at index %d\n", index);
}


void printAllLines(TextEditor *editor) {
    if (editor->count == 0) {
        printf("No lines in editor\n");
        return;
    }

    printf("\nEditor Contents\n");
    for (int i = 0; i < editor->count; i++) {
        printf("Line %d: %s\n", i + 1, editor->lines[i]);
    }
    printf("(Total lines: %d)\n\n", editor->count);
}


void printStats(TextEditor *editor) {
    printf("\nMemory Statistics\n");
    printf("Current lines: %d\n", editor->count);
    printf("Capacity: %d\n", editor->capacity);
    printf("Memory used by pointers: %lu bytes\n", editor->count * sizeof(char *));
    printf("Wasted pointer capacity: %lu bytes\n", (editor->capacity - editor->count) * sizeof(char *));
    
    
    size_t totalStringMemory = 0;
    for (int i = 0; i < editor->count; i++) {
        totalStringMemory += strlen(editor->lines[i]) + 1;  
    }
    printf("Total string memory: %lu bytes\n", totalStringMemory);
    
}


void shrinkToFit(TextEditor *editor) {
    if (editor->count == 0) {
        char **temp = (char **)realloc(editor->lines, 1 * sizeof(char *));
        if (temp != NULL) {
            editor->lines = temp;
            editor->capacity = 1;
            printf("Shrunk array to capacity 1\n");
        }
        return;
    }

    if (editor->count < editor->capacity) {
        char **temp = (char **)realloc(editor->lines, editor->count * sizeof(char *));
        
        if (temp != NULL) {
            editor->lines = temp;
            printf("Shrunk array capacity from %d to %d\n", editor->capacity, editor->count);
            editor->capacity = editor->count;
        } else {
            fprintf(stderr, "Warning: Failed to shrink to fit\n");
        }
    }
}


void saveToFile(TextEditor *editor, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s' for writing\n", filename);
        return;
    }

    for (int i = 0; i < editor->count; i++) {
        fprintf(file, "%s\n", editor->lines[i]);
    }

    fclose(file);
    printf("Saved %d lines to file '%s'\n", editor->count, filename);
}


void loadFromFile(TextEditor *editor, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s' for reading\n", filename);
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int lineCount = 0;

    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        insertLine(editor, editor->count, buffer);
        lineCount++;
    }

    fclose(file);
    printf("Loaded %d lines from file '%s'\n", lineCount, filename);
}


void freeAll(TextEditor *editor) {
    
    for (int i = 0; i < editor->count; i++) {
        free(editor->lines[i]);
    }

    
    free(editor->lines);

    
    free(editor);

    printf("All memory freed successfully\n");
}


int main() {
    printf("Dynamic Memory Text Editor\n\n");

    
    TextEditor *editor = initEditor();

    printf("Test Case 1: Adding Short Lines\n");
    insertLine(editor, 0, "Hello, World!");
    insertLine(editor, 1, "This is line 2");
    insertLine(editor, 2, "Line 3");
    insertLine(editor, 1, "Inserted at index 1");
    printAllLines(editor);
    printStats(editor);

    printf("Test Case 2: Deleting Lines\n");
    deleteLine(editor, 1);
    printAllLines(editor);
    printStats(editor);

    printf("Test Case 3: Adding Very Long Line\n");
    char longLine[MAX_LINE_LENGTH];
    memset(longLine, 'A', MAX_LINE_LENGTH - 2);
    longLine[MAX_LINE_LENGTH - 2] = '\0';
    insertLine(editor, 0, longLine);
    printStats(editor);

    printf("Test Case 4: Stress Test (Many Lines)\n");
    for (int i = 0; i < 20; i++) {
        char line[100];
        snprintf(line, sizeof(line), "Stress test line %d", i + 1);
        insertLine(editor, editor->count, line);
    }
    printf("Added 20 lines. Total lines: %d, Capacity: %d\n", editor->count, editor->capacity);
    printStats(editor);

    printf("Test Case 5: Shrink to Fit\n");
    shrinkToFit(editor);
    printStats(editor);

    printf("Test Case 6: Save to File\n");
    saveToFile(editor, "editor_output.txt");

    printf("Test Case 7: Create New Editor and Load from File\n");
    TextEditor *editor2 = initEditor();
    loadFromFile(editor2, "editor_output.txt");
    printAllLines(editor2);
    printStats(editor2);

    printf("Cleanup\n");
    freeAll(editor);
    freeAll(editor2);

    return 0;
}