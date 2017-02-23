#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

using LL = long long;

int n;
LL t_start, t_end, t_each;
LL t[100005], res = 10000000000000LL, res_which;

int main() {
    cin >> t_start >> t_end >> t_each;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    if (t[0] != 0)
        res = t_start - t[0] + 1, res_which = t[0] - 1;
    
    LL cur_time = t_start;
    for (int i = 0; i < n; ++i) {
        if (t[i] > cur_time && cur_time <= t_end - t_each) {
            cout << cur_time << endl;
            return 0;
        }
        cur_time += t_each;
        if (t[i + 1] != t[i]) { // last one of given time
            LL time = t[i + 1] - 1;
            if (cur_time - time < res && time <= t_end - t_each) 
                res = cur_time - time, res_which = time;
        }
    }
    if (cur_time <= t_end - t_each)
        res_which = t_end - t_each;
    cout << res_which << endl;
}
