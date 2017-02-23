#include <set>
#include <iostream>
using namespace std;

int n, m;
int spent[100005];
int wage[100005];
int res[100005][2];
long long whole_result;

set<pair<int, int>> S;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> spent[i];
    for (int i = 0; i < n; ++i)
        cin >> wage[i];
    
    for (int i = 0; i < n; ++i) {
        res[i][0] = spent[i] / 100;
        res[i][1] = spent[i] % 100;
        m        -= spent[i] % 100;
        if (spent[i] % 100 == 0)
            continue;
        S.insert(make_pair((100-spent[i]%100)*wage[i], i));

        if (m < 0) {
            auto it = S.begin();
            whole_result += it->first;
            res[it->second][0]++, res[it->second][1] = 0;
            S.erase(it);
            m += 100;
        }
    }
    cout << whole_result << endl;
    for (int i = 0; i < n; ++i)
        cout << res[i][0] << " " << res[i][1] << endl;
}
