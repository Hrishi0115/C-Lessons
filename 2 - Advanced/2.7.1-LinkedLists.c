// Linked lists are the best and simplest example of a dynamic data structure that uses pointers for its implementation.
// Essentially linked lists function as an array that can grow and shrink as needed, from any point in the array.

// Linked lists have a few advantages over arrays:

// 1. Items can be added or removed from the middle of the list
// 2. There is no need to define an initial size

// Disadvantages:
// 1. no random access - impossible to reach the nth item in the array without first iterating over all items up until that item - this means we have to start
// from the beginning of the list and count how many times we advance in the list until we get to the desired item
// 2. dynamic memory allocation and pointers are required - which complicates code and increases risk of memory leaks and segment faults
// 3. linked lists have a much larger overhead (refers to the extra resources required to manage a data structure/perform an operation, beyond the actual data
// itself) over arrays, since linked list items are dynamically allocated (less efficient in memory usage) and each item in the list also must store an
// additional pointer.

// A linked list is a set of dynamically allocated nodes, arranged in such a way that each node contains one value and one pointer.
// The pointer always points to the next member of the list. If the pointer is NULL, then it is the last node in the list.
// A linked list is held using a local pointer variable which points to the first item of the list. If that pointer is also NULL, then the list is 
// considered to be empty.

// ------------------------------              ------------------------------
// |              |             |            \ |              |             |
// |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
// |              |             |            / |              |             |
// ------------------------------              ------------------------------

// lets define a linked list node

#include <stdio.h>
#include <stdlib.h>

// Structure recap

typedef struct tag_name { // the tag name is used for referring to the structure within its own definition (for recursive structures).
    int val;
    struct tag_name * next; // pointer
} node_alias; // alias used for referring to the structure type outside of the structure definition without having to repeatedly use the struct keyword, i.e.
// struct tag_name example

typedef struct node {
     int val;
     struct node * next; // pointer
} node_t;

// Notice that we are defining the struct is a recursive manner, which is possible in C. Let's name our node type node_t.

// Now we can use the nodes. Let's create a local variable which points to the first item of the list, the head.

int ex1() {
    node_t * head = NULL; // pointer of type node_t called head currently pointing to nothing
    head = (node_t *) malloc(sizeof(node_t)); // head still points to nothing - but we want to give to memory so it can point to something later
    // so now head points to an empty pointer of type node_t with the memory of the size of a 1 node_t

    if (head == NULL) {
        // checking if malloc returned a NULL VALUE (failed) or not
        return 1;
    }

    head->val = 1; // val for the node struct that exists at the memory address head points to is set to 1

    // adding an second node to the linked list

    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;

    // this can go on and on, but what we should actually do is advance to the last item of the list, until the next variable will be NULL
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// Adding an item to the end of the list

// attempt one below - incorrect

void push_attempt_one(node_t * head, int val) {

    // check if the list is empty
    if (head == NULL) {
        // What's incorrect about this - 
        // Local head variable - in this if block, head is a new local variable and not actually the 

        // first need to allocate memory
        head = (node_t *) malloc(sizeof(node_t));
        head->val = val;
        head->next = NULL;
    }

    // if list is not empty

    else {
        node_t * current = head; // new pointer of type node_t called current equal to head (a pointer of type node_t pointing somewhere)
        // need to loop through linked list until we reach the end
        while (current->next != NULL) {
            // means there is a next node
            current = current->next;
        }
        // as soon as there is no next node, i.e. we are at the last node, we exit the while loop
        
        current->next = (node_t *) malloc(sizeof(node_t));
        current->next->val = val;
        current->next->next = NULL;
    }
}

void corrected_push(node_t **head, int val) {
    // 0000000000000000 - null pointer
    // head is a pointer to a pointer
    if (*head == NULL) {
        // dereference head - remember a pointer is just a int that is a memory address
        // firstly what is head - a pointer to the pointer that points to the memory address of the first node of the list
        // so when we deference head, we get the object, value that head points to - which is the pointer's value - which is the memory address
        // of the first node of the list
        // so if we deference head, we get the value of the thing that head is pointing to
        // head's value is a memory address where an object lives and that is the value we're finding
        // but if this pointer's value (the memory it is pointing to) is NULL (i.e. it doesn't point to a node) the linked list is empty
    
        *head = (node_t *) malloc(sizeof(node_t));
        (*head)->val=val;
        (*head)->next = NULL;
    } 

    else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (node_t *) malloc(sizeof(node_t));
        current->next->val = val;
        current->next->next = NULL;
    }
}

// given solution (doesn't account for the scenario where the linked list is empty)

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}


int main() {
    node_t *head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;

    push(head,2);
    push(head,3);

    print_list(head);

    node_t *current = head;
    node_t *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

