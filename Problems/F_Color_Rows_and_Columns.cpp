#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define INF 1000000000
#define f(i, n) for (int i = 0; i < n; i++)

ll memo[1001][101];

void solve()
{
    ll n, k;
    cin >> n >> k;
    vl a(n), b(n);
    f(i, n) cin >> a[i] >> b[i];

    // Initialize the DP table with INF
    f(i, 1001) f(j, 101) memo[i][j] = INF;
    memo[0][0] = 0;

    // Bottom-up DP
    for (int i = 1; i <= n; ++i) {
        int curra = a[i - 1], currb = b[i - 1];

        for (int j = 0; j <= k; ++j) {
            for (int point = 0; point <= min(j, curra + currb); ++point) {
                ll cost = 0;
                ll x = curra, y = currb;
                ll curr_points = 0;

                while (curr_points < point) {
                    if (x >= y) {
                        cost += y;
                        x--;
                    } else {
                        cost += x;
                        y--;
                    }
                    curr_points++;
                }

                if (j - point >= 0) {
                    memo[i][j] = min(memo[i][j], memo[i - 1][j - point] + cost);
                }
            }
        }
    }

    // Answer is the value in memo[n][k]
    if (memo[n][k] == INF) cout << -1;
    else cout << memo[n][k];

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
