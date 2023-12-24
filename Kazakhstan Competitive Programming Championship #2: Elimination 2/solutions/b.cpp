#include <iostream>
#include <cassert>
#include <set>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n, x;
    cin >> n >> x;
    multiset<int> a;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a.insert(x);
    }
    LL cnt = 0;
    while (x != 1 && !a.empty()) {
        if (*a.rbegin() == 0) {
            a.erase(--a.end());
            continue;
        }
        if (a.find(x) != a.end()) {
            a.erase(a.find(x));
        }
        else {
            int maxi = *a.rbegin() - x;
            a.erase(--a.end());
            if (maxi > 0) {
                a.insert(maxi);
            }
        }
        x = (x + 1) / 2;
        ++cnt;
    }
    for (int i : a) {
        cnt += i;
    }
    cout << cnt << endl;
    return 0;
}
int main() {
#ifdef LOCAL
    assert(freopen("../input.txt", "r", stdin));
    // assert(freopen("../output.txt", "w", stdout));
#endif
    solve();
    return 0;
}
