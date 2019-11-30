#ifndef DFA_H
#define DFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum COLOR {WHITE = 0, GREY = 1, BLACK = 2, CYAN = 3};

typedef struct node Node;
typedef struct edge Edge;
typedef struct dfa DFA;

struct node {
    int color;
    int number;
    Edge** out;
};

Node* createNode(int);

int infinite(DFA*);
int canSolve(DFA*, Node* pos);
int canReach(DFA*, Node* pos);

struct edge {
    char next;
    Node* dest;
};

Edge* createEdge(Node*, char);

void attachEdges(DFA*);

struct dfa {
    int q;
    Node** allNodes;
    int sigmaLen;
    char* sigma;
    Edge*** allTrans;
    Node** exit;
    Node* inital;
};

DFA* createDFA();

int isValidDFA(DFA*);
int indexOf(char*, char);

#endif
