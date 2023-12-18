#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ++cnt[u - 1];
        ++cnt[v - 1];
    }
    int leaf = 0;
    for (int i : cnt) {
        leaf += (i == 1);
    }
    cout << (leaf + 1) / 2 << endl;
    return 0;
}
int main() {
#ifdef LOCAL
    assert(freopen("../input.txt", "r", stdin));
    // assert(freopen("../output.txt", "w", stdout));
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}