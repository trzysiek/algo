#include <unordered_map>
#include <cstdio>
using namespace std;

int n;
unordered_map<int, int> DB;

int main() {
    scanf("%d", &n);
    while (n--) {
        int nr, ile;
        scanf("%d%d", &nr, &ile);
        if (ile >= 0) {
            DB[nr] += ile;
            printf("%d\n", DB[nr]);
        }
        else {
            unordered_map<int, int>::iterator it = DB.find(nr);
            if (it != DB.end()) {
                if (it->second >= (-ile)) {
                    DB[nr] += ile;
                    printf("%d\n", it->second);
                }
                else printf("NIE\n");
            }
            else printf("NIE\n");
        }
    }
}
