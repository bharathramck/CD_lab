//6.WRITE A PROGRAM TO CONVERT NFA TO DFA.
#include <stdio.h>
#include <string.h>
#include <math.h>

int ninputs;
int dfa[100][2][100] = {0};
int state[10000] = {0};
char ch[10], str[1000];
int go[10000][2] = {0};
int arr[10000] = {0};

int main() {
    int st, fin, in;
    int f[10];
    int i, j, s = 0, final = 0, flag = 0, curr1, k, l;
    int c, p, q, r, rel, x = 0;

    printf("\nEnter the number of states: ");
    scanf("%d", &st);
    printf("\nEnter state numbers from 0 to %d: ", st - 1);
    
    for (i = 0; i < st; i++)
        state[(int)(pow(2, i))] = 1;
    
    printf("\nEnter number of final states: ");
    scanf("%d", &fin);
    printf("\nEnter final states: ");
    for (i = 0; i < fin; i++)
        scanf("%d", &f[i]);
    
    printf("\nEnter the number of rules for the NFA: ");
    scanf("%d", &rel);
    printf("\nDefine transition rule as (state input state):\n");
    
    for (i = 0; i < rel; i++) {
        scanf("%d%d%d", &p, &q, &r);
        if (q == 0)
            dfa[p][0][r] = 1;
        else
            dfa[p][1][r] = 1;
    }
    
    printf("\nEnter initial state: ");
    scanf("%d", &in);
    in = pow(2, in);
    
    for (i = 0; i < st; i++) {
        for (j = 0; j < 2; j++) {
            int stf = 0;
            for (k = 0; k < st; k++) {
                if (dfa[i][j][k] == 1)
                    stf += pow(2, k);
            }
            go[(int)(pow(2, i))][j] = stf;
            if (state[stf] == 0) {
                arr[x++] = stf;
                state[stf] = 1;
            }
        }
    }
    
    for (i = 0; i < x; i++) {
        for (j = 0; j < 2; j++) {
            int new_state = 0;
            for (k = 0; k < st; k++) {
                if (arr[i] & (1 << k)) {
                    int h = pow(2, k);
                    if (new_state == 0)
                        new_state = go[h][j];
                    new_state |= go[h][j];
                }
            }
            if (state[new_state] == 0) {
                arr[x++] = new_state;
                state[new_state] = 1;
            }
        }
    }
    
    printf("\nTotal distinct states:\n");
    printf("State  0 1\n");
    for (i = 0; i < 10000; i++) {
        if (state[i] == 1) {
            int y = 0;
            if (i == 0)
                printf("q0 ");
            else {
                for (j = 0; j < st; j++) {
                    int x = 1 << j;
                    if (x & i) {
                        printf("q%d ", j);
                        y += pow(2, j);
                    }
                }
            }
            printf(" %d %d\n", go[y][0], go[y][1]);
        }
    }
    
    for (j = 0; j < 3; j++) {
        printf("\nEnter string: ");
        scanf("%s", str);
        l = strlen(str);
        curr1 = in;
        flag = 0;
        printf("\nPath:\n%d-", curr1);
        for (i = 0; i < l; i++) {
            curr1 = go[curr1][str[i] - '0'];
            printf("%d-", curr1);
        }
        printf("\nFinal state: %d\n", curr1);
        for (i = 0; i < fin; i++) {
            if (curr1 & (1 << f[i])) {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("\nString accepted\n");
        else
            printf("\nString rejected\n");
    }
    return 0;
}
