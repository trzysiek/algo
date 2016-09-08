#include <iostream>
#include <set>
using namespace std;

int n;
int a, b, suma, ile;
multiset<int> S;
multiset<int> S2;

int gcd(long long a, long long b) {
    while (a>0 && b>0) {
        if (a>b)
            a %= b;
        else
            b %= a;
    }
    return a+b;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            S.insert(b);
            S2.insert(-b);
            suma += b;
            ile++;
        }
        else if (a == 2) {
            if (S.size() > 0) {
                auto it = S.begin();
                cout << *it << endl;
                suma -= *it;
                int pom = *it;
                S.erase(it);
                it = S2.find(-pom);
                S2.erase(it);
                ile--;
            }
        }
        else if (a == 3) {
                auto it = S2.begin();
                int pom = -*it;
                cout << pom << endl;
                suma -= pom;
                ile--;
                S.erase(S.find(pom));
                S2.erase(it);
        }
        else if (a == 0) {
            if (suma == 0) cout << "0/0" << endl;
            else {
                int g = gcd(suma, ile);
                cout << suma/g << "/" << ile/g << endl;
            }
        }
        else {
            cout << "error" << endl;
        }
    }
}
