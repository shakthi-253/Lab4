#include <stdio.h>
#include <string.h>

int main() {
    char production[100];
    char non_terminal;

    printf("Enter production (E=E+T|T): ");
    scanf("%s", production);

    non_terminal = production[0];

    char *rhs = strchr(production,'=');
    rhs++;

    char alpha[10][20], beta[10][20];
    int a=0,b=0;

    char *token = strtok(rhs,"|");

    while(token!=NULL) {
        if(token[0]==non_terminal)
            strcpy(alpha[a++], token+1);
        else
            strcpy(beta[b++], token);

        token = strtok(NULL,"|");
    }

    printf("\nAfter removing Left Recursion:\n");

    printf("%c -> ",non_terminal);
    for(int i=0;i<b;i++)
        printf("%s%c' ",beta[i],non_terminal);
    printf("\n");

    printf("%c' -> ",non_terminal);
    for(int i=0;i<a;i++)
        printf("%s%c' | ",alpha[i],non_terminal);
    printf("ε\n");
}
