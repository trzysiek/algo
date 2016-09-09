#include <cstdio>
#include <algorithm>

long long w;

int main() {
    int n;
    int t[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    std::sort(t, t + n);
    for (int i = 0; i < n; ++i)
        w += t[i];
    int a = 0;
    for (int i = (n+1)/2; i < n; ++i)
        w += t[i] - t[a++];
    printf("%lld\n", w);
}
