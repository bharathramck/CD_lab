//WRITE PROGRAM TO FIND € CLOSURE OF ALL STATES OF ANY GIVEN NFA WITH TRANSITION.
#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 100

typedef struct {
    int statenum;
    int transitions[MAX_STATES];
} State;

void findEpsilonClosure(State nfa[], int currentState, bool visited[]) {
    if (visited[currentState])
        return;
    
    visited[currentState] = true;
    printf("%d ", currentState);

    for (int i = 0; nfa[currentState].transitions[i] != -1; i++) {
        findEpsilonClosure(nfa, nfa[currentState].transitions[i], visited);
    }
}

void findEpsilonClosures(State nfa[], int numStates) {
    for (int i = 0; i < numStates; i++) {
        printf("Epsilon closure of state %d: ", i);
        bool visited[MAX_STATES] = {false};
        findEpsilonClosure(nfa, i, visited);
        printf("\n");
    }
}

int main() {
    State nfa[MAX_STATES];

    nfa[0].statenum = 0;
    nfa[0].transitions[0] = 1;
    nfa[0].transitions[1] = 2;
    nfa[0].transitions[2] = -1;

    nfa[1].statenum = 1;
    nfa[1].transitions[0] = 3;
    nfa[1].transitions[1] = -1;

    nfa[2].statenum = 2;
    nfa[2].transitions[0] = 4;
    nfa[2].transitions[1] = -1;

    nfa[3].statenum = 3;
    nfa[3].transitions[0] = -1;

    nfa[4].statenum = 4;
    nfa[4].transitions[0] = -1;

    int numStates = 5;
    findEpsilonClosures(nfa, numStates);

    return 0;
}
