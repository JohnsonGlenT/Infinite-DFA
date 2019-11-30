#ifndef DFA_H
#define DFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct edge Edge;
typedef struct dfa DFA;

struct node {
    int number;
    Edge** out;
};

Node* createNode(int);

struct edge {
    char next;
    Node* dest;
};

Edge* createEdge(Node*, char);

struct dfa {
    int q;
    Node** allNodes;
    int sigmaLen;
    char* sigma;
    Edge*** allTrans;
    Node* inital;
    Node** exit;
};

DFA* createDFA();
int validDFA(DFA*);

int indexOf(char*, char);

#endif
