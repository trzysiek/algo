#include <queue>
#include <iostream>
using namespace std;

const int INF = 1000001;

int n, m;
vector<string> map;
vector<vector<int>> odl;

struct pole {
    int x, y, q;
    pole(int _x, int _y, int _q) : x(_x), y(_y), q(_q) {}
};

char what(pair<int, int> p) {
    return map[p.first][p.second];
}

const pair<int, int> moves[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool ok(pair<int, int> p) {
    if (p.first < 0 || p.second < 0
     || p.first >= n || p.second >= m
     || map[p.first][p.second] == 'R')
        return false;
    return true;
}

int ile(pair<int, int> p) {
    return odl[p.first][p.second];
}

int bfs(pair<int, int> p) {
    queue<pair<int, int>> Q;
    Q.push({p.first, p.second});
    odl[p.first][p.second] = 0;
    while (!Q.empty()) {
        auto now = Q.front(); Q.pop();
        if (what(now) == 'T')
            return ile(now);
        for (int i = 0; i < 4; ++i) {
            auto move = now;
            move.first += moves[i].first;
            move.second += moves[i].second;
            if (ok(move) && ile(move) == INF) {
                odl[move.first][move.second] = ile(now) + 1;
                Q.push(move);
            }
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
        vector<int> dupa;
        for (int j = 0; j < m; ++j) dupa.push_back(INF);
        odl.push_back(dupa);
    }
    cout << bfs(start);
}
