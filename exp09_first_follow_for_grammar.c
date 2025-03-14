//9.WRITE A PROGRAM TO FIND SIMULATE FIRST AND FOLLOW OF ANY GIVEN GRAMMAR
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n, m = 0, p, i = 0, j = 0;
char a[10][10], f[10];

void follow(char c);
void first(char c);

void main() {
    int z;
    char c, ch;

    clrscr(); 

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");

    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    do {
        m = 0;
        memset(f, 0, sizeof(f)); // Reset f array before each computation

        printf("\nEnter the element whose First & Follow is to be found: ");
        scanf(" %c", &c); // Added space before %c to handle newline issues

        first(c);
        printf("First(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", f[i]);
        }
        printf("}\n");

        m = 0;
        memset(f, 0, sizeof(f)); // Reset f array before computing Follow

        follow(c);
        printf("Follow(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", f[i]);
        }
        printf("}\n");

        printf("\nContinue? (1 - Yes / 0 - No): ");
        scanf("%d", &z);
    } while (z == 1);

    getch(); 
}

void first(char c) {
    int k;
    
    if (!isupper(c)) { 
        f[m++] = c; // If c is a terminal, add it to First
        return;
    }

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) { // If production starts with c
            if (a[k][2] == '$') { // If epsilon production
                follow(a[k][0]);
            } else if (islower(a[k][2])) { // If terminal
                f[m++] = a[k][2];
            } else { // If non-terminal, recursively find First
                first(a[k][2]);
            }
        }
    }
}

void follow(char c) {
    if (a[0][0] == c) {
        f[m++] = '$'; // If start symbol, add $
    }

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0') {
                    first(a[i][j + 1]);
                }
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]);
                }
            }
        }
    }
}
