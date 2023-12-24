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
    vector<int> a(n), b(n), c(n);
    vector<pair<int, int>> A, B, C;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        A.push_back({a[i], i});
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        B.push_back({b[i], i});
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        C.push_back({c[i], i});
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    vector<int> aid, bid, cid;
    for (int i = 0; i < min(10, (int)A.size()); ++i) {
        aid.push_back(A[i].second);
    }
    for (int i = 0; i < min(10, (int)B.size()); ++i) {
        bid.push_back(B[i].second);
    }
    for (int i = 0; i < min(10, (int)C.size()); ++i) {
        cid.push_back(C[i].second);
    }
    int maxi = 0;
    for (int i : aid) {
        for (int j : bid) {
            for (int k : cid) {
                if (i != j && j != k && i != k) {
                    maxi = max(maxi, a[i] + b[j] + c[k]);
                }
            }
        }
    }
    cout << maxi << endl;
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
