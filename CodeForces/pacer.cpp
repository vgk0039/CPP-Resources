#include <bits/stdc++.h>
using namespace std;

long long solve(vector<pair<long long,int>> &reqs, long long m) {
    long long ans = 0;
    long long prev_t = 0;
    int prev_b = 0;  // start at time 0 on side 0

    for (auto [t, b] : reqs) {
        long long L = t - prev_t;          // number of minutes between constraints
        int need_parity = prev_b ^ b;      // 0 if same side, 1 if must switch side
        if (L % 2 == need_parity) {
            ans += L;
        } else {
            ans += L - 1;
        }
        prev_t = t;
        prev_b = b;
    }

    // last stretch until m (no side requirement at m)
    ans += (m - prev_t);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<pair<long long,int>> reqs(n);
        for (int i = 0; i < n; i++) {
            cin >> reqs[i].first >> reqs[i].second;
        }
        cout << solve(reqs, m) << "\n";
    }
    return 0;
}
