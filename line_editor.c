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

void show_help() {
    printf("\nAvailable Commands:\n");
    printf("  insert <line_number>  - Insert a new line\n");
    printf("  delete <line_number>  - Delete a line\n");
    printf("  display               - Display the document\n");
    printf("  modify <line_number>  - Modify an existing line\n");
    printf("  help                  - Show available commands\n");
    printf("  quit                  - Exit the editor\n");
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
        int new_capacity = doc->capacity * 2;

        char **temp = realloc(doc->lines,
                          new_capacity * sizeof(char *));

        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        doc->lines = temp;
        doc->capacity = new_capacity;
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

void delete_line(Document *doc, int line_number) {
    if (doc->line_count == 0) {
        printf("Error: Document is empty.\n");
        return;
    }

    if (line_number < 1 || line_number > doc->line_count) {
        printf("Error: Invalid line number.\n");
        return;
    }

    free(doc->lines[line_number - 1]);

    for (int i = line_number - 1; i < doc->line_count - 1; i++) {
        doc->lines[i] = doc->lines[i + 1];
    }

    doc->line_count--;

    printf("Line deleted successfully.\n");
}

void modify_line(Document *doc, int line_number, const char *text) {
    if (doc->line_count == 0) {
        printf("Error: Document is empty.\n");
        return;
    }

    if (line_number < 1 || line_number > doc->line_count) {
        printf("Error: Invalid line number.\n");
        return;
    }

    char *new_line = malloc(strlen(text) + 1);

    if (new_line == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(new_line, text);

    free(doc->lines[line_number - 1]);
    doc->lines[line_number - 1] = new_line;

    printf("Line modified successfully.\n");
}

int main() {
    Document doc;
    char command[100];
    int line_number;

    init_document(&doc);

    printf("=== LINE EDITOR ===\n");
    printf("Type 'help' for available commands.\n");

    while (1) {
        printf("\n> ");

        if (scanf("%99s", command) != 1) {
            break;
        }

        if (strcmp(command, "display") == 0) {
            display_document(&doc);
        }
        
        else if (strcmp(command, "help") == 0) {
            show_help();
        }

        else if (strcmp(command, "quit") == 0) {
            printf("Goodbye.\n");
            break;
        }

        else if (strcmp(command, "insert") == 0) {
            char text[MAX_LINE_LENGTH];

            scanf("%d", &line_number);

            getchar();

            printf("Enter text: ");
            fgets(text, MAX_LINE_LENGTH, stdin);

            text[strcspn(text, "\n")] = '\0';

            insert_line(&doc, line_number, text);
        }

        else if (strcmp(command, "delete") == 0) {
            scanf("%d", &line_number);
            delete_line(&doc, line_number);
        }

        else if (strcmp(command, "modify") == 0) {
            char text[MAX_LINE_LENGTH];

            scanf("%d", &line_number);
            getchar();

            printf("Enter new text: ");
            fgets(text, MAX_LINE_LENGTH, stdin);

            text[strcspn(text, "\n")] = '\0';

            modify_line(&doc, line_number, text);
        }

        else {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    for (int i = 0; i < doc.line_count; i++) {
        free(doc.lines[i]);
    }

    free(doc.lines);

    return 0;
}