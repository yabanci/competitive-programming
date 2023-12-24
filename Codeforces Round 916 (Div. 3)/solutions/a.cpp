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
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
        ++cnt[c - 'A'];
    }
    int kolvo = 0;
    for (int i = 0; i < 26; ++i) {
        kolvo += (cnt[i] > i);
    }
    cout << kolvo << endl;
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
