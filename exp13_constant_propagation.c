#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

void input();
void output();
void change(int p, char *res);
void constant();

struct expr {
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

int n;

void main() {
    clrscr();  
    input();
    constant();
    output();
    getch();   
}

void input() {
    int i;
    printf("\nEnter the maximum number of expressions: ");
    scanf("%d", &n);
    
    printf("\nEnter the expressions (format: op op1 op2 res):\n");
    for (i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;
    }
}

void constant() {
    int i, op1, op2, res;
    char op, res1[5];

    for (i = 0; i < n; i++) {
        /* If both operands are numbers, or it's an assignment (=) operation */
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0) {
            op1 = atoi(arr[i].op1);
            op = arr[i].op[0];

            /* If it's an assignment, just assign the value */
            if (strcmp(arr[i].op, "=") == 0) {
                res = op1;
            } else {
                op2 = atoi(arr[i].op2);

                switch (op) {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '*': res = op1 * op2; break;
                    case '/': res = (op2 != 0) ? (op1 / op2) : 0; break;
                }
            }

            sprintf(res1, "%d", res);
            arr[i].flag = 1; // Mark this expression for elimination
            change(i, res1);
        }
    }
}

void output() {
    int i;
    printf("\nOptimized Code:\n");
    for (i = 0; i < n; i++) {
        if (!arr[i].flag) {  // Print only non-optimized expressions
            printf("\n%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
    printf("\n");
}

/* Replace occurrences of the computed result in later expressions */
void change(int p, char *res) {
    int i;
    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}
