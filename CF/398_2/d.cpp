#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, k;
int possessed[1000005];
pair<int, int> shop[1000005];
int all[2000005];

bool ok(int ile) {
    //printf("n: %d, ile: %d\n", n, ile);
    int i = 0, j = m - ile, now = 0;
    while (i < n || j < m) {
        if (possessed[i] <= shop[j].first)
            all[now++] = possessed[i++];
        else
            all[now++] = shop[j++].first;
    }
    /*for (int i = 0; i < now; ++i)
        printf("%d ", all[i]);
    printf("\n");
    */
    int step = 0, ptr = 0;
    while (ptr < n + ile) {
        int how_many_this_step = 0;
        while (ptr < n + ile && how_many_this_step < k) {
            if (all[ptr] < step)
                return false;
            ptr++;
            how_many_this_step++;
        }
        step++;
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &possessed[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &shop[i].first), shop[i].second = i;
    sort(shop, shop + m);
    sort(possessed, possessed + n);
    possessed[n]  = 1000000000;
    shop[m].first = 1000000000;
    
    int l = 0, h = m, mid;
    while (l < h) {
        mid = (l + h + 1) / 2;
        if (ok(mid))
            l = mid;
        else
            h = mid - 1;
    }
    if ((l > 0) || (l == 0 && ok(0))) {
        printf("%d\n", l);
        for (int i = m - 1; i >= m - l; i--)
            printf("%d ", shop[i].second + 1);
    }
    else
        printf("-1\n");
}
