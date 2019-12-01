#ifndef DFA_H
#define DFA_H

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ENUM
enum COLOR {WHITE = 0, GREY = 1, BLACK = 2};

// TYPEDEFS
typedef struct node Node;
typedef struct edge Edge;
typedef struct dfa DFA;

// NODE STRUCT
struct node {
    int color;
    int number;
    int infinite;
    Edge** out;
};

// NODE FUNCTIONS
Node* createNode(int);

int infinite(DFA*);
int canSolve(DFA*, Node* pos);
int canReach(DFA*, Node* pos);
int search(DFA*, Node* init, Node* goal);
int infSearch(DFA*, Node* init, Node* goal);

// EDGE STRUCT
struct edge {
    char next;
    Node* dest;
};

// EDGE FUNCTIONS
Edge* createEdge(Node*, char);

void attachEdges(DFA*);

// DFA STRUCT
struct dfa {
    int q;
    Node** allNodes;
    int sigmaLen;
    char* sigma;
    Edge*** allTrans;
    int exitNum;
    Node** exit;
    Node* inital;
};

// DFA FUNCTIONS
DFA* createDFA();

int isValidDFA(DFA*);
int indexOf(char*, char);

#endif
