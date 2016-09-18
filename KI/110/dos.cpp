#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int suma, ile;
map<int, int> normalny;
map<int, int> min10, max10;

int get_max_w_min10() {
}

int get_min_w_max10() {
}

void update_db_modulo_10() {
}

void standardzik(int co) {
    suma += co;
    ile++;
    normalny[co]++;
}

void szacher_macher_min10(int co) {
    int topik = get_max_w_min10();
    min10[topik]--;
    min10[co]++;
    normalny[topik]++;
}

void szacher_macher_max10(int co) {
    int botom = get_min_w_max10();
    max10[botom]--;
    max10[co]++;
    normalny[botom]++;
}

void add(int co) {
    suma += co;
    ile++;

    if (co < get_max_w_min10())
        szacher_macher_min10(co);
    else if (co > get_min_w_max10())
        szacher_macher_max10(co);
    else
        standardzik(co);

    if (ile % 10 == 0)
        update_db_modulo_10();
}

int gcd(int a, int b) {
    while (a>0 && b>0) {
        if (a > b) a %= b;
        else       b %= a;
    }
    return a + b;
}

int main() {
    int n;
    int a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a == 0) {
            if (ile == 0)
                printf("0/0\n");
            else {
                int g = gcd(suma, ile);
                printf("%d/%d\n", suma/g, ile/g);
            }
        }
        else {
            scanf("%d", &b);
            add(b);
        }
    }
}
