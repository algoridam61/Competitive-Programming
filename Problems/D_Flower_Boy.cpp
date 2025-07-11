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
void solve()
{
    ll n;cin>>n;
    ll m;cin>>m;

    vl a(n);read(a);
    vl b(m);read(b);

    vl pref(m,-1);
    vl suff(m,-1);


    ll curr = b[0];
    ll j = 0;
    ll i = 0;
    while (j < n)
    {
        if (a[j] >= curr)
        {
            pref[i] = j;
            if (i == m - 1)
                break;
            curr = b[i+1];
            i++;
            j++;
        }
        else j++;
    }

    curr = b[m-1];
    j = n - 1;
    i = m - 1;
    while (j >= 0)
    {
        if (a[j] >= curr)
        {
            suff[i] = j;
            if (i == 0)
                break;
            curr = b[i-1];
            i--;
            j--;
        }
        else j--;
    }
    // cout<<pref[m-1]<<" "<<suff[0]<<"\n";
    if (pref[m-1]!=-1 || suff[0]!=-1 )
    {
        cout<<0;L;
        return;
    }
    vl valids;

    f(i,m)
    {
        if (i != 0 && i != m - 1 && pref[i-1] != -1 && suff[i+1] != -1 )
        {
            if (pref[i-1] < suff[i+1])
            {
                valids.push_back(b[i]);
            }
        }
        else if (i == 0)
        {
            if (suff[i+1] != -1)
            {
                valids.push_back(b[i]);
            }
        }
        else if (i == m - 1)
        {
            if (pref[i-1] != -1)
            {
                valids.push_back(b[i]);
            }
        }
        else
        {
            continue;
        }
        
    }

    sortall(valids);

    if (valids.size() == 0)
    {
        cout << -1;L;
        return;
    }
    cout << valids[0] << "\n";


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
