#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string old, neww;
int perm[200005];
bool arr[200005];

bool ok(int n) {
    for (int i = 0; i < old.size(); ++i)
        arr[i] = 1;
    for (int i = 0; i < n; ++i)
        arr[perm[i] - 1] = 0;
    string ne;
    for (int i = 0; i < old.size(); ++i)
        if (arr[i])
            ne += old[i];

    //cout << n << ": " << ne << endl;
    auto it_n = ne.begin();
    auto it_o = neww.begin();

    while (it_n != ne.end() && it_o != neww.end()) {
        if (*it_n == *it_o)
            ++it_n, ++it_o;
        else
            ++it_n;
    }
    if (it_o == neww.end())
        return true;
    return false;
}

int main() {
    cin >> old >> neww;
    for (int i = 0; i < (int)old.size(); ++i)
        cin >> perm[i];
    int l = 0, h = (int)old.size(), mid;
    while (l < h) {
        mid = (l + h + 1) / 2;
        if (ok(mid))
            l = mid;
        else
            h = mid - 1;
    }
    cout << l << endl;
}
