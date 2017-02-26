#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct tmp {
    int now, week;
};

int n, k;
tmp t[200005];
long long res;

bool operator<(const tmp &a, const tmp &b) {
    return a.week - a.now > b.week - b.now;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i].now);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i].week);
    sort(t, t + n);

    for (int i = 0; i < n; ++i) {
        if (i < k)
            res += t[i].now;
        else
            res += min(t[i].week, t[i].now);
    }
    cout << res << endl;
}
