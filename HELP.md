# Line Editor - Help

The Line Editor is a command-line text editor implemented in C. It allows users to insert, delete, display, and modify lines of a text document using terminal-based commands.

## Available Commands

### 1. Insert a Line

```text
insert <line_number>
Adds a new line at the specified position in the document.

Example:

> insert 1
Enter text: Hello world
Line inserted successfully.

The line number must be between 1 and the current number of lines + 1.
```

### 2. Delete a Line

```text
delete <line_number>

Deletes the line at the specified position from the document.

Example:

> delete 2
Line deleted successfully.

The line number must refer to an existing line in the document. If the document is empty or the line number is invalid, an error message is displayed.
```

### 3. Display Document

```text
display

Displays all lines currently stored in the document along with their line numbers.

Example:

> display

--- Document ---
1: Hello world
2: I am learning C
----------------

If the document does not contain any lines, the editor displays:

Document is empty.
```

### 4. Modify a Line

```text
modify <line_number>

Replaces the existing text of the specified line with new text.

Example:

> modify 1
Enter new text: Hello C programming
Line modified successfully.

The line number must refer to an existing line in the document. If the document is empty or the line number is invalid, an error message is displayed.
```

### 5. Help

```text
help

Displays the list of available commands and their descriptions.

Example:

> help

The available commands are:

insert <line_number>  - Insert a new line
delete <line_number>  - Delete a line
display               - Display the document
modify <line_number>  - Modify an existing line
help                  - Show available commands
quit                  - Exit the editor
```

### 6. Quit

```text
quit

Exits the Line Editor program.

Example:

> quit
Goodbye.

The editor releases the dynamically allocated memory before terminating.
```

## Error Handling

The Line Editor handles the following invalid situations:

- Attempting to display an empty document.
- Attempting to delete a line from an empty document.
- Attempting to modify a line in an empty document.
- Using an invalid line number for insertion.
- Attempting to delete a non-existing line.
- Attempting to modify a non-existing line.
- Entering an unknown command.

Example:

```text
> delete 99
Error: Invalid line number.

For an empty document:

> display
Document is empty.
```

## Data Structure

The Line Editor uses a dynamic array of strings to store the document lines.

Each line is stored as a dynamically allocated character array, while the document maintains a dynamically allocated array of pointers to those lines.

The initial capacity is 10 lines. When the document reaches its capacity, the array is resized using `realloc()`.

This structure allows:

- Lines to be stored dynamically in memory.
- Insertion of lines at different positions.
- Deletion of individual lines.
- Modification of existing lines.
- The document to grow beyond its initial capacity.

Memory allocated for the document is released before the program terminates.

## Example Session

```text
=== LINE EDITOR ===
Type 'help' for available commands.

> insert 1
Enter text: Hello world
Line inserted successfully.

> insert 2
Enter text: I am learning C
Line inserted successfully.

> display

--- Document ---
1: Hello world
2: I am learning C
----------------

> modify 1
Enter new text: Hello C programming
Line modified successfully.

> display

--- Document ---
1: Hello C programming
2: I am learning C
----------------

> delete 2
Line deleted successfully.

> display

--- Document ---
1: Hello C programming
----------------

> quit
Goodbye.
```