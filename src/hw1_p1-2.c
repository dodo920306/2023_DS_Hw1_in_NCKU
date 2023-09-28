#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10000

int main(int argc, char* argv[])
{
    int top = -1, size = 0;
    char *input = malloc(MAX_INPUT_SIZE * sizeof(char)), *postfix, **stack;

    if (input) {
        /* scanf() failed. */
        if (scanf("%s", input) != 1)    return 2;
    }
    /* malloc() failed. */
    else    return 1;

    size = strlen(input);
    /* Plus 1 for string security in C since the existence of '\0' in the end of a string.
     * However, the real length should still be stored in size for later use.
     */
    /* Even whole postfix has been pushed into the stack, it still won't overflow. */
    stack = malloc((size + 1) * sizeof(char*));
    postfix = malloc((size + 1) * sizeof(char));
    if (!stack || !postfix) {
        /* malloc() failed. */
        return 1;
    }

    /* strncpy() will automatically set the last element '\0'. 
     * A warning about length bound with src length may occur, but that shouldn't matter.
     */
    strncpy(postfix, input, size + 1);
    /* Release the input string with MAX_INPUT_SIZE */
    free(input);

    for (int i = 0; i < size; i++) {
        if (postfix[i] >= 'A' && postfix[i] <= 'Z') {
            /* push operands */
            stack[++top] = malloc(2 * sizeof(char));
            stack[top][0] = postfix[i];
            stack[top][1] = '\0';
        }
        else {
            /* operators
             * There is no need to care about precedence.
             * All precedence things have been done in the postfix expression.
             */
            char **a = malloc(3 * sizeof(char*));
            a[0] = malloc(2 * sizeof(char));
            a[0][0] = postfix[i];
            a[0][1] = '\0';

            int local_size = 1;
            for (int t = 2; t; t--) {
                /* Plus 1 for string security in C since the existence of '\0' in the end of a string. */
                int tmp = strlen(stack[top]);
                local_size += tmp;
                a[t] = malloc((tmp + 1) * sizeof(char));
                /* pop */
                /* strncpy() will automatically set the last element '\0'. 
                 * A warning about length bound with src length may occur, but that shouldn't matter.
                 */
                strncpy(a[t], stack[top], tmp + 1);
                free(stack[top--]);
            }
            /* push whole a (it will looks like "operator operand1 operand2" with other operators inside a operand). */
            stack[++top] = malloc((local_size + 1) * sizeof(char));
            stack[top][0] = '\0';
            for (int i = 0; i < 3; i++) {
                /* strncat() will automatically set the last element '\0'. */
                strncat(stack[top], a[i], local_size);
                free(a[i]);
            }
            free(a);
        }
    }
    if (!top)    free(postfix);
    /* invalid input */
    else    return 3;
    
    printf("%s", stack[0]);
    free(stack[0]);
    free(stack);
    return 0;
}
