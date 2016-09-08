#include <iostream>

int t[1000005], i;

int main() {
    int n, A, B, M;
    std::cin >> n >> A >> B >> M;
    A %= M;

    int x = A;
    for (i = 2; i <= n; ++i) {
        if (t[x])
            break;
        t[x] = i - 1;
        x = (((long long)x)*x + B) % M;
    }
    if (i != n + 1) {
        int dl = i - t[x] + 1;
        n %= dl;
        if (n < 3)
            n += dl;
        x = A;
        for (i = 2; i <= n; ++i)
            x = (((long long) x)*x + B) % M;
    }
    std::cout << x << std::endl;
}
