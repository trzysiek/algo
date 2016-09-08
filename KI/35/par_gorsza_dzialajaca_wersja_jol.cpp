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
    long long w = 0LL;
    for (auto &it : M) {
        if (it.first * 2 == s)
            w += ((long long)(it.second))*(it.second+1)/2;
        else if (it.first * 2 < s)
            w += ((long long)it.second)*M[s-it.first];
    }
    printf("%lld\n", w);
}
