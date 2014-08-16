/***
 * @author Belkacem LAHOUEL
 * UTBM: University of Technology of Belfort-Montbeliard
 * 08/2014
 * belkacem.lahouel@utbm.fr
 *
 * Code for classic and simple Queue of int.
 ***/

#include <stdio.h>
#include <stdlib.h>

/***
 * Definitions for Node and Queue data-structures.
 ***/

typedef struct _Node {
    int value;
    struct _Node* next;
} Node;	

typedef struct _Queue {
    Node* top;
    int nb_nodes;
} Queue;

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
 * This is more convenient when coming to Queue management.
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
 * Checks whether the Queue is empty or not.
 * TRUE means that the Queue is empty.
 * FALSE means that the Queue is not empty.
 ***/

Boolean is_empty(Queue _ll) {
    if (_ll.nb_nodes <= 0) {
        return TRUE;
    }
    return FALSE;
}

/***
 * Creation of an empty Queue.
 * Returns this newly created Queue.
 ***/

Queue init_queue() {
    Queue new_ll;
    new_ll.top = NULL;
    new_ll.nb_nodes = 0;
    return new_ll;
}

/***
 * Removal of all Nodes in the Queue.
 * Returns this updated and empty Queue.
 ***/

Queue empty_queue(Queue _ll) {
    Node* tmp = _ll.top;
    while (tmp != NULL) {
        tmp = remove_node(tmp);
        -- _ll.nb_nodes;
    }
    _ll.top = NULL;
    return _ll;
}

/***
 * Adding an int in the head of the Queue.
 * Returns the updated Queue.
 ***/

Queue enqueue(Queue _ll, int _new_value) {
    Node* new_node = create_node(_new_value);
    new_node->next = _ll.top;
    ++ _ll.nb_nodes;
    _ll.top = new_node;
    return _ll;
}

/***
 * Removes the tail of the Queue (last Node).
 * Returns a pointer on the updated Queue.
 ***/

Queue dequeue(Queue _ll) {
	if (is_empty(_ll) == FALSE) {
		Node* tmp = _ll.top;
		if (tmp->next != NULL) {
			for (tmp; tmp->next->next != NULL; tmp = tmp->next) {}
			tmp->next = remove_node(tmp->next);
			tmp->next = NULL;
		} else {
			tmp = remove_node(tmp);
			_ll.top = tmp;
		}
		-- _ll.nb_nodes;
	}

	return _ll;
}

/***
 * Prints the whole Stack.
 ***/

void print_queue(Queue _ll) {
    if (is_empty(_ll) == FALSE) {
        Node* tmp = _ll.top;
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
 * The user should only use the Stack data-structure with its functions.
 ***/

int main(int argc, char** argv) {
    Queue tmp_ll = init_queue();

    tmp_ll = dequeue(tmp_ll);
    print_queue(tmp_ll);

    tmp_ll = enqueue(tmp_ll, 13);
    print_queue(tmp_ll);

    tmp_ll = enqueue(tmp_ll, 14);
    print_queue(tmp_ll);

    tmp_ll = dequeue(tmp_ll);
    print_queue(tmp_ll);

    tmp_ll = enqueue(tmp_ll, 17);
    print_queue(tmp_ll);

    tmp_ll = dequeue(tmp_ll);
    print_queue(tmp_ll);

    tmp_ll = empty_queue(tmp_ll);
    print_queue(tmp_ll);

    return EXIT_SUCCESS;
}
