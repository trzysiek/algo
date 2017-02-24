#include <iostream>
#include <set>
using namespace std;

int n;
string sherlock, moriarty;

int algos(bool upper) {
    int res = 0;
    multiset<int> S;
    for (int i = 0; i < n; ++i)
        S.insert((int)moriarty[i]);
    for (int i = 0; i < n; ++i) {
        multiset<int>::iterator it;
        if (upper)
            it = S.upper_bound((int)sherlock[i]);
        else
            it = S.lower_bound((int)sherlock[i]);
        if (it == S.end())
            continue;
        res++;
        S.erase(it);
    }
    return res;
}

int main() {
    cin >> n;
    cin >> sherlock >> moriarty;
    cout << n - algos(0) << endl << algos(1);
}
