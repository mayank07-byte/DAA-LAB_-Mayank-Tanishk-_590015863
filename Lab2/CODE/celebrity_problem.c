#include <stdio.h>
#include <stdlib.h>

#define N 4 
int M[N][N] = {
    {0, 1, 0, 1},
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0}
};
int knows(int a, int b) {
    return M[a][b];
}
int findCelebrity(int n) {
    int stack[n];
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }
    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(a, b)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }
    int candidate = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != candidate && knows(candidate, i)) {
            return -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != candidate && !knows(i, candidate)) {
            return -1;
        }
    }

    return candidate;
}
int main() {
    int celeb = findCelebrity(N);
    if (celeb == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is: %d\n", celeb);

    return 0;
}