# Project Overview

This project includes a `Makefile` for building the application, a `push.sh` script for managing Git commits and pushes, and a `.gitignore` file for excluding unnecessary files from version control.

---

# Garbage Collector (`gc.c`)

The `gc.c` file implements a simple garbage collection mechanism to manage dynamically allocated memory in the project. This ensures that memory is properly freed when no longer needed, preventing memory leaks.

---

## Overview

The garbage collector is designed to track all dynamically allocated memory and free it automatically when the program ends or when explicitly requested. It uses a linked list to store references to allocated memory blocks.

---

## Functions

### `gc_register(void *ptr)`
- **Purpose**: Registers a pointer to dynamically allocated memory in the garbage collector.
- **Parameters**:
  - `ptr`: Pointer to the allocated memory.
- **Behavior**:
  - Creates a new node in the garbage collector's linked list to store the pointer.
  - If `ptr` is `NULL`, the function does nothing.

### `gc_malloc(size_t size)`
- **Purpose**: Allocates memory and automatically registers it in the garbage collector.
- **Parameters**:
  - `size`: Size of memory to allocate.
- **Returns**:
  - Pointer to the allocated memory, or `NULL` if allocation fails.
- **Behavior**:
  - Allocates memory using `malloc`.
  - Registers the allocated memory in the garbage collector using `gc_register`.

### `gc_collect(void)`
- **Purpose**: Frees all memory tracked by the garbage collector.
- **Behavior**:
  - Iterates through the linked list of tracked memory blocks.
  - Frees each memory block and its corresponding node in the linked list.
  - Resets the garbage collector's head pointer to `NULL`.

---

## How It Works

1. **Memory Allocation**:
   - Use `gc_malloc` instead of `malloc` to allocate memory.
   - This ensures that the allocated memory is automatically tracked by the garbage collector.

2. **Memory Registration**:
   - If you manually allocate memory using `malloc`, you can register it with the garbage collector using `gc_register`.

3. **Memory Cleanup**:
   - Call `gc_collect` to free all tracked memory at once.
   - This is typically done at the end of the program or when memory cleanup is required.

---

## Example Usage

```c
#include "cube.h"

int main(void)
{
    char *str = gc_malloc(50); // Allocate and register memory
    if (!str)
        return (1);

    // Use the allocated memory
    strcpy(str, "Hello, Garbage Collector!");

    // Clean up all allocated memory
    gc_collect();

    return (0);
}