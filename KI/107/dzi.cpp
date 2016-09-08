#include <cstdio>

int gcd(int a, int b) {
    while (a>0 && b>0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if ((a>0 && b>0)) {
            int g = gcd(a, b);
            a /= g, b /= g;
            int g2 = gcd(b, g);
            b /= g2;
        }
        printf("%d %d\n", a, b);
    }
}
