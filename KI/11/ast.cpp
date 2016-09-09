#include <cstdio>
#include <vector>
using namespace std;

int n, m, a, b;
int wysS[100005], wys[100005];
vector<int> e[100005];
vector<int> Q[1000005];
bool odw[100005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &wysS[i]);
    for (int i = 1; i <= n; ++i)
        wys[i] = 34243423;
    while (m--) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    Q[wys[1]].push_back(1);
    int now = wysS[1];
    wys[1] = wysS[1];
    while (now <= 1000001) {
        while (now <= 1000001 && Q[now].empty())
            ++now;
        if (now > 1000000)
            break;
        int v = Q[now].back(); Q[now].pop_back();
        //printf("%d\n", v);
        if (v == n) {
            printf("%d\n", wys[n]);
            return 0;
        }
        for (int i = 0; i < e[v].size(); ++i) {
            int u = e[v][i];
            if (odw[u] == false || wys[u] < wys[v]) {
                odw[u] = true;
                wys[u] = max(wys[v], wysS[u]);
                Q[wys[u]].push_back(u);
            }
        }
    }
    printf("%d\n", wys[n]);
    return 0;
}
