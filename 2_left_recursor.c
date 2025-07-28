#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() {
    char production[SIZE][50];
    char non_terminal;
    int num;

    printf("Enter Number of Productions: ");
    scanf("%d", &num);

    printf("Enter the grammar as E->E-A or similar:\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        char alpha[50], beta[50];
        int index = 3;  // Skip over non-terminal and '->'

        printf("\nGRAMMAR: %s", production[i]);
        non_terminal = production[i][0];

        if (production[i][index] == non_terminal) {
            // Left recursive
            strcpy(alpha, &production[i][index + 1]);

            // Find '|' to extract beta
            char *pipe_pos = strchr(production[i], '|');
            if (pipe_pos != NULL) {
                strcpy(beta, pipe_pos + 1);

                printf("\nThis grammar is left recursive.");
                printf("\nGrammar without left recursion:\n");

                printf("%c -> %s%c'\n", non_terminal, beta, non_terminal);
                printf("%c' -> %s%c' | ε\n", non_terminal, alpha, non_terminal);
            } else {
                printf("\nCannot eliminate left recursion (no alternative production).\n");
            }
        } else {
            printf("\nThis grammar is not left recursive.");
        }
    }

    return 0;
}
