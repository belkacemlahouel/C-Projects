/***
 * @author Belkacem LAHOUEL
 * UTBM: University of Technology of Belfort-Montbeliard (France)
 * 08/2014
 * belkacem.lahouel@utbm.fr
 *
 * Code for simple LinkedList data-structure creation.
 ***/

#include <stdio.h>
#include <stdlib.h>

/***
 * Structures definitions for Node and LinkedList types.
 ***/

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef Node* LinkedList;

/***
 * Definition of a new data-type: Boolean.
 ***/

typedef enum _Boolean {
    TRUE,
    FALSE
} Boolean;

/***
 * Creation of a Node with an int.
 ***/

Node* create_node(int _value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = _value;
    new_node->next = NULL;
    return new_node;
}

/***
 * Removal of a Node and memory freeing.
 * Removes the Node and returns the address on the next Node.
 ***/

Node* remove_node(Node* _node) {
    if (_node != NULL) {
        Node* tmp = _node->next;
        _node->value = 0;
        _node->next = NULL;
        free(_node);
        return tmp;
    } else return NULL;
}

/***
 * Checks whether the LinkedList is empty or not.
 * TRUE means that the LinkedList is empty.
 * FALSE means that the LinkedList is not empty.
 ***/

Boolean is_empty(LinkedList _ll) {
    if (_ll == NULL) {
        return TRUE;
    }
    return FALSE;
}

/***
 * Creation of a LinkedList with a first int.
 * Returns a pointer on this (first element) LinkedList.
 * @deprecated Better use init_linkedlist with add_head/add_tail.
 ***/

LinkedList create_linkedlist(int _first_value) {
    Node* first_element = create_node(_first_value);
    LinkedList new_ll = first_element;
    return new_ll;
}

/***
 * Initialization of a LinkedList with nothing.
 * Returns a pointer on this newly created LinkedList.
 ***/

LinkedList init_linkedlist() {
	LinkedList new_ll = NULL;
	return new_ll;
}

/***
 * Removal of the whole LinkedList.
 * Returns a pointer on the beginning of this LinkedList (checking).
 ***/

LinkedList empty_linkedlist(LinkedList _ll) {
    Node* tmp = _ll;
    while (tmp != NULL) {
        tmp = remove_node(tmp);
    }
    return NULL;
}

/***
 * Adding an int in the head of the LinkedList.
 * Returns the updated LinkedList.
 ***/

LinkedList add_head(LinkedList _ll, int _new_value) {
	Node* new_node = create_node(_new_value);
    new_node->next = _ll;
    _ll = new_node;
    return _ll;
}

/***
 * Adding an int in the tail of the LinkedList.
 * Returns the updated LinkedList.
 ***/

LinkedList add_tail(LinkedList _ll, int _new_value) {
    Node* new_node = create_node(_new_value);
    if (is_empty(_ll) == FALSE) {
        Node* tmp = _ll;
        for (tmp; tmp->next != NULL; tmp = tmp->next) {}
        tmp->next = new_node;
    } else {
        _ll = new_node;
    }
    return _ll;
}

/***
 * Removes the head of the LinkedList (first Node).
 * Returns a pointer on the updated LinkedList.
 ***/

LinkedList remove_head(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        _ll = remove_node(_ll);
    }
    return _ll;
}

/***
 * Removes the tail of the LinkedList (last Node).
 * Returns the updated LinkedList.
 ***/

LinkedList remove_tail(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        if (_ll->next != NULL) {
            Node* tmp = _ll;
            while (tmp->next->next != NULL) {
                tmp = tmp->next;
            }
            remove_node(tmp->next);
            tmp->next = NULL;
            return _ll;
        }
        _ll = remove_node(_ll);
        return _ll;
    } else return;
}

/***
 * Prints the whole LinkedList.
 ***/

void print_linkedlist(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        Node* tmp = _ll;
        printf("%d", tmp->value);
        tmp = tmp->next;
        for (tmp; tmp != NULL; tmp = tmp->next) {
            printf("->%d", tmp->value);
        }
    } else {
        printf("EMPTY");
    }
    printf("\n");
}

/***
 * Main function used to test this data-structure functions.
 * The Node data-structure is not supposed to be directly used by the user.
 * The user should only use the LinkedList data-structure with its functions.
 ***/

int main(int argc, char** argv) {
	LinkedList tmp_ll = init_linkedlist();
	tmp_ll = add_head(tmp_ll, 14);
	tmp_ll = add_head(tmp_ll, 17);
	print_linkedlist(tmp_ll);

    /* tmp_ll = add_head(tmp_ll, 13);
    tmp_ll = add_head(tmp_ll, 14);
    tmp_ll = remove_head(tmp_ll);
    tmp_ll = add_tail(tmp_ll, 17);
    tmp_ll = remove_tail(tmp_ll);*/
    tmp_ll = empty_linkedlist(tmp_ll);

    print_linkedlist(tmp_ll);

    return EXIT_SUCCESS;
}
