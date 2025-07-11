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
    ll k;cin>>k;
    
    vl a(n);read(a);

    map<ll,ll> freqs;

    ll num_distinct = 0;
    ll i = 0;
    while (1)
    {
        if (i == n)
        {
            cout<<n*(n+1)/2;L;return;
        }

        if (freqs[a[i]] == 0)
        {
            num_distinct++;freqs[a[i]]++;
            if (num_distinct > k)
            {
                break;
            }
            
        }
        else 
        {
            freqs[a[i]]++;
        }
        i++;
    }
    ll ans = i*(i+1)/2;
    // cout<<ans;L;
    ll pointerl = 0;
    ll pointerr = i;
    // cout<<freqs[1]<<endl;
    // currently, from 0 to i inclusive, we have k + 1 distinct 
    // elements
    // so we increase pointerl till we have k distinct elements
    bool remove_front = true;
    while (pointerr < n)
    {
        if (remove_front)
        {
            while (1)
            {
                freqs[a[pointerl]]--;
                
                if (freqs[a[pointerl]] == 0)
                {
                    num_distinct--;pointerl++;
                    break;
                }
                pointerl++;
            }
        }
        // now we again have k distinct elements
        // cout<<pointerl;L;
        ans ++; // for the new element
        ans += (pointerr - pointerl);
        // cout<<"mating between "<<pointerl<<" and "<<pointerr<<endl; 
        // cout<<ans;L;
        pointerr++;
        if (pointerr == n)
        {
            break;
        }
        // cout<<"freq of 1 is: "<<freqs[1]<<endl;
        if (freqs[a[pointerr]] == 0)
        {
            // cout<<"hello";L;
            num_distinct++;
            freqs[a[pointerr]]++;
            remove_front = true;
        }
        else 
        {
            freqs[a[pointerr]]++;
            remove_front = false;
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
    // cin>>t;
 
    while(t--)
    {
        solve();
    }
}
