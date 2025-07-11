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

bool checkpresent(vi sorted_vector, int target)
{
int n=size(sorted_vector);
int l=0;int h=n-1;
while(l<=h)
{
    int mid=(l+h)/2;
    if (sorted_vector[mid]==target)
    {return true;}
    else if (sorted_vector[mid]>target)
    {
        l=mid;
    }
    else h=mid;
}
return false;

}
 
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
// ll dp(int n, int m, ll k, vvl &a, vvl &memo)
// {
//     if (n < 0 || m < 0 || n >= memo.size() || m >= memo[0].size()) return INT_MAX; // Check for out-of-bounds
    
//     if (memo[n][m] != -1) return memo[n][m];
    
//     if (n == 0)
//     {
//         // ll ans1 = a[0][0];
//         ll min1 = 0;
//         f(i,m+1)
//         {
//             min1+=a[0][i];
//         }
//         ll ans = min1;
//         f1(i,1,size(a[0]))
//         {
//             ans = ans - a[0][i-1] + a[0][(m+i+size(a[0]))%size(a[0])] + k*i;
//             min1 = min(min1,ans);
//         }
//         return min1;
//     }
//     ll costup = INT_MAX, costleft = INT_MAX;

//     if (n > 0) costup = dp(n-1, m, k, a, memo) + a[n][m];
//     if (m > 0) costleft = dp(n, (m-1+size(a[0]))%size(a[0]), k, a, memo) + a[n][m];
//     for (int j = 0;j<a[0].size();j++)
//     {
//         costleft = min(costleft,dp(n,j,k,a,memo)+a[n][(j+1+a[0].size())%(a[0].size())]+(ll)k*(ll)((m-j+size(a[0]))%size(a[0])));
//     }
//     ll min_cost = min(costup, costleft);

//     f(i, a[0].size()) 
//     {
//         if (i < a[0].size()) // Ensure i is within bounds
//         {
//             if (costup!=INT_MAX)
//             {ll shift_cost = a[n][i] + k * (ll)((i - m + a[0].size()) % a[0].size());
//             min_cost = min(min_cost, costup - a[n][m] + shift_cost);}
//         }
//     }

//     return memo[n][m] = min_cost;
// }
// the above dp does not work
ll memo1[201][201][201];
ll memo2[201][201];
ll dp1(int i,int j,int shift,vvl& a,int n,int m,ll k);
ll dp2(int i,int j,vvl& a,int n,int m,ll k);
ll dp1(int i,int j,int shift,vvl& a,int n,int m,ll k)
{
    if (memo1[i][j][shift]!=-1) return memo1[i][j][shift];
    if (i==n-1&&j==m-1) return 0;

    ll ans = 10000000000000000;
    if (i<n-1)
    {
        ans = min(ans,dp2(i+1,j,a,n,m,k));
    }
    if (j<m-1)
    {
        ans = min(ans,dp1(i,j+1,shift,a,n,m,k)+a[i][(j+shift+1)%m]);
    }
    return memo1[i][j][shift] = ans;

}
ll dp2(int i,int j,vvl& a,int n,int m,ll k)
{
    if (memo2[i][j]!=-1) return memo2[i][j];
    ll ans = 10000000000000000;

    f(s,m)
    {
        ans = min(ans,(ll)(k*s)+dp1(i,j,s,a,n,m,k)+a[i][(j+s)%m]);
    }
    return memo2[i][j] = ans;
}
void solve()
{
    int n;cin>>n;
    int m;cin>>m;

    ll k;cin>>k;

    vvl a(n,vl(m));

    f(i,n) f(j,m) cin>>a[i][j];
    f(i,n) f(j,m) memo2[i][j] = -1;
    f(i,n) f(j,m) f(k,m) memo1[i][j][k] = -1;
    cout<<dp2(0,0,a,n,m,k);L;
    // cout<<"hello";L;
    // we need to maintain 2 dp arrays
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
    cin>>t;
 
 
    while(t--)
    {
        solve();
    }
}