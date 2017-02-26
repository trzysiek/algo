#include <cstdio>
#include <algorithm>
using namespace std;

int n, x;
int A[10], B[10];
int res;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x), ++A[x];
    for (int i = 0; i < n; ++i)
        scanf("%d", &x), ++B[x];
    for (int i = 1; i <= 5; ++i) {
        if ((A[i] - B[i]) % 2) {
            printf("-1\n");
            return 0;
        }
        res += abs(A[i] - B[i]);
    }
    printf("%d\n", res / 4);
}
