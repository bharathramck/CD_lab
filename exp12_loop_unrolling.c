//12. WRITE A PROGRAM TO PERFORM LOOP UNROLLING. 
#include <stdio.h>
#include <conio.h>

int countbit1(unsigned int);
int countbit2(unsigned int);

void main() {
    unsigned int n;
    int x, ch;

    clrscr();
    printf("\nEnter n: ");
    scanf("%u", &n);

    printf("\n1. Loop Roll\n2. Loop Unroll");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            x = countbit1(n);
            printf("\nLoop Roll: Count of 1's: %d", x);
            break;
        case 2:
            x = countbit2(n);
            printf("\nLoop Unroll: Count of 1's: %d", x);
            break;
        default:
            printf("\nWrong Choice!");
    }
    
    getch();
}

int countbit1(unsigned int n) {
    int bits = 0, i = 0;
    while (n != 0) {
        if (n & 1) bits++;
        n >>= 1;
        i++;
    }
    printf("\nNumber of iterations: %d", i);
    return bits;
}

int countbit2(unsigned int n) {
    int bits = 0, i = 0;
    while (n != 0) {
        if (n & 1) bits++;
        if (n & 2) bits++;
        if (n & 4) bits++;
        if (n & 8) bits++;
        n >>= 4;
        i++;
    }
    printf("\nNumber of iterations: %d", i);
    return bits;
}
