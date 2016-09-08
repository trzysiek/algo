#include <unordered_map>
#include <cstdio>
using namespace std;

unordered_map<int, int> M;

int main() {
    int n; // ile liczb
    int s; // jaka ma byc suma
    scanf("%d%d", &n, &s);
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (M.count(x) == 0)
            M[x] = 1;
        else
            M[x]++;
    }
    long long A = 0LL;
    long long B = 0LL;
    for (auto& it : M)
        if (M.count(s - it.first))
            A += it.second * M[s - it.first];
    if ((s % 2 == 0) && M.count(s/2))
        B = M[s/2];
    printf("%lld\n", (A-B*B)/2LL + B*(B+1)/2LL);
}
