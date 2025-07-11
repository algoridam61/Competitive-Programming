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
map<ll,ll> mp;
// map<ll,ll> max_diff;
// map<ll,ll> last_index;
map<ll,vl> group_index;
bool check_valid(ll i,ll k,ll n,vl& a)
{
    // from 0 to i-1, everyone should be present in. in each of the k groups
    // all the groups will be contiguous
    // first check if there are k each of 0 to i-1
    // then check difference between any 2 consecutive elements should be 
    // for (ll j = 0; j <= i; j++)
    // {
    //     if (mp[j] < k) return false;
    // }
    // this means there are k each of 0 to i-1
    ll curr_ind = -1;
    ll count = 0;
    
    // find the smallest index for each of i to i-1, greater than curr_ind
    while (true)
    {
        ll curr_max = curr_ind;
        for (ll j = 0; j <= i; j++)
        {
            
            vl curr = group_index[j];
            // find index in curr greater than curr_ind
            auto it = lower_bound(curr.begin(), curr.end(), curr_ind);
            // cout<<curr_ind<<" "<<j<<" "<<*it<<count<<endl;
            if (it == curr.end()) return false;
            curr_max = max(curr_max, *it);
        }
        curr_ind = curr_max + 1;
        count++;
        if (curr_ind > n) return false;
        if (count == k) return true;
        
    }
}
void solve()
{
    ll n;cin>>n;
    ll k;cin>>k;
    
    vl a(n);read(a);

    
    f(i,n)
    {
        mp[a[i]]++;
        group_index[a[i]].push_back(i);
    }

    // ll count = n/k;
    ll i = 0;
    while (true)
    {
        if (mp[i] < k) break;
        else i++;
    }

    // cout<<i;L;

    // our answer will be less than or equal to i
    // say we need to check for a particular i.
    // can we do binary search on the answer?
    // each search will take O(n)
    // so total time complexity will be O(nlogn)
    if (i == 1)
    {
        cout<<1;L;
        group_index.clear();
        mp.clear();
        return;
    }

    ll left = 0;
    ll right = i-1;

    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        bool check = check_valid(mid,k,n,a);
        if (check)
        {
            ans = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    // cout<<check_valid(4,k,n,a);L;

    cout<<ans+1;L;

    group_index.clear();
    mp.clear();


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
