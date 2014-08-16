/***
 * @author Belkacem LAHOUEL
 * UTBM: University of Technology of Belfort-Montbeliard (France)
 * 08/2014
 * belkacem.lahouel@utbm.fr
 *
 * Code for improved double LinkedList data-structure creation.
 *
 * @todo
 * Some functions can be added to this API. For an example, consider those:
 *      insert_at(LinkedList, int, int)
 *      remove_at(LinkedList, int)
 *      get_at(LinkedList, int)
 *      sort(LinkedList)
 *      ...
 * We can use this very API to build other similar data-structures.
 * To do so, we need to change function names. For an example, consider those:
 *      Stack
 *      Queue
 ***/

#include <stdio.h>
#include <stdlib.h>

/***
 * Structures definitions for Node and LinkedList types.
 ***/

typedef struct _Node {
    int value;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _LinkedList {
    Node* first_node;
    Node* last_node;
    int nb_nodes;
} LinkedList;

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
    new_node->prev = NULL;
    return new_node;
}

/***
 * Removal of a Node and memory freeing.
 * Removes the Node and returns the address on the next Node.
 * Keeps previous and next Nodes together.
 * This is more convenient when coming to LinkedList management.
 ***/

Node* remove_node(Node* _node) {
    if (_node != NULL) {
        if (_node->prev != NULL) {
            _node->prev->next = _node->next;
        }
        if (_node->next != NULL) {
            _node->next->prev = _node->prev;
        }
        Node* tmp = _node->next;
        _node->value = 0;
        _node->next = NULL;
        _node->prev = NULL;
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
    if (_ll.nb_nodes == 0) {
        return TRUE;
    }
    return FALSE;
}

/***
 * Creation of an empty LinkedList.
 * Returns this newly created LinkedList.
 ***/

LinkedList init_linkedlist() {
    LinkedList new_ll;
	new_ll.first_node = NULL;
    new_ll.last_node = NULL;
    new_ll.nb_nodes = 0;
    return new_ll;
}

/***
 * Removal of all Nodes in the LinkedList.
 * Returns this updated and empty LinkedList.
 ***/

LinkedList empty_linkedlist(LinkedList _ll) {
    Node* tmp = _ll.first_node;
    while (tmp != NULL) {
        tmp = remove_node(tmp);
        -- _ll.nb_nodes;
    }
    _ll.first_node = NULL;
    _ll.last_node = NULL;
    return _ll;
}

/***
 * Adding an int in the head of the LinkedList.
 * Returns the updated LinkedList.
 ***/

LinkedList add_head(LinkedList _ll, int _new_value) {
    Node* new_node = create_node(_new_value);
    new_node->next = _ll.first_node;
    if (_ll.nb_nodes == 0) {
        _ll.last_node = new_node;
    } else {
        _ll.first_node->prev = new_node;
    }
    ++ _ll.nb_nodes;
    _ll.first_node = new_node;
    return _ll;
}

/***
 * Adding an int in the tail of the LinkedList.
 * Returns the updated LinkedList.
 ***/

LinkedList add_tail(LinkedList _ll, int _new_value) {
    Node* new_node = create_node(_new_value);
    if (is_empty(_ll) == TRUE) {
        _ll.first_node = new_node;
        _ll.last_node = new_node;
    } else {
        _ll.last_node->next = new_node;
        new_node->prev = _ll.last_node;
    }
    _ll.last_node = new_node;
    ++ _ll.nb_nodes;
    return _ll;
}

/***
 * Removes the head of the LinkedList (first Node).
 * Returns a pointer on the updated LinkedList.
 ***/

LinkedList remove_head(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        _ll.first_node = remove_node(_ll.first_node);
		_ll.first_node->prev = NULL;
        -- _ll.nb_nodes;
    }
    return _ll;
}

/***
 * Removes the tail of the LinkedList (last Node).
 * Returns the updated LinkedList.
 ***/

LinkedList remove_tail(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        Node* tmp = _ll.last_node;
        _ll.last_node = tmp->prev;
        tmp = remove_node(tmp);
        -- _ll.nb_nodes;
    }
    return _ll;
}

/***
 * Prints the whole LinkedList.
 ***/

void print_linkedlist(LinkedList _ll) {
    if (is_empty(_ll) == FALSE) {
        Node* tmp = _ll.first_node;
        printf("%d", tmp->value);
        tmp = tmp->next;
        for (tmp; tmp != NULL; tmp = tmp->next) {
            printf("->%d", tmp->value);
        }
        if (_ll.nb_nodes == 1) {
            printf(" (1 node)");
        } else {
            printf(" (%d nodes)", _ll.nb_nodes);
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

    tmp_ll = remove_head(tmp_ll); // EMPTY
    tmp_ll = add_head(tmp_ll, 13); // 13 (1 node)
	print_linkedlist(tmp_ll);

    tmp_ll = add_head(tmp_ll, 14); // 14->13 (2 nodes)
    tmp_ll = remove_head(tmp_ll); // 13 (1 node)
    tmp_ll = add_tail(tmp_ll, 17); // 13->17 (2 nodes)
    tmp_ll = remove_tail(tmp_ll); // 13 (1 node)
    tmp_ll = empty_linkedlist(tmp_ll); // EMPTY

    print_linkedlist(tmp_ll);

    return EXIT_SUCCESS;
}
