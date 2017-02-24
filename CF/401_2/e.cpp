#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

struct pom {
    int a, b, h;
} t[100005];
int n;

long long result[100005];
int mapped[200005];
map<int, int> mapa;

bool operator<(pom a, pom b) {
    if (a.b != b.b)
        return a.b < b.b;
    return a.a < b.a;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &t[i].a, &t[i].b, &t[i].h);
        mapped[2*i] = t[i].a;
        mapped[2*i+1] = t[i].b;
    }
    sort(mapped, mapped + 2*n);

    auto begin = 0;
    auto end = 0;
    int now = 0;
    while (begin != 2*n) {
        while (end != 2*n && mapped[end] == mapped[begin])
            ++end;
        mapa[mapped[begin]] = now++;
        begin = end;
    }
    
    sort(t, t + n);

    for (int i = 0; i < n; ++i) {
        result[i] = t[i].h + tree_max(mapa[t[i].a] + 1, mapa[t[i].b]);
        tree_add(result_
    }

}
