#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int t[50000];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    sort(t, t + n);
    for (int i = 0; i < n; ++i)
        cout << t[i] << " ";
}
