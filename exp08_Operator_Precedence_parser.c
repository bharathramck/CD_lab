//DEVELOP AN OPERATOR PRECEDENCE PARSER FOR A GIVEN LANGUAGE.  
#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    char stack[20], ip[20], opt[10][10][1], ter[10];
    int i, j, k, n, top = 0, row = -1, col = -1;

    clrscr();

    // Initialize stack and input arrays
    for (i = 0; i < 20; i++) {
        stack[i] = NULL;
        ip[i] = NULL;
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("\nEnter the terminals: ");
    scanf("%s", ter);

    printf("\nEnter the operator precedence table values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for (%c, %c): ", ter[i], ter[j]);
            scanf("%s", opt[i][j]); // Directly storing '<', '>', '='
        }
    }

    // Display the operator precedence table
    printf("\nOPERATOR PRECEDENCE TABLE:\n");
    printf("\t");
    for (i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
    }
    printf("\n--------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%c |", ter[i]);
        for (j = 0; j < n; j++) {
            printf("\t%s", opt[i][j]);
        }
        printf("\n");
    }

    stack[top] = '$'; // Initialize stack with $
    
    printf("\nEnter the input string (append with $ at the end): ");
    scanf("%s", ip);

    i = 0;
    printf("\nSTACK\t\tINPUT STRING\t\tACTION\n");
    printf("\n%s\t\t%s\t\t", stack, ip);

    while (i <= strlen(ip)) {
        row = col = -1;

        // Finding row and column indexes for terminals in precedence table
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k]) 
                row = k;
            if (ip[i] == ter[k]) 
                col = k;
        }

        if (row == -1 || col == -1) {
            printf("\nError: Invalid symbol in input.\n");
            break;
        }

        if ((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is ACCEPTED\n");
            break;
        } else if ((opt[row][col][0] == '<') || (opt[row][col][0] == '=')) {
            printf("Shift %c", ip[i]);
            stack[++top] = opt[row][col][0];
            stack[++top] = ip[i];
            ip[i] = ' ';
            i++;
        } else if (opt[row][col][0] == '>') {
            while (stack[top] != '<') {
                --top;
            }
            top = top - 1;
            printf("Reduce");
        } else {
            printf("\nString is NOT accepted\n");
            break;
        }

        printf("\n%s\t\t%s\t\t", stack, ip);
    }

    getch(); 
}
