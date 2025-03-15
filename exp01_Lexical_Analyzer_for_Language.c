/*1.DESIGN AND IMPLEMENT A LEXICAL ANALYSER FOR GIVEN LANGUAGE USING C
AND THE LEXICAL ANALYSER SHOULD IGNORE REDUNDANT SPACES, TABS AND
NEW LINES.*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

void main() {
    FILE *f1; 
    char c, str[20];  // Buffer for identifiers/keywords
    int lineno = 1, num = 0, i = 0;
    
    clrscr(); 
    
    printf("\nEnter the C program (Press Ctrl+Z to end input in Turbo C++):\n");
    
    // Open file for writing the input program
    f1 = fopen("input.txt", "w"); 
    while ((c = getchar()) != EOF) {
        putc(c, f1);
    }
    fclose(f1); // Close after writing
    
    // Open file for reading the input program
    f1 = fopen("input.txt", "r"); 

    printf("\nLexical Analysis Output:\n");

    // Read file character by character
    while ((c = getc(f1)) != EOF) { 
        if (isdigit(c)) { 
            // Recognize numbers
            num = c - '0'; 
            c = getc(f1);
            while (isdigit(c)) { 
                num = num * 10 + (c - '0'); 
                c = getc(f1);
            }
            printf("%d is a number\n", num); 
            ungetc(c, f1);  // Put back last read character
        } 
        else if (isalpha(c)) { 
            // Recognize keywords and identifiers
            i = 0;
            str[i++] = c;
            c = getc(f1);
            while (isalnum(c) || c == '_' || c == '$') { 
                str[i++] = c;
                c = getc(f1);
            }
            str[i] = '\0'; // Null terminate the string
            
            // Check if the string is a keyword
            if (strcmp(str, "for") == 0 || strcmp(str, "while") == 0 || 
                strcmp(str, "do") == 0 || strcmp(str, "int") == 0 || 
                strcmp(str, "float") == 0 || strcmp(str, "char") == 0 || 
                strcmp(str, "double") == 0 || strcmp(str, "static") == 0 || 
                strcmp(str, "switch") == 0 || strcmp(str, "case") == 0) {
                printf("%s is a keyword\n", str);
            } else {
                printf("%s is an identifier\n", str);
            }

            ungetc(c, f1); // Put back last read character
        } 
        else if (c == ' ' || c == '\t') { 
            // Ignore spaces and tabs
        } 
        else if (c == '\n') { 
            // Count line number
            lineno++; 
        } 
        else { 
            // Recognize special symbols
            printf("%c is a special symbol\n", c);
        }
    }

    printf("Total number of lines: %d\n", lineno);

    fclose(f1); // Close file
    getch(); 
}
