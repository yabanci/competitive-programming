#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n, k;
    cin >> n >> k;
    for (int i = n - k; i <= n; ++i) {
        cout << i << ' ';
    }
    for (int i = n - k - 1; i >= 1; --i) {
        cout << i << ' ';
    }
    cout << endl;
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
