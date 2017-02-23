#include <cstdio>
#include <vector>
using namespace std;

int n;
int root;
vector<int> e[1000005];
int t[1000005];
int sum[1000005];
int ans[1000005];
bool visited[1000005];
int res1, res2, need;

void dfs(int v) {
    sum[v] = t[v];
    for (int i = 0; i < e[v].size(); ++i) {
        int son = e[v][i];
        if (!visited[son]) {
            visited[son] = 1;
            dfs(son);
            sum[v] += sum[son];
            if (ans[son] && ans[v])
                res1 = ans[son], res2 = ans[v];
            else if (ans[son])
                ans[v] = ans[son];
        }
    }
    if (ans[v] && sum[v] == 2 * need && v != root)
        res1 = ans[v], res2 = v;
    if (sum[v] == need)
        ans[v] = v;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int father;
        scanf("%d%d", &father, &t[i]);
        if (father == 0)
            root = i;
        else
            e[father].push_back(i), e[i].push_back(father);
        need += t[i];
    }
    if (need % 3 == 0)
        need /= 3;
    else {
        printf("-1\n");
        return 0;
    }
    visited[root] = 1; dfs(root);

    if (res1)
        printf("%d %d\n", res1, res2);
    else
        printf("-1\n");
}
