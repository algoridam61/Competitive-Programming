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
    int n;cin>>n;
    vl a(n);read(a);

    // you dont want to waste on monsters with freq = 1
    // so build combos using them
    // greedy strategy : first kill all monsters with freq = 1. such that total killed less
    // than the max freq. after that kill all the max freq ones.
    // update the max freq after that

    sortall(a);

    ll ans = 0;
    ll curr_max_ind = n-1;
    ll curr_least_ind = 0;
    ll combo = 0;

    while(curr_least_ind<curr_max_ind)
    {
        while(combo<a[curr_max_ind]&&curr_least_ind<curr_max_ind)
        {
            ll curr_comb = combo + a[curr_least_ind];
            if (curr_comb==a[curr_max_ind])
            {
                
                ans+=a[curr_least_ind];
                ans+=1;
                combo = 0;
                curr_max_ind--;
                curr_least_ind++;
                // cout<<curr_least_ind;L;
                // cout<<curr_max_ind;L;
                break;
            }
            else if (curr_comb<a[curr_max_ind])
            {
                ans+=a[curr_least_ind];
                combo = curr_comb;
                curr_least_ind++;
                // cout<<curr_least_ind;L;
                // cout<<curr_max_ind;L;
            }
            else
            {
                // combo = 0;
                ll temp = a[curr_least_ind] - (a[curr_max_ind]-combo);
                ans+=1;
                ans+=a[curr_least_ind]-temp;
                a[curr_least_ind] = temp;
                curr_max_ind--;
                combo = 0;
                break;
            }
        }
    }
    // cout<<combo;L;
    // cout<<ans;L;
    // cout<<curr_least_ind;L;
    // cout<<curr_max_ind;L;
    if (curr_least_ind==curr_max_ind)
    {
        ll val = a[curr_least_ind];
        ll comb = combo;
        // cout<<val<<" "<<comb;L;
        if (comb==0)
        {
            if (val==1) {ans+=1;
            cout<<ans;L;return;}
        }
        if ((val-comb)%2==0)
        {
            ans+=(val-comb)/2+1;
        }
        else 
        {
            ans+=(val-comb)/2+2;
        }
    }
    cout<<ans;L;
    

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