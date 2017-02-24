#include <cstdio>
#include <vector>
using namespace std;

vector<int> t[100001];
int how_far[100001];
int n, m, x, y, q_nr;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &x), t[i].push_back(x);
    for (int col = 0; col < m; ++col) {
        int start = 0, end = 1; // [start, end)
        while (start < n) {
            while (end < n && t[end][col] >= t[end-1][col])
                ++end;
            how_far[start] = max(how_far[start], end - 1);
            start = end;
            end++;
        }
    }
    //for (int i = 0; i < n; ++i) printf("%d\n", how_far[i]);
    for (int i = 1; i < n; ++i)
        how_far[i] = max(how_far[i], how_far[i - 1]);

    scanf("%d", &q_nr);
    while (q_nr--) {
        scanf("%d%d", &x, &y);
        x--, y--;
        if (y <= how_far[x])
            printf("Yes\n");
        else
            printf("No\n");
    }

}
