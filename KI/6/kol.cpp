#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MN = 1000001;
int mi[MN], ma[MN], mass[MN], p[MN], size[MN];

int find(int nr) {
    if (p[nr] != nr) {
        p[nr] = find(p[nr]);
    }
    return p[nr];
}

void join(int a, int b) {
    int a_boss = find(a);
    int boss = find(b);
    if (size[boss] < size[a_boss])
        swap(boss, a_boss);
    if (a_boss != boss) {
        if (size[boss] == size[a_boss])
            size[boss]++;
        p[a_boss] = boss;
        mass[boss] += mass[a_boss];
        mi[boss] = min(mi[boss], mi[a_boss]);
        ma[boss] = max(ma[boss], ma[a_boss]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &mass[i], &mi[i]);
        ma[i] = mi[i];
        p[i] = i;
    }
    char str[100];
    int nr, a, b;
    while (scanf(" %s", str) != EOF) {
        if (str[0] == 'M') { // MASS
            scanf("%d", &nr);
            int c_nr = find(nr);
            printf("%d\n", mass[c_nr]);
        }
        else if (str[0] == 'J') { // JOIN
            scanf("%d%d", &a, &b);
            join(a, b);
        }
        else if (str[4] == 'A') { // IQ_MAX
            scanf("%d", &nr);
            int c_nr = find(nr);
            printf("%d\n", ma[c_nr]);
        }
        else { // IQ_MIN
            scanf("%d", &nr);
            int c_nr = find(nr);
            printf("%d\n", mi[c_nr]);
        }
    }
}
