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

bool checkpresent(vi sorted_vector, int target)
{
int n=size(sorted_vector);
int l=0;int h=n-1;
while(l<=h)
{
    int mid=(l+h)/2;
    if (sorted_vector[mid]==target)
    {return true;}
    else if (sorted_vector[mid]>target)
    {
        l=mid;
    }
    else h=mid;
}
return false;

}
 
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
    int n;cin>>n;
    int m;cin>>m;
    ll v;cin>>v;

    vl a(n);read(a);

    // lets first check possible or not
    ll curr = 0;
    ll count = 0;
    vi indices_s(n+1);
    indices_s[0] = 0;
    vi indices_e(n+1);
    indices_e[0] = n-1;
    int i = 0;
    while (i<n)
    {
        while (curr < v&&i<n)
        {
            curr+=a[i];
            i++;
        }
        if (curr>=v) count++;
        // indices_s[count] = i; // i - 1 has the last element of the partition
        // count++;
        curr = 0;

    }
    if (count<m)
    {
        cout<<-1;L;
    }
    else
    {
        // possible
        vl pref(n);
        pref[0] = a[0];
        f1(i,1,n)
        {
            pref[i] = pref[i-1]+a[i];
        }
        // count = 0;
        ll ans = 0;
        curr = 0;
        count = 0;
        i = n-1;
        while (i>=0)
        {
            while (curr < v&&i>=0)
            {
                curr+=a[i];
                i--;
            }
            if (curr>=v) {count++;
            indices_e[count] = i; }// i + 1 has the first element of the partition
            // count++;
            curr = 0;
        }
        curr = 0;
        count = 0;
        i = 0;
        while (i<n)
        {
            while (curr < v&&i<n)
            {
                curr+=a[i];
                i++;
            }
            if (curr>=v) {count++;
            // cout<<i;L;
            indices_s[count] = i;} // i - 1 has the last element of the partition
            // count++;
            curr = 0;

        }
        f(i,m+1)
        {
            ll left = indices_s[m-i];
            ll right = indices_e[i];
            if (right>=left) ans = max(ans,pref[right]-pref[left]+a[left]);
        }
        cout<<ans;L;
        
    }

    // out(indices_e);out(indices_s);
 
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