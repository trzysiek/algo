#include <iostream>
using namespace std;

typedef long long LL;
const LL M = 123456789;

struct Macierz {
    LL t[2][2];

    void print() {
        cout << t[0][0] << "   " << t[0][1] << endl;
        cout << t[1][0] << "   " << t[1][1] << endl;
    }

    Macierz() {
        t[0][1] = t[1][0] = t[1][1] = 1;
        t[0][0] = 0;
    }

    Macierz& operator*(const Macierz& m) {
        Macierz w = Macierz();
        w.t[0][0] = t[0][0] * m.t[0][0] + t[0][1] * m.t[1][0];
        w.t[0][1] = t[0][0] * m.t[1][0] + t[0][1] * m.t[1][1];
        w.t[1][0] = t[1][0] * m.t[0][0] + t[1][1] * m.t[1][0];
        w.t[1][1] = t[1][0] * m.t[1][0] + t[1][1] * m.t[1][1];
        t[0][0] = w.t[0][0] % M;
        t[0][1] = w.t[0][1] % M;
        t[1][0] = w.t[1][0] % M;
        t[1][1] = w.t[1][1] % M;
        return *this;
    }
};

Macierz pot(int b) {
    Macierz wyn = Macierz();
    Macierz pot = Macierz();
    while (b) {
        if (b % 2 == 1)
            wyn = wyn * pot;
        pot = pot * pot;
        b /= 2;
    }
    return wyn;
}

int main() {
    int n;
    cin >> n;
    Macierz m = pot(n-2);
    cout << m.t[1][1] << endl;
}

