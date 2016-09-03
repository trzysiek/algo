#include <queue>
#include <iostream>
using namespace std;

int n, m;
vector<string> map;

struct pole {
    int x, y, q;
    pole(int _x, int _y, int _q) : x(_x), y(_y), q(_q) {}
};

char what(pole p) {
    return map[p.x][p.y];
}

const pole moves[] = {{1, 0, 1}, {0, 1, 1}, {-1, 0, 1}, {0, -1, 1}};

int bfs(pair<int, int> p) {
    queue<pole> Q;
    Q.push(pole(p.first, p.second, 0));
    while (!Q.empty()) {
        pole now = Q.front(); Q.pop();
        if (what(now) == 'T')
            return now.q;
        for (int i = 0; i < 4; ++i) {
            pole move = now + moves[i];
            if (ok(move))
        }
    }
}

int main() {
    pair<int, int> start;
    cin >> n >> m; // n - rows, m - columns
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        map.push_back(s);
        for (int j = 0; j < m; ++j) if (s[j] == 'W') start = {i, j};
    }
    cout << bfs(start);
}
