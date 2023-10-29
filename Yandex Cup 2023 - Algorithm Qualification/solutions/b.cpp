#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<typename T> using indexed_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long LL;
typedef long double LD;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int> (l, r)
const int mod = 1e9 + 7;
int get_smallest(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> cnt;
    int l = 0, mini = INT_MAX, found = 0;
    int n = a.size(), m = b.size();
    for (int num : b) {
        --cnt[num];
    }
    for (int r = 0; r < n; ++r) {
        if (cnt.count(a[r])) {
            ++cnt[a[r]];
            if (cnt[a[r]] <= 0) {
                found++;
            }
        }
        while (found == m) {
            if (r - l + 1 < mini) {
                mini = r - l + 1;
            }
            if (cnt.count(a[l])) {
                cnt[a[l]]--;
                if (cnt[a[l]] < 0) {
                    --found;
                }
            }
            ++l;
        }
    }
    return mini;
}
LL solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    while (b.size() != m) {
        b.pop_back();
    }
    cout << get_smallest(a, b) << endl;
    return 0;
}
int main() {
#ifdef LOCAL
    assert(freopen("../input.txt", "r", stdin));
    //assert(freopen("../output.txt", "w", stdout));
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(15);
    cerr.setf(ios::fixed); cerr.precision(10);
    auto t1 = clock();
    solve();
    auto t2 = clock();
#ifdef LOCAL
    cout << "Time = " << (double)(t2 - t1) / 1.0e6 << " sec" << endl;
#endif
}