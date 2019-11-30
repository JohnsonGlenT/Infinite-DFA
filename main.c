#include "main.h"

int main(int argc, char** argv) {
   
    DFA* dfa = scanFile(argv[1]);
    if (!isValidDFA(dfa)) {
        printf("Invalid DFA.\nExiting.\n");
        return 1;
    }
    attachEdges(dfa);
    return 0;
}

DFA* scanFile(char* txt) {
    if (txt == NULL) { return NULL; } 
    FILE* fp = fopen(txt, "rw");
    
    DFA* dfa = createDFA();
    int tmp;
    int out;
    int index;
    char c[1];
    char f;

    f = fscanf(fp, "%d", &tmp);
    if (f == EOF) { return NULL; }

    dfa->q = tmp;
    dfa->allNodes = (Node**) malloc(sizeof(Node*)*tmp); 
    
    for (int i = 0; i < tmp; i++) {
        dfa->allNodes[i] = createNode(i);
    }

    f = fscanf(fp, "%d", &tmp);
    if (f == EOF) { return NULL; }

    dfa->sigmaLen = tmp;
    dfa->sigma = (char*) malloc(sizeof(tmp));

    for (int i = 0; i < tmp; i++) {
        f = fscanf(fp, "%s", c);
        if (f == EOF) { return NULL; }
        dfa->sigma[i] = c[0];
    }

    dfa->allTrans = (Edge***) malloc(sizeof(Edge**)*dfa->q);
    
    for (int i = 0; i < dfa->q; i++) {
        dfa->allTrans[i] = (Edge**) malloc(sizeof(Edge*)*dfa->sigmaLen);
    }
    
    for (int i = 0; i < (dfa->q * dfa->sigmaLen); i++) {
        f = fscanf(fp, "%d %s %d", &tmp, c, &out);
        if (f == EOF) { return NULL; }
        if (tmp < 0 || tmp > dfa->q) { return NULL; }
        if (out < 0 || out > dfa->q) { return NULL; }
        index = indexOf(dfa->sigma, c[0]);
        if (index == -1) { return NULL; } 
        dfa->allTrans[index][tmp] = createEdge(dfa->allNodes[out], c[0]);
    }
    
    f = fscanf(fp, "%d", &tmp);
    if (f == EOF) { return NULL; }
    if (tmp < 0 || tmp > dfa->q) { return NULL; }
    dfa->inital = dfa->allNodes[tmp];

   
    f = fscanf(fp, "%d", &tmp);
    if (f == EOF) { return NULL; }
    if (tmp < 0 || tmp > dfa->q) { return NULL; }
    dfa->exit = (Node**) malloc(sizeof(Node*)*tmp);
    
    for (int i = 0; i < tmp; i++) {
        f = fscanf(fp, "%d", &out);
        if (f == EOF) { return NULL; }
        dfa->exit[i] = dfa->allNodes[out];
    }

    return dfa;
}
