#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int solve_dp(int n, int k) {
    if (n == 1) return k;

    if (k == 0) return 0;
    if (k == 1) return 1;

    if (dp[n][k] != -1) return dp[n][k];

    int ans = 1e9;

    for (int i = 1;i <= k;i++) {
        int anss = max(solve_dp(n,k-i)+1,solve_dp(n-1,i-1)+1);
        if (anss < ans) ans = anss;
    }

    return ans;




}

int main() {
    int n,k;cin>>n>>k;
    for (int i = 0;i < 1005;i++) for (int j = 0;j < 1005;j++) dp[i][j] = -1;
    cout<<solve_dp(n,k);
}