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
vector<LL> bits_cnt(LL n) {
    vector<LL> result(60);
    for (int bit = 0; bit < 60; ++bit) {
        LL count = (n >> bit) / 2 * (1LL << bit);
        if ((n >> bit) % 2) {
            count += (n % (1LL << bit)) + 1;
        }
        result[bit] = (count % mod + mod) % mod;
    }
    return result;
}
// vector<LL> slow_bits_cnt(LL n) {
//     vector<LL> result(60);
//     for (int bit = 0; bit < 60; ++bit) {
//         for (int i = 0; i <= n; ++i) {
//             if (i & (1LL << bit)) {
//                 result[bit]++;
//             }
//         }
//     }
//     return result;
// }
// void print_it(vector<LL> &nums) {
//     for (auto to : nums) {
//         cout << to << ' ';
//     }
//     cout << endl;
// }
// int validator() {
//     for (int i = 1; i < 100000; ++i) {
//         auto fast = bits_cnt(i);
//         auto slow = slow_bits_cnt(i);
//         if (fast != slow) {
//             print_it(fast);
//             print_it(slow);
//             cout << i << endl;
//             return 0;
//         }
//     }
//     return 0;
// }
LL solve(LL n) {
    vector<LL> cnt = bits_cnt(n);
    LL ans = 0;
    for (int bit = 0; bit < 60; ++bit) {
        LL cnt_mod = cnt[bit] * cnt[bit] % mod;
        LL pw2_mod = (1LL << bit) % mod;
        ans = (ans + cnt_mod * pw2_mod % mod) % mod;
    }
    return ans;
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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        LL n;
        cin >> n;
        cout << solve(n) << endl;
    }
    // validator();
    auto t2 = clock();
#ifdef LOCAL
    cout << "Time = " << (double)(t2 - t1) / 1.0e6 << " sec" << endl;
#endif
}