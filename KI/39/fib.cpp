#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> stringz;
    for (int i = 0; i < (1 << n); ++i)
        stringz.push_back(bitset<15>(i).to_string());
    sort(stringz.begin(), stringz.end());
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 15 - n; j < 15; ++j)
            cout << stringz[i][j];
        cout << endl;
    }
}
