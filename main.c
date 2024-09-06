#include <stdio.h>
#include <stdlib.h>

// auto formatted by Replit.com

// linked lists
struct node {
  int val;
  struct node *next;
};
typedef struct node List;

void init(List **ptr) { *ptr = NULL; }
int isEmpty(List *ptr) { return ptr == NULL; }
void shift(List **ptr, int val) {
  List *temp = *ptr;
  *ptr = (List *)malloc(sizeof(List));
  (*ptr)->val = val;
  (*ptr)->next = temp;
}
void unshift(List **ptr) {
  List *temp = *ptr;
  *ptr = (*ptr)->next;
  free(temp);
}
void push(List **ptr, int val) {
  while (*ptr != NULL) {
    ptr = &((*ptr)->next);
  }
  shift(ptr, val);
}
void pop(List **ptr) {
  while ((*ptr)->next != NULL) {
    ptr = &((*ptr)->next);
  }
  unshift(ptr);
}
void ordInsert(List **ptr, int val) {
  while (*ptr != NULL) {
    if ((*ptr)->val < val) {
      ptr = &((*ptr)->next);
    } else {
      shift(ptr, val);
      return;
    }
  }
  shift(ptr, val);
}
void printList(List *ptr) {
  while (ptr != NULL) {
    printf("%d ", ptr->val);
    ptr = ptr->next;
  }
}
int searchValue(List *ptr, int val) {
  while (ptr != NULL) {
    if (ptr->val == val) {
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}
void reverseList(List **ptr) {
  List *old = NULL;
  while (*ptr != NULL) {
    List *next = (*ptr)->next;
    (*ptr)->next = old;
    old = (*ptr);
    *ptr = next;
  }
  *ptr = old;
}
void cloneList(List *src, List **dest) {
  while (src != NULL) {
    push(dest, src->val);
    src = src->next;
  }
}

// btrees
struct btree {
  int val;
  struct btree *rightPtr;
  struct btree *leftPtr;
};
typedef struct btree BST;
void initBST(BST **ptr) { *ptr = NULL; }
void insertNode(BST **ptr, int val) {
  if (*ptr == NULL) {
    *ptr = (BST *)malloc(sizeof(BST));
    (*ptr)->val = val;
    (*ptr)->rightPtr = NULL;
    (*ptr)->leftPtr = NULL;
  } else {
    if (val <= (*ptr)->val) {
      insertNode(&((*ptr)->leftPtr), val);
    } else {
      insertNode(&((*ptr)->rightPtr), val);
    }
  }
}
BST *removeNode(BST *ptr, int val) {
  if (ptr == NULL)
    return NULL;

  if (val < ptr->val) {
    ptr->leftPtr = removeNode(ptr->leftPtr, val);
  } else if (val > ptr->val) {
    ptr->rightPtr = removeNode(ptr->rightPtr, val);
  }

  else {
    if (ptr->leftPtr == NULL && ptr->rightPtr == NULL) {
      free(ptr);
      return NULL;
    } else if (ptr->leftPtr != NULL) {
      BST *temp = ptr->leftPtr;
      free(ptr);
      return temp;
    } else if (ptr->rightPtr != NULL) {
      BST *temp = ptr->rightPtr;
      free(ptr);
      return temp;
    } else {
      int rightMin;
      BST *right = ptr->rightPtr;
      while (right->leftPtr != NULL) {
        right = right->leftPtr;
      }
      rightMin = right->val;
      ptr->val = rightMin;
      ptr->rightPtr = removeNode(ptr->rightPtr, rightMin);
    }
  }

  return ptr;
}
void printBST(BST *ptr) {
  if (ptr != NULL) {
    printf("%d ", ptr->val);
    printBST(ptr->leftPtr);
    printBST(ptr->rightPtr);
  }
}
void printBST2D(BST *ptr, int spaces) {
  if (ptr != NULL) {
    printBST2D(ptr->rightPtr, spaces * 2);

    for (int i = 0; i < spaces; i++) {
      printf(" ");
    }
    printf("%d", ptr->val);
    printf("\n\n\n\n");

    printBST2D(ptr->leftPtr, spaces * 2);
  }
}

// main
int main(void) {
  // lls
  List *newList;

  init(&newList);
  printf("%d\n", isEmpty(newList));

  ordInsert(&newList, 3);
  ordInsert(&newList, 7);
  ordInsert(&newList, 9);
  ordInsert(&newList, 11);
  ordInsert(&newList, 1);
  ordInsert(&newList, 19);
  ordInsert(&newList, -3);

  printList(newList);
  printf("\n");

  unshift(&newList);

  printList(newList);
  printf("\n");

  printf("%d\n", searchValue(newList, 11));

  reverseList(&newList);

  printList(newList);
  printf("\n");

  List *clonedList;
  cloneList(newList, &clonedList);

  printList(clonedList);
  printf("\n");

  printf("\n");
  printf("##########################");
  printf("\n\n");

  // btrees
  BST *newBST;
  int spaces = 8;
  initBST(&newBST);

  insertNode(&newBST, 3);
  insertNode(&newBST, 6);
  insertNode(&newBST, 1);
  insertNode(&newBST, 5);
  insertNode(&newBST, 1);
  insertNode(&newBST, 9);
  insertNode(&newBST, 2);

  printBST2D(newBST, spaces);
  printf("\n\n\n\n");

  removeNode(newBST, 3);

  printBST2D(newBST, spaces);
  printf("\n\n\n\n");

  return 0;
}