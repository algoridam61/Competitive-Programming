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
 
int log1(int x,int b)
{
	int cnt = 0;
	while (x) {
		x /= b;
		cnt++;
	}
	return cnt;
}

vector<int> bit32_dec_to_binary(int n)
{
    vector<int> ans(32);
    for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
    return ans;
}

unsigned int nextPowerOf2(unsigned int n) {
    if (n == 0)
        return 1; // Smallest power of 2 for n=0 is 1.
    n--; // Subtract 1 to handle cases where n is already a power of 2.
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16; // For 32-bit integers, this handles all bits.
    return n + 1;
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

// ll dpsolve(ll i, ll x)
// {
//     if (i == 0 || x == 0)
//         return 0;
//     if (dp[i][x] != -1)
//         return dp[i][x];
//     if (price[i - 1] <= x)
//         return dp[i][x] = max(dpsolve(i - 1, x), dpsolve(i - 1, x - price[i - 1]) + pages[i - 1]);
//     else
//         return dp[i][x] = dpsolve(i - 1, x);
// }    
void solve()
{
    int n;cin>>n;
    int x;cin>>x;

    vvi dp(n+1,vi(x+1,-1));
    vi price(n);
    vi pages(n);

    // price.resize(n);
    // pages.resize(n);
    // dp.resize(n+1,vi(x+1,-1));
    
    read(price);
    read(pages);

    // cout<<dpsolve(n,x);L;              
    // solving by iterative dp
    for (int j = 0; j <= x; j++)
        dp[0][j] = 0;

    f1(i,1,n+1)   
    {
        f1(j,0,x+1)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (price[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout<<dp[n][x];L;
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
 
    int t=1;
    // cin>>t;
 
    while(t--)
    {
        solve();
    }
}
