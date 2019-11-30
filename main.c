#include "main.h"

int main(int argc, char** argv) {
   
    DFA* dfa = scanFile(argv[1]);

    return 0;
}

DFA* scanFile(char* txt) {
    if (txt == NULL) { return NULL; } 
    FILE* fp = fopen(txt, "rw");
    
    DFA* dfa = createDFA();
    int tmp;
    int out;
    int index;
    char c;

    fscanf(fp, "%d", &tmp);
    
    dfa->q = tmp;
    dfa->allNodes = (Node**) malloc(sizeof(Node*)*tmp); 
    
    for(int i = 0; i < tmp; i++) {
        dfa->allNodes[i] = createNode(i);
    }

    fscanf(fp, "%d", &tmp);

    dfa->sigmaLen = tmp;
    dfa->sigma = (char*) malloc(sizeof(tmp));

    for(int i = 0; i < tmp; i++) {
        fscanf(fp, "%c", &c);
        dfa->sigma[i] = c;
    }

    dfa->allTrans = (Edge***) malloc(sizeof(Edge**)*dfa->sigmaLen);
    
    for(int i = 0; i < dfa->sigmaLen; i++) {
        dfa->allTrans[i] = (Edge**) malloc(sizeof(Edge*)*dfa->q);
    }
    
    for(int i = 0; i < (dfa->q * dfa->sigmaLen); i++) {
        fscanf(fp, "%d, %c, %d", &tmp, &c, &out);
        index = indexOf(dfa->sigma, c);
        dfa->allTrans[index][tmp] = createEdge(dfa->allNodes[out], c);
    }
    
    fscanf(fp, "%d", &tmp);
    dfa->inital = dfa->allNodes[tmp];

    fscanf(fp, "%d", &tmp);
    dfa->exit = (Node**) malloc(sizeof(Node*)*tmp);
    
    for(int i = 0; i < tmp; i++) {
        fscanf(fp, "%d", &tmp);
        dfa->exit[i] = dfa->allNodes[tmp];
    }

    return dfa;
}
