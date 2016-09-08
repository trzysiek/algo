#include <iostream>
#include <string>
using namespace std;

string fib[1001];

string dodaj(string a, string b) {
    string w = "";
    int diff = a.size() - b.size();
    int przes = 0;
    for (int i = (int)b.size() - 1; i >= 0; i--) {
        int ile = a[diff + i] + b[i] - '0' * 2 + przes;
        if (ile <= 9)
            w += char('0' + ile), przes = 0;
        else
            w += char('0' + ile - 10), przes = 1;
    }
    for (int i = diff - 1; i >= 0; i--) {
        int ile = a[i] - '0' + przes;
        if (ile <= 9)
            w += char('0' + ile), przes = 0;
        else
            w += char('0' + ile - 10), przes = 1;
    }
    if (przes == 1)
        w += '1';
    return string(w.rbegin(), w.rend());
}

int main() {
    fib[1] = "1";
    fib[2] = "1";
    int n;
    cin >> n;
    for (int i = 3; i <= n; ++i)
        fib[i] = dodaj(fib[i-1], fib[i-2]);
    cout << fib[n] << endl;
}
