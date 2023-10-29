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
LL solve() {
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