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

// const ll MOD = 1000000007;
 
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
const int MOD = 1000000007;
const int MAXN = 200005;
vector<ll> fact, invfact;

ll power(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

void precompute() {
    fact.resize(MAXN);
    invfact.resize(MAXN);
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[MAXN-1] = power(fact[MAXN-1], MOD-2);
    for(int i = MAXN-2; i >= 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
}

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % MOD) * invfact[n-r]) % MOD;
}

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vi a(n); read(a);
    sortall(a);
    // precompute();  
    
    int dist = (k-1)/2;
    ll ans = 0;
    f(i,n) {
        if (a[i]==1) {
            ans = (ans + (C(i,dist) * C(n-i-1,dist)) % MOD) % MOD;
        }
    }
    cout << ans % MOD; L;
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
    precompute();
    int t=1;
    cin>>t;
 
 
    while(t--)
    {
        solve();
    }
}