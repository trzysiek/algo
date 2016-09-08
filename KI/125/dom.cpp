#include <vector>
#include <iostream>
using namespace std;

int n, m, l, w, a, b;
int bylo[10001];
vector<int> e[10001];

void dfs(int x) {
    bylo[x] = true;
    for (auto y : e[x])
        if (!bylo[y])
            dfs(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> l;
    for (int i = 0; i < m; ++i)
        cin >> a >> b, e[a].push_back(b);
    while (l--)
        cin >> a, dfs(a);
    for (int i = 1; i <= n; ++i)
        if (bylo[i])
            ++w;
    cout << w << endl;
}
