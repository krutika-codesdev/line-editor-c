#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define MAX_LINE_LENGTH 500

typedef struct {
    char **lines;
    int line_count;
    int capacity;
} Document;

void init_document(Document *doc) {
    doc->lines = malloc(INITIAL_CAPACITY * sizeof(char *));
    
    if (doc->lines == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    doc->line_count = 0;
    doc->capacity = INITIAL_CAPACITY;
}

void display_document(const Document *doc) {
    if (doc->line_count == 0) {
        printf("Document is empty.\n");
        return;
    }

    printf("\n--- Document ---\n");

    for (int i = 0; i < doc->line_count; i++) {
        printf("%d: %s\n", i + 1, doc->lines[i]);
    }

    printf("----------------\n");
}

void insert_line(Document *doc, int line_number, const char *text) {
    if (line_number < 1 || line_number > doc->line_count + 1) {
        printf("Error: Invalid line number.\n");
        return;
    }

    if (doc->line_count == doc->capacity) {
        doc->capacity *= 2;

        char **temp = realloc(doc->lines,
                              doc->capacity * sizeof(char *));

        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        doc->lines = temp;
    }

    for (int i = doc->line_count; i >= line_number; i--) {
        doc->lines[i] = doc->lines[i - 1];
    }

    doc->lines[line_number - 1] = malloc(strlen(text) + 1);

    if (doc->lines[line_number - 1] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(doc->lines[line_number - 1], text);

    doc->line_count++;

    printf("Line inserted successfully.\n");
}

int main() {
    Document doc;

    init_document(&doc);

    printf("Line Editor initialized successfully.\n");

    insert_line(&doc, 1, "Hello world");
    insert_line(&doc, 2, "This is my first document.");
    insert_line(&doc, 2, "I am learning C.");
    insert_line(&doc, 4, "This is the last line.");

    display_document(&doc);

    for (int i = 0; i < doc.line_count; i++) {
        free(doc.lines[i]);
    }

    free(doc.lines);

    return 0;
}