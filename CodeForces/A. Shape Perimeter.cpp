#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

        long long perimeter = 4LL * m;
        for (int i = 1; i < n; ++i) {
            perimeter += 2LL * (x[i] + y[i]);
        }

        cout << perimeter << '\n';
    }
}
