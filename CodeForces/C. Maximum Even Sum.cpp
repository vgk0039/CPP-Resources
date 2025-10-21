#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    long long ans = -1;
    long long limit = 1000000;  // check only up to 1e6

    for (long long k = 1; k * k <= b && k <= limit; k++) {
        if (b % k == 0) {
            long long d1 = k, d2 = b / k;

            long long s1 = a * d1 + b / d1;
            if (s1 % 2 == 0) ans = max(ans, s1);

            long long s2 = a * d2 + b / d2;
            if (s2 % 2 == 0) ans = max(ans, s2);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
