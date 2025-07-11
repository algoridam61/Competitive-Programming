#include <bits/stdc++.h>

using namespace std;

int dp[1005][2];
vector<int> a(1005);
int n;
int solve_dp(int i, int state) {
    if (i == -1) {
        // int ans = 0;
        int ans1 = solve_dp(1, 1); // have not taken 0 so can take 1
        int ans2 = a[0] + solve_dp(1,0); // have taken 0 so cannot take 1
        return max(ans1,ans2);
    }

    if (i == n-1) {
        if (state == 0) return 0;
        else return a[n-1];
    }

    if (dp[i][state] != -1) return dp[i][state];

    if (state == 0) {
        return dp[i][state] = solve_dp(i+1, 1);
    } else {
        return dp[i][state] = max(solve_dp(i+1,0)+a[i],solve_dp(i+1,1));
    }
}
int main () {
    cin>>n;

    for (int i = 0;i < n;i++) {
        cin>>a[i];
    }

    for (int i = 0;i < 1005;i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    cout<<solve_dp(-1,-1);

}

