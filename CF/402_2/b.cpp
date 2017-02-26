#include <iostream>
using namespace std;

string n;
int k;

int main() {
    cin >> n >> k;
    int nr_of_0 = 0;
    for (auto i : n)
        if (i == '0')
            ++nr_of_0;
    if (nr_of_0 >= k) {
        auto it = n.end(); it--;
        int how_many = 0;
        int to_delete = 0;
        while (how_many < k) {
            if (*it == '0') ++how_many;
            else ++to_delete;
            --it;
        }
        cout << to_delete << endl;
    }
    else {
        cout << n.size() - 1 << endl;
    }
}
