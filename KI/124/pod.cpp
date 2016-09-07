#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    long long biere = x, nie_biere = 0LL;

    for (int i = 0; i < n-1; ++i) {
        scanf("%d", &x);
        long long stare_nie_biere = nie_biere;
        nie_biere = max(nie_biere, biere);
        biere = max(biere, stare_nie_biere + x);
    }
    cout << max(biere, 0LL) << endl;
}
