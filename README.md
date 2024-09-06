# Linked Lists and Binary Trees in C

This C program implements and demonstrates basic operations on **Linked Lists** and **Binary Search Trees (BST)**, offering functionalities such as insertion, deletion, reversal, cloning, and search.

## Features

### Linked Lists:
- **Insert (Shift, Push, Ordered Insert)**: Add elements at the start or end of the list, or maintain sorted order.
- **Delete (Unshift, Pop)**: Remove elements from the start or end of the list.
- **Reversal**: Reverse the order of the linked list.
- **Cloning**: Create a copy of the entire linked list.
- **Search**: Search for a value within the linked list.
- **Print**: Output the list elements.

### Binary Search Trees (BST):
- **Insert**: Insert elements maintaining the BST properties.
- **Delete**: Remove a node from the BST.
- **Print**: Display the tree in a 2D or pre-order format.

## How to Use

1. **Compile the Program**:
   ```bash
   gcc main.c -o output_name
   ```

2. **Run the Program**:
   ```bash
   ./output_name
   ```

The program demonstrates inserting, deleting, searching, reversing, and printing both the linked list and the binary search tree.

## Example Output

```bash
0  # Checking if the list is empty
-3 1 3 7 9 11 19  # Ordered insertion into the list
1 3 7 9 11 19  # After removing the first element
1  # Searching for value 11
19 11 9 7 3 1  # Reversed list
19 11 9 7 3 1  # Cloned list
##########################
                9
        6
                5
3
                2
        1
                1

# Binary tree after removing node 3:
                9
        6
                5
2
        1
                1
```

## File Structure

- **Linked Lists**: Defined using the `struct node`, with functions to manipulate and traverse the list.
- **Binary Search Trees**: Defined using the `struct btree`, with functions to insert, remove, and display nodes.

## Dependencies

- Standard C libraries: `<stdio.h>`, `<stdlib.h>`
