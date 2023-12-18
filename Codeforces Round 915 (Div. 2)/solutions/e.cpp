#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 998244353;

LL add(LL a, LL b) {
    a += b;
    if (a < 0) {
        a += mod;
    }
    if (a >= mod) {
        a -= mod;
    }
    return a;
}
LL mul(LL a, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) {
            res = add(res, a);
        }
        a = add(a, a);
        n >>= 1;
    }
    return res;
}
LL bpw(LL a, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
int solve() {
    LL n;
    cin >> n;
    LL temp = bpw(2LL, n);
    temp = add(temp, (n + 1) * -1);
    cout << mul(temp, n) << endl;
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