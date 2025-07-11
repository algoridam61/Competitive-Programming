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

    // find the powers of 2 and 5 in n
    ll p2;
    ll p5;

    ll i = 0;
    ll n1 = n;
    while (n1 % 2 == 0)
    {
        n1 /= 2;
        i++;
    }
    p2 = i;
    i = 0;
    n1 = n;
    while (n1 % 5 == 0)
    {
        n1 /= 5;
        i++;
    }
    p5 = i;

    // cout<<p2<<" "<<p5;L;

    if (p2 == p5)
    {
        // find the multiple of 10 less than or equal to m
        if (m<10)
        {
            cout<<n*m;L;
            return;
        }
        else 
        {
            ll curr = 1;
            while (curr <= m)
            {
                curr *= 10;
                if (curr > m)
                {
                    curr /= 10;
                    break;
                }
            }
            if (curr*9 <= m) curr *= 9;
            else if (curr*8 <= m) curr *= 8;
            else if (curr*7 <= m) curr *= 7;
            else if (curr*6 <= m) curr *= 6;
            else if (curr*5 <= m) curr *= 5;
            else if (curr*4 <= m) curr *= 4;
            else if (curr*3 <= m) curr *= 3;
            else if (curr*2 <= m) curr *= 2;
            cout<<n*curr;L;
            return;
        }
    }
    else if (p2 > p5)
    {
        ll diff = p2 - p5;
        ll num = 1;
        while (diff--)
        {
            num *= 5;
        }
        if (m<num)
        {
            ll curr = 1;
            while (curr <= m)
            {
                curr *= 5;
                if (curr > m)
                {
                    curr /= 5;
                    break;
                }
            }
            if (curr*9 <= m) curr *= 9;
            else if (curr*8 <= m) curr *= 8;
            else if (curr*7 <= m) curr *= 7;
            else if (curr*6 <= m) curr *= 6;
            else if (curr*5 <= m) curr *= 5;
            else if (curr*4 <= m) curr *= 4;
            else if (curr*3 <= m) curr *= 3;
            else if (curr*2 <= m) curr *= 2;
            cout<<n*curr;L;return;
        }
        else 
        {
            ll curr = num;
            // cout<<curr;L;
            while (curr <= m)
            {
                curr *= 10;
                if (curr > m)
                {
                    curr /= 10;
                    break;
                }
            }
            // cout<<curr;L;
            if (curr*9 <= m) curr *= 9;
            else if (curr*8 <= m) curr *= 8;
            else if (curr*7 <= m) curr *= 7;
            else if (curr*6 <= m) curr *= 6;
            else if (curr*5 <= m) curr *= 5;
            else if (curr*4 <= m) curr *= 4;
            else if (curr*3 <= m) curr *= 3;
            else if (curr*2 <= m) curr *= 2;
            cout<<n*curr;L;return;
        }
    }
    else 
    {
        ll diff = p5 - p2;
        ll num = 1;
        while (diff--)
        {
            num *= 2;
        }
        if (m<num)
        {
            ll curr = 1;
            while (curr <= m)
            {
                curr *= 2;
                if (curr > m)
                {
                    curr /= 2;
                    break;
                }
            }
            if (curr*9 <= m) curr *= 9;
            else if (curr*8 <= m) curr *= 8;
            else if (curr*7 <= m) curr *= 7;
            else if (curr*6 <= m) curr *= 6;
            else if (curr*5 <= m) curr *= 5;
            else if (curr*4 <= m) curr *= 4;
            else if (curr*3 <= m) curr *= 3;
            else if (curr*2 <= m) curr *= 2;
            cout<<n*curr;L;return;
        }
        else 
        {
            ll curr = num;
            while (curr <= m)
            {
                curr *= 10;
                if (curr > m)
                {
                    curr /= 10;
                    break;
                }
            }
            if (curr*9 <= m) curr *= 9;
            else if (curr*8 <= m) curr *= 8;
            else if (curr*7 <= m) curr *= 7;
            else if (curr*6 <= m) curr *= 6;
            else if (curr*5 <= m) curr *= 5;
            else if (curr*4 <= m) curr *= 4;
            else if (curr*3 <= m) curr *= 3;
            else if (curr*2 <= m) curr *= 2;
            cout<<n*curr;L;return;
        }
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
