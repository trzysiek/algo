#include <cstdio>
#include <stack>
using namespace std;

int n, x;
stack<pair<int, int>> S;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        while (!S.empty() && x >= S.top().first)
            S.pop();
        printf("%d\n", (S.empty()) ? -1 : S.top().second);
        S.push({x, i});
    }
}
