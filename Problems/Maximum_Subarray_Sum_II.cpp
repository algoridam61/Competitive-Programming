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
    ll a,b;cin>>a>>b;

    vl arr(n);read(arr);
    
    f(i,b-a+1)
    {
        arr.push_back(-1e10);
    }
    n+= b-a+1;

    vl pref(n+1,0);
    f1(i,1,n+1)
    {
        pref[i] = pref[i-1] + arr[i-1];
    }

    ll window_size = b - a + 1;
    vl sliding_window_max(n-window_size+2,0);
    ll max_so_far = 0;
    deque<int> dq;

    for (int i = 0; i < pref.size(); ++i) 
    {
        if (!dq.empty() && dq.front() <= i - window_size) 
        {
            dq.pop_front();
        }

            // Maintain monotonically decreasing order of values in deque (for maximum)
            // Remove elements from the back of the deque that are smaller than or equal to the current element pref[i]
        while (!dq.empty() && pref[dq.back()] <= pref[i]) 
        {
            dq.pop_back();
        }
        dq.push_back(i);

        // Once the window is full (i.e., we have processed at least window_size elements,
        // so i >= window_size - 1), the front of the deque has the index of the maximum element
        // for the window ending at index i.
        // This window is pref[i - window_size + 1 ... i].
        // The result for this window corresponds to sliding_window_max[i - window_size + 1].
        if (i >= window_size - 1) 
        {
            sliding_window_max[i - window_size + 1] = pref[dq.front()];
        }
    }
    // out(pref);
    // out(sliding_window_max);
    ll ans = LLONG_MIN;
    f1(i,0,n-window_size+1-a+1)
    {
        ans = max(ans,sliding_window_max[i+a] - pref[i]);
    }
    cout<<ans;L;
    // with sliding window maximum this will be done in O(n)
    // 

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
