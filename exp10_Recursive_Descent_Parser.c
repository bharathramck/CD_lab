//10. CONSTRUCT A RECURSIVE DESCENT PARSER FOR AN EXPRESSION.
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

char str[15];
int p, chk = 1; // 'chk' determines whether the string is valid

void e();
void eprime();
void t();
void tprime();
void f();

void main() {
    clrscr(); 

    printf("Enter the input string: ");
    scanf("%s", str); // No need for '&' with char arrays

    printf("Input: %s", str);

    p = 0;
    chk = 1; // Reset validity check before parsing

    e();

    if (p == strlen(str) && chk) {
        printf("\nString is ACCEPTABLE");
    } else {
        printf("\nThe given input string: %s", str);
        printf("\nThe string is NOT ACCEPTABLE");
    }

    getch(); 
}

void e() {
    printf("\nE -> T E'");
    t();
    eprime();
}

void eprime() {
    if (str[p] == '+') {
        printf("\nE' -> + T E'");
        p++;
        t();
        eprime();
    } else {
        printf("\nE' -> # (epsilon)");
    }
}

void t() {
    printf("\nT -> F T'");
    f();
    tprime();
}

void tprime() {
    if (str[p] == '*') {
        printf("\nT' -> * F T'");
        p++;
        f();
        tprime();
    } else {
        printf("\nT' -> # (epsilon)");
    }
}

void f() {
    if (isalpha(str[p])) {
        printf("\nF -> id");
        p++;
    } else if (str[p] == '(') {
        printf("\nF -> ( E )");
        p++;
        e();
        if (str[p] == ')') {
            p++;
        } else {
            chk = 0; // Error: Missing closing parenthesis
        }
    } else {
        chk = 0; // Error: Invalid character
    }
}
