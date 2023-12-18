#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

LL t[maxn * 4];
void build(int v, int tl, int tr, const vector<int> &a) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, a);
    build(v << 1 | 1, tm + 1, tr, a);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
int add[maxn * 4];
void push(int v, int tl, int tr) {
    if (add[v] == -1) {
        return;
    }
    if (tl != tr) {
        add[v << 1] = add[v];
        add[v << 1 | 1] = add[v];
    }
    t[v] = (tr - tl + 1) * add[v];
    add[v] = -1;
}
void upd(int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);
    if (l <= tl && tr <= r) {
        add[v] = val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm, l, r, val);
    upd(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
int get(int v, int tl, int tr, int id) {
    if (tl == tr) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    if (id <= tm) {
        return get(v << 1, tl, tm, id);
    }
    return get(v << 1 | 1, tm + 1, tr, id);
}
int solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    set<int> s;
    for (int i = 0; i <= n; ++i) {
        s.insert(i);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        auto it = s.find(p[i]);
        if (it != s.end()) {
            s.erase(it);
        }
        a[i] = *s.begin();
    }
    build(1, 0, n-1, a);
    memset(add, -1, sizeof add);
    vector<int> id(n + 1);
    for (int i = 0; i < n; ++i) {
        id[p[i]] = i;
    }
    LL maxi = t[1];
    for (int i = 0; i < n; ++i) {
        if (id[p[i] - 1]) {}
        int saved = get(1, 0, n - 1, );
        upd(1, 0, n - 1, i, i, n);
        id[p[i]] += n;
        maxi = max(maxi, t[1]);
    }
    cout << maxi << endl;
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