#include <iostream>
using namespace std;

int tree[1<<21];
int POW = 1 << 20;

void initialize_tree() {
}

void update(int id, int t_a, int t_b, int a, int b, int ile) {
    if (t_a >= a && t_b <= b) {
        tree[id] = ile;
        return;
    }

    int mid = (t_a + t_b) / 2;
    if (a <= mid)
        update(id*2,   t_a,   mid, a, b, ile);
    if (b > mid)
        update(id*2+1, mid+1, t_b, a, b, ile);

    tree[id] = max(tree[id*2], tree[id*2+1]);
}

int get_max(int id, int t_a, int t_b, int a, int b) {
    if (t_a >= a && t_b <= b)
        return tree[id];
    
    int mid = (t_a + t_b) / 2;
    int ma = 0;
    if (a <= mid)
        ma = get_max(id*2, t_a, mid, a, b);
    if (b > mid)
        ma = max(ma, get_max(id*2+1, mid+1, t_b, a, b));

    return ma;
}

int main() {
    int d, n;
    cin >> d >> n;
    initialize_tree();
    while (n--) {
        int length, beginning;
        cin >> length >> beginning;
        length--;

        int ma = get_max(1, 0, POW - 1, beginning, beginning + length);
        update(1, 0, POW - 1, beginning, beginning + length, ma + 1);

        //cout << beginning << " " << beginning + length << " " << ma << endl;
    }
    cout << get_max(1, 0, POW - 1, 0, POW - 1) << endl;
}
