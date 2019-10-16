#include <stdio.h>

long fact(int n) {
    long f;
    int i;
    for (i=0; i<n; i++) {
        f = f * i;
    }
    return f;
}

long factRec(int n) {
    if (n < 0)
        return 1;
    else
        return n * factRec(n-1);
}

int main() {

    printf("   fact(5) = %d\n", fact(5));
    printf("factRec(5) = %d\n", factRec(5));

    return 0;
}