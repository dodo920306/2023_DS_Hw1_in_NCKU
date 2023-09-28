#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10000

int main(int argc, char* argv[]) {
    int top = -1, size = 0, j = 0;
    char *input = malloc(MAX_INPUT_SIZE * sizeof(char)), *postfix, *infix, *stack;

    if (input) {
        /* scanf() failed. */
        if (scanf("%s", input) != 1)    return 2;
    }
    /* malloc() failed. */
    else    return 1;

    size = strlen(input);
    /* Plus 1 for string security in C since the existence of '\0' in the end of a string.
     * However, the real length should still be stored in size.
     */
    infix = malloc((size + 1) * sizeof(char));
    /* Even whole infix has been pushed into the stack, it still won't overflow. */
    stack = malloc((size + 1) * sizeof(char));
    postfix = malloc((size + 1) * sizeof(char));
    if (!infix || !stack || !postfix) {
        /* malloc() failed. */
        return 1;
    }

    /* strncpy() will automatically set the last element '\0'. 
     * A warning about length bound with src length may occur, but that shouldn't matter.
     */
    strncpy(infix, input, size + 1);
    free(input); /* Release the input string with MAX_INPUT_SIZE */

    for (int i = 0; i < size; i++) {
        if (infix[i] >= 'A' && infix[i] <= 'Z') {
            /* infix[i] == operand => No push.
             * Only operators should be pushed in the stack.
             */
            postfix[j++] = infix[i];
        }
        else {
            if (infix[i] == '(') {
                stack[++top] = '('; /* push */
            }
            else if (infix[i] == ')') {
                while (top >= 0 && stack[top] != '(') {
                    /* All the remain operators. */
                    postfix[j++] = stack[top--];
                }
                /* The '(' can't be found in the stack */
                if (top == -1)    return 3;
                /* pop '(' */
                top--;
            }
            else {
                /* infix[i] == operator
                 * If the stack[top] is '(',
                 * it will be impossible that the precedence of infix[i] < stack[top] since a will be 0,
                 * so '(' is a nature barrier between what's inside and outside of the parentheses since the loop will naturally stop.
                 * All operators in the stack whose precedence is larger than or equal to infix[i] will be popped out since that
                 * 1. If the precedence is larger, the top of the stack should be in the postfix expression first.
                 * 2. If the precedence is equal to one of infix[i], 
                 *    due to the "compute from left to right" principle of the infix expression,
                 *    the top of the stack should be in the postfix expression first, too.
                 * Hence, the stack won't stop popping until the top of it has a precedence smaller than infix[i].
                 */
                int a = top >= 0 ? (stack[top] == '^' ? 3 :(stack[top] == '*' || stack[top] == '/' ? 2 : (stack[top] == '+' || stack[top] == '-' ? 1 : 0))) : 0;
                int b = infix[i] == '*' || infix[i] == '/' ? 2 : (infix[i] == '+' || infix[i] == '-' ? 1 : 0);
                while (!(b > a)) {
                    postfix[j++] = stack[top--];
                    a = stack[top] == '*' || stack[top] == '/' ? 2 : stack[top] == '+' || stack[top] == '-' ? 1 : 0;
                }
                stack[++top] = infix[i]; /* push */
            }
        }
    }
    free(infix);
    /* Pop all that remain in the stack */
    while (j < size)    postfix[j++] = stack[top--];
    free(stack);
    postfix[size] = '\0';
    
    printf("%s", postfix);
    free(postfix);
    return 0;
}
