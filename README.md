# Line Editor in C

A minimalist, interactive command-line line editor implemented in standard C as a data-structures practice activity. The editor stores document text in a dynamically allocated array of strings, supporting 1-indexed line insertion, deletion, modification, and display.

## Features

- **Interactive CLI:** Command-driven loop accepting editing commands with prompt feedback.
- **Dynamic Memory Allocation:** Document capacity starts at 10 lines and doubles automatically using `realloc()` when full.
- **1-Indexed Line Insertion:** Insert new text at any valid position (`1` to `line_count + 1`) with automatic line shifting (`insert <line_number>`).
- **Line Deletion:** Remove an existing line, free its allocated string memory, and shift remaining lines up (`delete <line_number>`).
- **Line Modification:** Replace the contents of an existing line, properly allocating memory for the new string and freeing the old one (`modify <line_number>`).
- **Document Display:** View all lines formatted with 1-indexed line numbers, or a notification if the document is empty (`display`).
- **Built-in Help:** Quick reference displaying all supported commands (`help`).
- **Clean Memory Management:** All allocated lines and the main pointer array are freed upon exiting via `quit`.
- **Input & Bounds Validation:** Error handling for invalid line indices, empty-document operations, unknown commands, and memory allocation failures.

## Data Structure & Memory Model

The editor represents the in-memory document using the following struct:

```c
typedef struct {
    char **lines;
    int line_count;
    int capacity;
} Document;
```

- **Initial State:** `capacity` is initialized to 10 (`INITIAL_CAPACITY`), and `line_count` starts at 0.
- **Capacity Growth:** When `line_count == capacity`, capacity doubles (`capacity * 2`) and the pointer array is resized using `realloc()`.
- **String Memory:** Each line is individually allocated with `malloc(strlen(text) + 1)` and freed upon deletion, modification, or program termination.

## Available Commands

All line numbers are **1-indexed**.

| Command | Usage | Description |
|---|---|---|
| `display` | `display` | Displays all lines with line numbers (or prints `"Document is empty."`) |
| `insert` | `insert <line_number>` | Prompts for text and inserts it at `<line_number>`, shifting subsequent lines down |
| `delete` | `delete <line_number>` | Deletes the line at `<line_number>`, frees its memory, and shifts remaining lines up |
| `modify` | `modify <line_number>` | Prompts for new text, frees the previous line string, and updates `<line_number>` |
| `help` | `help` | Displays the list of available commands |
| `quit` | `quit` | Frees all dynamically allocated memory and exits the program |

## Compilation and Execution

Compile using GCC:

On Linux / macOS:
```bash
gcc line_editor.c -o line_editor
./line_editor
```

On Windows (Command Prompt / PowerShell):
```powershell
gcc line_editor.c -o line_editor.exe
.\line_editor.exe
```

## Repository

- **GitHub:** https://github.com/krutika-codesdev/line-editor-c