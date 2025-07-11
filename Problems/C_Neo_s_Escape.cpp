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
    // ll k;cin>>k;
    
    vl a(n);read(a);

    // count the number of peaks
    vpl b(n,{0,0});
    f(i,n)
    {
        b[i].first = a[i];
        b[i].second = i;
    }
    rsortall(b);

    vl done(n,0);

    ll peaks = 1;
    done[b[0].second] = 1;
    ll curr_peak_ind = b[0].second;
    ll curr_ind = curr_peak_ind;
    ll dones = 1;   
    ll both_sides_done = 0;
    ll curr_peak_arr_ind = 0; 
    while (dones < n)
    {
        if (both_sides_done == 0)
        {
            if (curr_ind-1 >= 0 && done[curr_ind-1] == 0 && a[curr_ind-1] <= a[curr_ind])
            {
                curr_ind--;
                done[curr_ind] = 1;
                dones++;
            }
            // else if (curr_ind+1 < n && done[curr_ind+1] == 0)
            // {
            //     curr_ind++;
            //     done[curr_ind] = 1;
            //     dones++;
            // }
            else 
            {
                both_sides_done = 1;
                curr_ind = curr_peak_ind;
                // done[curr_peak_ind] = 1;
            }
        }
        else 
        {
            // if (curr_ind-1 >= 0 && done[curr_ind-1] == 0)
            // {
            //     curr_ind--;
            //     done[curr_ind] = 1;
            //     dones++;
            // }
            
            if (curr_ind+1 < n && done[curr_ind+1] == 0 && a[curr_ind+1] <= a[curr_ind])
            {
                curr_ind++;
                done[curr_ind] = 1;
                dones++;
            }
            else 
            {
                both_sides_done = 0;
                // find another peak
                curr_peak_arr_ind++;
                while (curr_peak_arr_ind < n)
                {
                    if (done[b[curr_peak_arr_ind].second] == 0)
                    {
                        curr_peak_ind = b[curr_peak_arr_ind].second;
                        curr_ind = curr_peak_ind;
                        done[curr_peak_ind] = 1;
                        dones++;
                        peaks++;
                        break;
                    }
                    curr_peak_arr_ind++;
                }
            }
        }
    }
    cout<<peaks;L;
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
