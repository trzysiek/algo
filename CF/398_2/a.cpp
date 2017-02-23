#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> results[100005];
    pair<int, int> t[100005];

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i].first);
        t[i].second = i;
    }
    sort(t + 1, t + n + 1);
    int now = n;
    while (now > 0) {
        int oldNow = now, time = t[now].second;
        while (now > 0 && t[now].second <= time)
            now--;
        for (int i = oldNow; i >= now + 1; i--)
            results[time].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : results[i])
            printf("%d ", j);
        printf("\n");
    }
}
