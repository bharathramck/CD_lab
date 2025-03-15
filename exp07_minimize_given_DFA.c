//7.Write a program to minimize any given DFA.
#include <stdio.h>
#include <string.h>

#define STATES 99
#define SYMBOLS 20

int N_symbols;
int N_DFA_states;
char *DFA_finals;
int DFAtab[STATES][SYMBOLS];
char StateName[STATES][STATES+1];
int N_optDFA_states;
int OptDFA[STATES][SYMBOLS];
char NEW_finals[STATES+1];

void print_dfa_table(int tab[][SYMBOLS], int nstates, int nsymbols, char *finals) {
    int i, j;
    printf("\nDFA: STATE TRANSITION TABLE\n");
    printf("  | ");
    for (i = 0; i < nsymbols; i++)
        printf(" %c ", '0' + i);
    printf("\n---+");
    for (i = 0; i < nsymbols; i++)
        printf("---");
    printf("\n");
    for (i = 0; i < nstates; i++) {
        printf(" %c | ", 'A' + i);
        for (j = 0; j < nsymbols; j++)
            printf(" %c ", tab[i][j]);
        printf("\n");
    }
    printf("Final states = %s\n", finals);
}

void load_DFA_table() {
    DFAtab[0][0] = 'B'; DFAtab[0][1] = 'C';
    DFAtab[1][0] = 'E'; DFAtab[1][1] = 'F';
    DFAtab[2][0] = 'A'; DFAtab[2][1] = 'A';
    DFAtab[3][0] = 'F'; DFAtab[3][1] = 'E';
    DFAtab[4][0] = 'D'; DFAtab[4][1] = 'F';
    DFAtab[5][0] = 'D'; DFAtab[5][1] = 'E';
    DFA_finals = "EF";
    N_DFA_states = 6;
    N_symbols = 2;
}

void get_NEW_finals(char *newfinals, char *oldfinals, char stnt[][STATES+1], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strchr(oldfinals, stnt[i][0]))
            *newfinals++ = i + 'A';
    }
    *newfinals = '\0';
}

void main() {
    load_DFA_table();
    print_dfa_table(DFAtab, N_DFA_states, N_symbols, DFA_finals);
    N_optDFA_states = N_DFA_states;
    memcpy(OptDFA, DFAtab, sizeof(DFAtab));
    strcpy(NEW_finals, DFA_finals);
    print_dfa_table(OptDFA, N_optDFA_states, N_symbols, NEW_finals);
}