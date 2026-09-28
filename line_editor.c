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

int main() {
    Document doc;

    init_document(&doc);

    printf("Line Editor initialized successfully.\n");

    display_document(&doc);

    free(doc.lines);

    return 0;
}