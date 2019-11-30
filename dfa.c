#include "dfa.h"

Node* createNode(int n) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->number = n;
    return node;
}

Edge* createEdge(Node* n, char c) {
    Edge* e = (Edge*) malloc(sizeof(Edge));
    e->next = c;
    e->dest = n;
    return e;
}

DFA* createDFA() {
    return (DFA*) malloc(sizeof(DFA));
}

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
