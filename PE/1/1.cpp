#include <cstdio>

const int SUM_TO = 999;

int main() {
    int sum = 0;
    for (int i = 1; i <= SUM_TO; ++i)
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    printf("%d\n", sum);
}
