#include <stdio.h>
#include <stdlib.h>

// The best use cases for linked lists are stacks and queues, which we will now implement

// Adding an item to the beginning of the lish (pushing to the list)

// Pseudocode:
// 1. Create a new item and set its value
// 2. Link the new list to point to the head of our list
// 3. Set the head of the linked list to be our new item

// This will effectively create a new head to the list with a new value, and keep the rest of the list linked to it

// Since we use a function to do this operation, we want to be able to modify the head variable, to do this we pass point a pointer the pointer variable
// (a double pointer) so we will be able to modify the pointer itself:

typedef struct node {
    int val;
    struct node * next;
} node_t;

void push_to_head(node_t ** head, int val) {
    // create a new item
    node_t *new_head;

    // need to allocate memory, because the new_head is created when the function is called - not created here
    new_head = (node_t *) malloc(sizeof(node_t)); 
    
    // set its value
    new_head->val = val;
    
    // link the new_head to the head of the linked list
    new_head->next= * head;

    // set the head of the linked list to be our new item

    (*head) = new_head;

}

// Removing the first item (popping from the list) - and return its value

// Take the next item that the head points to and save it
// Free the head item
// set the head to be the next item that we've stored on the side

int pop(node_t **head) {
    int retval = -1;

    node_t * new_head = NULL;

    if (*head == NULL) {
        return -1;
    }

    new_head = (*head)->next;

    // free the old head node
    retval = (*head)->val;
    // int retval = *((*head)).val;

    free(*head);

    (*head) = new_head;

    return retval;
}

// removing the last item of the list and returning its value

int remove_last(node_t * head) {

    int retval = 0;
    // if there is only one item it in the list remove it
    if (head->next == NULL) {
        retval = (head)->val;
        free(head);
        return retval;
    }

    // find SECOND TO LAST item - and set the next pointer to NULL
    // need to iterate through the list

    node_t * current = head;
    while (current->next->next != NULL) {
        // update current
        current = current->next;
    }

    // once exit loop we are at second the last node
    retval = current->next->val;
    free(current->next);    
    current->next = NULL;
    return retval;

}

// removing a specific item by index

// int remove_by_index(node_t ** head, int n) {
//     int index = 0; // first node
//     int retval = 0;
//     node_t * slow_pointer = *head;
//     node_t * fast_pointer = *head;
//     while (index != n - 1) {
//         slow_pointer = slow_pointer->next;
//         fast_pointer = fast_pointer->next->next->next;
//         index++;
//     }
//     retval = slow_pointer->next->val;
//     free(slow_pointer->next);
//     slow_pointer->next = fast_pointer;

//     return retval;
//     // now index = n - 1, i.e. current is at the node before the node we want to remove
//     // need to set this node's next to the node after the next

    
// }

// int remove_by_index(node_t ** head, int n) {

//     // Pseudocode:
//     // 1. iterate to the node before the node we wish to delete
//     // 2. save the node we wish to delete in a temporary pointer
//     // 3. set the previous node's next pointer to point to the node after the node we wish to delete
//     // 4. delete the node using the temporary pointer

//     node_t * current = *head;
//     node_t * temp_node;

//     for (int i = 0; i < n-1; i++) {
//         current = current->next;
//     }
//     // reached the node before the delete node
//     temp_node = current->next;
//     int retval = -1;
//     retval = temp_node->val;
    
//     current->next = temp_node->next;
//     free(temp_node);

    
// }

int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;

    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        // remove first element
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        // iterates until we are at the node one before end node we want to remove
        if (current->next == NULL) {
            // want to remove an index that doesn't exist (for example, linked list if 5 elements long and index is 5)
            return -1;
        }
        current = current->next;
    }

    // after loop ends we are at the node one before the one we want to remove

    if (current->next == NULL) {
        // we are already at the end of the linked list and again we are trying to remove an index that doesn't exist
        return -1; // remember, -1 means an error or some expectional condition has occurred
    } 

    temp_node = current->next;
    retval = temp_node->val;

    current->next = temp_node->next;
    free(temp_node); // temp_node still has the pointer value, but th

    return temp_node; 

}

int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
        // first node was node to remove
        // if first node is removed we exit code (return)
    }

    // only reach this block if the first node isn't the one we want to remove

    previous = *head;
    current = (*head)->next;

    // now we need to move through the linked list

    // but first check this current
    while (current) {
        // while (current != NULL) {}
            if (current->val == val) {
            // next node is the node we want to remove
            // set previous to point to the node after current
            previous->next = current->next;
            free(current);
            return val;
        }
        previous = current;
        current = current->next;
    }

    return -1;
}

int main() {

}
