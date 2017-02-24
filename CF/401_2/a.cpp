#include <cstdio>

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    n %= 6;
    if (n == 5) {
        if (x == 0) x = 1;
        else if (x == 1) x = 0;
        n--;
    }
    if (n == 4) {
        if (x == 2) x = 1;
        else if (x == 1) x = 2;
        n--;
    }
    if (n == 3) {
        if (x == 0) x = 1;
        else if (x == 1) x = 0;
        n--;
    }
    if (n == 2) {
        if (x == 2) x = 1;
        else if (x == 1) x = 2;
        n--;
    }
    if (n == 1) {
        if (x == 0) x = 1;
        else if (x == 1) x = 0;
        n--;
    }
    printf("%d\n", x);
}
