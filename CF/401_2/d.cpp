#include <iostream>
#include <string>
using namespace std;

int n;
string ss[500005];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ss[i];
    for (int i = n - 2; i >= 0; i--) {
        decltype (ss[i].size()) now = 0;
        while (now < ss[i].size() && now < ss[i + 1].size()
                    && ss[i][now] == ss[i + 1][now])
            ++now;
        if (now >= ss[i].size())
            continue;
        if (now >= ss[i+1].size())
            ss[i] = ss[i].substr(0, ss[i+1].size());
        else if (ss[i][now] < ss[i+1][now])
            continue;
        else
            ss[i] = ss[i].substr(0, now);
    }
    for (int i = 0; i < n; ++i)
        cout << ss[i] << endl;

}
