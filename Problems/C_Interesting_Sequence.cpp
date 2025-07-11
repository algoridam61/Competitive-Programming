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

template<typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
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

vi getBinary(ll n)
{
    // 64 bit vector
    vi binary(64, 0);
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
    // reverse(binary.begin(), binary.end());
    return binary;
}

void solve()
{
    ll n;cin>>n;
    ll x;cin>>x;
    
    // any position where 1 in x, all should be 1
    // from n to m

    ll limit_1;

    vl powers_of_2(64);
    powers_of_2[0] = 1;
    for (int i = 1; i < 64; i++)
    {
        powers_of_2[i] = powers_of_2[i - 1] * 2;
    }

    vi binary_x = getBinary(x);
    vi binary_n = getBinary(n);
    ll limit_h = LLONG_MAX;
    ll limit_l = n;

    f(i,64)
    {
        if (binary_x[i] == 1)
        {
            if (binary_n[i] == 0)
            {
                cout<<-1;L;return;
            }
            else 
            {
                ll nxt = x / powers_of_2[i];

                nxt = (nxt + 1) * powers_of_2[i];

                limit_h = min(limit_h, nxt - 1);
            }
        }
        else 
        {
            if (binary_n[i] == 1)
            {
                ll curr = 0;
                for (int j = 0; j <= i; j++)
                {
                    curr += binary_n[j] * powers_of_2[j];
                }
            
                ll nxt = n + powers_of_2[i+1] - curr;
                limit_l = max(limit_l, nxt);
            }
        }
    }

    if (limit_l > limit_h)
    {
        cout<<-1;L;return;
    }

    cout<<limit_l;L;



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
