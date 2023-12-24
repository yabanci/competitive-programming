#include <iostream>
#include <cassert>

using namespace std;

const int mod = 1e9 + 7;

int solve() {
    int sum1 = 0, sum2 = 0;
    int min1 = 200, min2 = 200;
    for (int i = 0, ai; i < 4; ++i) {
        cin >> ai;
        sum1 += ai;
        min1 = min(min1, ai);
    }
    for (int i = 0, ni; i < 4; ++i) {
        cin >> ni;
        sum2 += ni;
        min2 = min(min2, ni);
    }
    if (sum1 - min1 > sum2 - min2) {
        cout << "aibark" << endl;
    }
    else if (sum1 - min1 < sum2 - min2) {
        cout << "Na2a" << endl;
    }
    else {
        cout << "Tekor" << endl;
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("../input.txt", "r", stdin);
    // assert(freopen("../output.txt", "w", stdout));
#endif
    solve();
    return 0;
}
