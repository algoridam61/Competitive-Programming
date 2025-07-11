#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
const int INF = 1e9;

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

unordered_map<pii, int, pair_hash> memo;

int dp(int i1, int i2, vi &a) {
    if (i1 >= 0 && i2 >= 0 && memo.count({i1, i2})) {
        return memo[{i1, i2}];
    }

    if (i1 == i2) {
        return 0 + min(dp(0, i2, a), dp(i1, 0, a));
    }

    int n = a.size();

    if (i1 >= n || i2 >= n) return 0;

    if (i1 == -1) {
        if (i2 + 1 < n) {
            return memo[{i1, i2}] = min(
                dp(i2 + 1, i2, a),
                (a[i2] < a[i2 + 1]) + dp(i1, i2 + 1, a)
            );
        }
        return 0;
    }

    if (i2 == -1) {
        if (i1 + 1 < n) {
            return memo[{i1, i2}] = min(
                (a[i1] < a[i1 + 1]) + dp(i1 + 1, i2, a),
                dp(i1, i1 + 1, a)
            );
        }
        return 0;
    }

    if (i1 > i2) {
        return memo[{i1, i2}] = min(
            (a[i1] < a[i1 + 1]) + dp(i1 + 1, i2, a),
            (a[i2] < a[i1 + 1]) + dp(i1, i1 + 1, a)
        );
    }

    if (i1 < i2) {
        return memo[{i1, i2}] = min(
            (a[i1] < a[i2 + 1]) + dp(i2 + 1, i2, a),
            (a[i2] < a[i2 + 1]) + dp(i1, i2 + 1, a)
        );
    }

    return 0;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp is order O(n^2)
    int x = INT_MAX;
    int y = INT_MAX;
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if (x>y) swap(x,y);
        // so x is smaller

        if (a[i]<=x) x = a[i];
        else if (a[i]<=y) y = a[i];
        else {
            x = a[i];
            ans++;
        }   
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;

    while (t--) solve();
    return 0;
}
