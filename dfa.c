#include "dfa.h"

/*  
 *  Creates a Node
 *  Node gets state number of n
 *
 */

Node* createNode(int n) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->number = n;
    node->color = WHITE;
    node->infinite = 0;
    return node;
}

/*
 * Checks if there are any loops in DFA
 * Returns 1 if loops can be reached and
 * you can exit from the loops
 *
 */

int infinite(DFA* dfa) {
    for (int i = 0; i < dfa->q; i++) {
        if(infSearch(dfa, dfa->allNodes[i], dfa->allNodes[i]) 
                        && canReach(dfa, dfa->allNodes[i]) 
                        && canSolve(dfa, dfa->allNodes[i])) {
            return 1;
        }
    }
    
    return 0;    
}

/*
 * Checks if the DFA can
 * be completed from a node
 * returns 1 if it can
 *
 */

int canSolve(DFA* dfa, Node* pos) {
    for (int i = 0; i < dfa->exitNum; i ++) {
        if (search(dfa, pos, dfa->exit[i])) {
            return 1;
        }
    }
    return 0;
}

/* 
 * Checks if the DFA can
 * reach a node form the start
 * returns 1 if it can
 *
 */

int canReach(DFA* dfa, Node* pos) {
    return search(dfa, dfa->inital, pos);
}

/*
 * Searches for a node from a node recursivly
 * returns 1 if it can
 *
 */

int search(DFA* dfa, Node* init, Node* goal) {
    if (init == goal) {
        init->color = BLACK;
        return 1;
    }

    init->color = GREY;
    for (int j = 0; j  < dfa->sigmaLen; j++) {
        if (init->out[j]->dest != init) {
            if (search(dfa, init->out[j]->dest, goal)) {
                init->color = BLACK;
                return 1;
            }
        }
    }

    return 0;
}

/*
 * Same search function but checks
 * checks the return state in the for loop
 *
 */

int infSearch(DFA* dfa, Node* init, Node* goal) {
    init->color = GREY;

    for (int j = 0; j  < dfa->sigmaLen; j++) {
        if (init->out[j]->dest == goal) {
            init->color = BLACK;
            init->infinite = 1;
            return 1;
        }

       if (init->out[j]->dest != init) {
            if (infSearch(dfa, init->out[j]->dest, goal)) {
                init->color = BLACK;
                init->infinite = 1;
                return 1;
            }
        }
    }

    return 0;
}

/*
 * Creates an Edge that goes to node n
 * and uses char c
 * Returns the Edge
 *
 */

Edge* createEdge(Node* n, char c) {
    Edge* e = (Edge*) malloc(sizeof(Edge));
    e->next = c;
    e->dest = n;
    return e;
}

/* 
 * Attaches the Edges of the nodes
 * to the DFA node list
 *
 */

void attachEdges(DFA* dfa) {
    for (int i = 0; i < dfa->q; i++) {
        for (int j = 0; j < dfa->sigmaLen; j++) {
            dfa->allNodes[i]->out = dfa->allTrans[i];
        }
    }
}

/*
 * Creates a DFA
 * Returns a DFA
 *
 */

DFA* createDFA() {
    return (DFA*) malloc(sizeof(DFA));
}

/*
 * Checks if the dfa transistion table
 * is complete, and accurate,
 * only thing not checked in scan file
 * Returns 1 if dfa is valid
 *
 */

int isValidDFA(DFA* dfa) {
    if (dfa == NULL) { return 0; }

    for (int i = 0; i < dfa->sigmaLen; i++) {
        for (int j = 0; j < dfa->q; j++) {
            if (dfa->allTrans[i][j] == NULL) {
                return 0;
            }
        }
    }

    return 1;
}

/*
 * Gets the index of a character in an array
 * returns index if found
 * else returns -1
 *
 */

int indexOf(char* arr, char c) {
    int i = 0;
    while(arr != NULL) {
        if((*arr) == c) {
                return i;
        }
        i++;
        arr++;
    }
    return -1;
}

