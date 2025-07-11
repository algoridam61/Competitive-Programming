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
ll max_subarray_sum(vl &a, ll n)
{
    ll max_so_far = LLONG_MIN;
    ll max_ending_here = 0;
 
    for (ll i = 0; i < n; i++)
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve()
{
    ll n;cin>>n;
    ll k;cin>>k;
    string s;cin>>s;
    
    vl a(n);read(a);

    vl b(n);
    f(i,n)
    {
        b[i] = a[i];
    }
    bool iszero = false;
    ll ind = -1;
    f(i,n)
    {
        if (s[i] == '0')
        {
            iszero = true;
            ind = i;
            b[i] = -1e12;
        }
    }

    if (!iszero)
    {
        if (max_subarray_sum(b,n) == k)
        {
            cout<<"YES";L;
            out(b);return;
        }
        else 
        {
            cout<<"NO";L;return;
        }
    }

    if (max_subarray_sum(b,n) <= k)
    {
        cout<<"YES";L;
        // now observe that max subarray sum is less than or equal to k
        // also on adding one, either it will increase or remain same
        ll left = -1e12;
        ll right = 1e12;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            b[ind] = mid;
            if (max_subarray_sum(b,n) == k)
            {
                out(b);return;
            }
            else if (max_subarray_sum(b,n) < k)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid - 1;
            }

        }
    }
    else 
    {
        cout<<"NO";L;return;
    }

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
