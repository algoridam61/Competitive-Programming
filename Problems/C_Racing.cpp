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
void solve()
{
    ll n;cin>>n;
    vl d(n);read(d);

    vl l(n);vl r(n);

    f(i,n)
    {
        cin>>l[i]>>r[i];
    }

    // we try if all 0s work

    // if not, we will place some 1s

    // for each stream of -1s, we calculate the maximum and minimum heights after that
    // phase
    // vl pref(n,0);
    // f(i,n)
    // {
    //     if (i == 0) 
    //     {
    //         if (d[i] == -1)
    //         {
    //             pref[i] = 0;
    //         }
    //     }
    // }

    vl maxi(n,0);
    vl mini(n,0);

    if (d[0] == 1)
    {
        maxi[0] = min(1ll,r[0]);
        mini[0] = max(1ll,l[0]);
    }
    else if (d[0] == 0)
    {
        maxi[0] = min(0ll,r[0]);
        mini[0] = max(0ll,l[0]);
    }
    else 
    {
        maxi[0] = min(1ll,r[0]);
        mini[0] = max(0ll,l[0]);
    }

    if (maxi[0] < mini[0]) 
    {
        cout<<-1;L;return;
    }

    f1(i,1,n)
    {
        if (d[i]) maxi[i] = min(maxi[i-1]+1,r[i]);
        else maxi[i] = min(maxi[i-1],r[i]);
        if (d[i] == 1) mini[i] = max(mini[i-1]+1,l[i]);
        else mini[i] = max(mini[i-1],l[i]);
        if (maxi[i] < mini[i])
        {
            cout<<-1;L;return;
        }
    }
    // iteratively construct the mini sequence backwards
    // if reach here, possible

    // let us try to construct mini.
    ll last = mini[n-1];

    for (int i = n-1;i > 0;i--)
    {
        if (d[i]>=0)
        {
            if (d[i] == 1)
            {
                last--;
            }
        }
        else 
        {
            if (mini[i-1] == last)
            {
                d[i] = 0;
            }
            else 
            {
                d[i] = 1;
                last--;
            }
        }
    }

    if (d[0] == -1)
    {
        if (0 == last)
        {
            d[0] = 0;
        }
        else 
        {
            d[0] = 1;
            last--;
        }
    }

    out(d);





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
