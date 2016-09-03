#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[60001];
long long w;

void count_inv(const int a, const int b) { // interval [a, b)
    if (b - a <= 1)
        return;

    const int m = (a + b + 1) / 2;
    count_inv(a, m);  // [a, m)
    count_inv(m, b);  // [m, b)

    // cout << a << " "<<  m << " " << b << endl;
    int sorted[b - a];
    int N = m - a;
    int M = b - m;
    for (int i=0, j=0; i+j < b-a; ) {
        int l = t[a + i];
        int r = t[m + j];
        // `cout << "l: " << l << ", r: " << r << endl;
        if (i == N || (j != M && l > r)) {
            sorted[i + j] = r;
            j++;
            w += (N - i); // only now we update inversion count
        }
        else {
            sorted[i + j] = l;
            i++;
        }
    }
    for (int i = 0; i < b - a; ++i)
        t[i + a] = sorted[i];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    count_inv(0, n);

    // for (int i = 0; i < n; ++i) cout << t[i] << " ";
    // cout <<endl;
    cout << w << endl;
}
