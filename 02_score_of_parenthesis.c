int scoreOfParentheses(char* s) {
    int len = strlen(s);
    int *stack = (int *)malloc(len * sizeof(int));
    int top = -1;
    stack[++top] = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = 0;
        } else {
            int val = stack[top--];
            if (val == 0) {
                stack[top] += 1;
            } else {
                stack[top] += 2 * val;
            }
        }
    }

    return stack[top];
}