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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        p.push_back({a[i] + b[i], i});
    }
    sort(p.rbegin(), p.rend());
    LL answer = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            answer += a[p[i].second] - 1;
        }
        else {
            answer -= b[p[i].second] - 1;
        }
    }
    cout << answer << endl;
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
