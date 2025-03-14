#include <stdio.h>
#include<conio.h> 
#include <ctype.h>
#include <string.h>

FILE *fp, *fp1;

void check(char s[10]); // Function declaration

int main() {
    char s[10];

    clrscr(); 

    fp = fopen("i.dat", "r");
    fp1 = fopen("o.dat", "w");

    if (fp == NULL || fp1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fscanf(fp, "%s", s) != EOF) {
        check(s);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}

void check(char s[10]) {
    if (strcmp(s, "read") == 0 || strcmp(s, "write") == 0 ||
        strcmp(s, "while") == 0 || strcmp(s, "for") == 0 ||
        strcmp(s, "if") == 0 || strcmp(s, "else") == 0 ||
        strcmp(s, "endif") == 0 || strcmp(s, "then") == 0) {
        fprintf(fp1, "%s -> keyword\n", s);
    } else if (!isalpha(s[0])) {
        if (strcmp(s, ",") == 0)
            fprintf(fp1, ", -> comma\n");
        else if (strcmp(s, "(") == 0)
            fprintf(fp1, "( -> openbrace\n");
        else if (strcmp(s, ")") == 0)
            fprintf(fp1, ") -> closebrace\n");
        else if (strcmp(s, ";") == 0)
            fprintf(fp1, "; -> semicolon\n");
        else if (strcmp(s, ">") == 0)
            fprintf(fp1, "> -> greater than\n");
        else if (strcmp(s, "<") == 0)
            fprintf(fp1, "< -> less than\n");
    } else {
        fprintf(fp1, "%s -> identifier\n", s);
    }
}
