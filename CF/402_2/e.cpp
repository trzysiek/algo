#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int n, m;
bool is_number[5001];
string name[5001];
string number[5001];
string op[5001];
string op_a[5001], op_b[5001];
int Op_a[5001], Op_b[5001];
int bit_res[5001];

int licz(int bit_nr, int bit_value) {
    int overall_res = 0;
    bit_res[n] = bit_value;
    for (int i = 0; i < n; ++i) {
        if (is_number[i]) {
            bit_res[i] = number[i][bit_nr] - '0';
        }
        else {
            int a = bit_res[Op_a[i]], b = bit_res[Op_b[i]], res;
            if (op[i] == "AND")
                res = a & b;
            else if (op[i] == "XOR")
                res = a ^ b;
            else
                res = a | b;
            overall_res += res;
            bit_res[i] = res;
        }
    }
    return overall_res;
}

int main() {
    cin >> n >> m;
    map<string, int> M;
    M["?"] = n;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> name[i];
        cin >> x >> x;
        if (x[0] == '0' || x[0] == '1')
            is_number[i] = 1, number[i] = x;
        else {
            op_a[i] = x;
            cin >> op[i] >> op_b[i];
            Op_a[i] = M[op_a[i]];
            Op_b[i] = M[op_b[i]];
        }
        M[name[i]] = i;
    }
    string res_lowest, res_highest;
    for (int i = 0; i < m; ++i) {
        int a = licz(i, 0), b = licz(i, 1);
        //cout << a << " " << b << endl;
        if (a > b)
            res_highest += '0', res_lowest += '1';
        else if (a < b)
            res_highest += '1', res_lowest += '0';
        else
            res_highest += '0', res_lowest += '0';
    }
    cout << res_lowest << endl << res_highest << endl;
}
