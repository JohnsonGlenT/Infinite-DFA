#include "dfa.h"

Node* createNode(int n) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->number = n;
    node->color = WHITE;
    return node;
}

int infinite(DFA* dfa) {
    // SINGLE NODE LOOP SCAN
    for (int i = 0; i < dfa->q; i++) {
        for (int j = 0; j < dfa->sigmaLen; j++) {
            if (dfa->allTrans[i][j]->dest == dfa->allNodes[i]) {
                allNodes[i].color = GREY;
                if(canReach(dfa, dfa->allNodes[i]) && canSolve(dfa->allNodes[i]) ) {
                    return 1;
                }
            }
        }
    }

    // MULTIPLE NODE LOOP SCAN
    
}

int canSolve(DFA* dfa, Node* pos) {
    
}

int canReach(DFA* dfa, Node* pos){
    
}

Edge* createEdge(Node* n, char c) {
    Edge* e = (Edge*) malloc(sizeof(Edge));
    e->next = c;
    e->dest = n;
    return e;
}

void attachEdges(DFA* dfa) {
    for (int i = 0; i < dfa->q; i++) {
        for (int j = 0; j < dfa->sigmaLen; j++) {
            dfa->allNodes[i]->out = dfa->allTrans[i];
        }
    }
}

DFA* createDFA() {
    return (DFA*) malloc(sizeof(DFA));
}

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
