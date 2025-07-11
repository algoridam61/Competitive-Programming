#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define vl vector<ll>
#define vvl vector<vl>
#define vi vector<int>
#define vvi vector<vi>
#define L cout<<"\n"
#define pl pair<ll,ll>
#define INF (unsigned)!((int)0)
#define sortall(a) sort(a.begin(),a.end())
#define rsortall(a) sort(a.begin(), a.end(), [](const auto &x, const auto &y) { return x > y; });
#define max1(a) *max_element(a.begin(), a.end())
#define min1(a) *min_element(a.begin(), a.end())
#define no {cout<<"NO";L;return;}
#define yes {cout<<"YES";L;return;}
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define vvpi vector<vector<pair<int,int>>>
#define vpl vector<pair<ll,ll>>
#define vvpl vector<vector<pair<ll,ll>>>
#define read(a) f(i,size(a)) cin>>a[i];
#define out(a) f(i,size(a)) if (i!=size(a)-1) cout<<a[i]<<" "; else cout<<a[i];L;

const ll MOD = 1000000007;
 
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2>
using ordered_set_pair = tree<std::pair<T1, T2>, null_type, std::less<std::pair<T1, T2>>, rb_tree_tag, tree_order_statistics_node_update>;

/*
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
*/
vi bfs_dp() {
    vi dp(1001, 1001);
    dp[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 1; i <= x / 2; ++i) {
            int nx = x + x / i;
            if (nx <= 1000 && dp[nx] > dp[x] + 1) {
                dp[nx] = dp[x] + 1;
                q.push(nx);
            }
        }
        if (x + 1 <= 1000 && dp[x + 1] > dp[x] + 1) {
            dp[x + 1] = dp[x] + 1;
            q.push(x + 1);
        }
    }
    return dp;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    vi cost = bfs_dp();
    vi moves(n);
    f(i, n) moves[i] = cost[b[i]];

    k = min(k, 1000 * n); // limit knapsack capacity

    vi dp_knapsack(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        int w = moves[i];
        int v = c[i];
        for (int j = k; j >= w; --j) {
            dp_knapsack[j] = max(dp_knapsack[j], dp_knapsack[j - w] + v);
        }
    }

    int ans = *max_element(dp_knapsack.begin(), dp_knapsack.end());
    cout << ans << '\n';
}
/*
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
################################################################################
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;cin>>t;
    // solve_dp(1,1000);
    
 
    while(t--)
    {
        solve();
    }
}
