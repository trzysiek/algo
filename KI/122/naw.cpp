#include <cstdio>

int n;
int stos[1000001], stos_size;
int wyn[1000001][2], wyn_size;
char s[2000001];

int main() {
    scanf("%d %s", &n, s);
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '(' && stos_size <= 1000000)
            stos[stos_size++] = i + 1;
        else if (s[i] == ')') {
            if (stos_size == 0) {
                printf("NIE\n");
                return 0;
            }
            else {
                wyn[wyn_size][0] = stos[--stos_size];
                wyn[wyn_size][1] = i + 1;
                wyn_size++;
            }
        }
        else {
            printf("NIE\n");
            return 0;
        }
    }
    if (stos_size == 0) {
        printf("TAK\n");
        for (int i = 0; i < n; ++i)
            printf("%d %d\n", wyn[i][0], wyn[i][1]);
    }
    else printf("NIE\n");
}
