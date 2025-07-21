%{
#include <stdio.h>
int is_simple = 1;
%}

%%
[ \t\n]+[aA][nN][dD][ \t\n]+    { is_simple = 0; }
[ \t\n]+[oO][rR][ \t\n]+        { is_simple = 0; }
[ \t\n]+[bB][uU][tT][ \t\n]+    { is_simple = 0; }
.                               { /* ignore other chars */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the sentence (press Ctrl+D to finish):\n");
    yylex();

    if (is_simple == 1) {
        printf("The given sentence is simple\n");
    } else {
        printf("The given sentence is compound\n");
    }

    return 0;
}
