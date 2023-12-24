#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

#define all(v) (v).begin(),(v).end()

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<pair<int, int>, int> cnt;
    unordered_map<int, vector<int> > vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++cnt[make_pair(a[i], b[i])];
        vals[a[i]].push_back(b[i]);
    }
    int answer = 0;
    for (auto &i : vals) {
        sort(all(i.second));
        int now = INT_MAX;
        if (i.second[0] == i.second.back()) {
            now = i.second[0] - i.second.size();
        }
        else {
            for (int j : i.second) {
                int temp = 0;
                if (cnt[make_pair(i.first, j)] >= j) {
                    temp = i.second.size() - j;
                }
                else {
                    temp = (i.second.size() - cnt[make_pair(i.first, j)]) + (j - cnt[make_pair(i.first, j)]);
                }
                now = min(now, temp);
            }
        }
        now = min(now, (int)i.second.size());
        answer += abs(now);
    }
    cout << answer << endl;
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
