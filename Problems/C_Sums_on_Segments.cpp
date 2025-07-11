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
// #define INF (unsigned)!((int)0)
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
    vl a(n);read(a);

    int pos = -1;
    f(i,n)
    {
        if (a[i]!=1&&a[i]!=-1) {pos = i;break;}
    }

    // set<ll> sums;

    // each subarray is defined by l and r.
    
    vl pref(n);
    pref[0] = a[0];
    f1(i,1,n)
    {
        pref[i] = pref[i-1] + a[i];
    }

    // sums.insert(0);
    // out(pref);return;

    // vl minpref(n);
    // vl maxpref(n);
    // pref[0] = minpref[0] = maxpref[0];
    // f1(i,1,n)
    // {
    //     maxpref[i] = maxpref[i-1]>pref[i] ? maxpref[i-1] : pref[i];
    //     minpref[i] = minpref[i-1]<pref[i] ? minpref[i-1] : pref[i];
    // }

    // if (pos==-1)
    // {
    //     // strange not present
    //     // find maximum and minimum sum segment
    //     ll maxs = -LLONG_MIN;
    //     ll mins = LLONG_MAX;
    //     // find the minimum and maximum sum segments
    //     for (int right = 0;right <= n-1;right++)
    //     {
    //         ll maxcurr = pref[right] - minpref[right];
    //         ll mincurr = pref[right] - maxpref[right];
    //         maxs = max(maxs,maxcurr);
    //         mins = min(mins,mincurr);
    //     }
    //     mins = min(0ll,mins);
    //     maxs = max(0ll,maxs);
    //     cout<<maxs-mins+1;L;
    //     f1(i,mins,maxs+1)
    //     {
    //         cout<<i<<" ";
    //     }
    //     L;

    // }
    // else
    

    ll l1 = 0;
    ll r1 = 0;
    ll l2 = 2000000000;
    ll r2 = -2000000000;

    ll prefcurr = 0;
    ll minl = 0;ll maxl = 0;
    ll minr = 2000000000;ll maxr = -2000000000;

    f(i,n)
    {
        prefcurr += a[i];
        if (i==pos)
        {
            
            minr = minl;maxr = maxl;minl = prefcurr;maxl = prefcurr;
        }
        l1 = min(l1,prefcurr - maxl);
        r1 = max(r1,prefcurr - minl);
        l2 = min(l2,prefcurr - maxr);
        r2 = max(r2,prefcurr - minr);
        minl = min(minl,prefcurr);
        maxl = max(maxl,prefcurr);
    }

    if (l1>r2)
    {
        // cout<<r1;L;
        // cout<<r2;L;
        // cout<<l1;L;
        // cout<<l2;L;
        cout<<max(r1-l1+1,0ll)+max(r2-l2+1,0ll);L;
        
        f1(i,l2,r2+1)
        {
            cout<<i<<" ";
        }
        f1(i,l1,r1+1)
        {
            cout<<i<<" ";
        }
        L;
    }
    else if (l2>r1)
    {
       
        cout<<max(0ll,r1-l1+1)+max(0ll,r2-l2+1);L;
         f1(i,l1,r1+1)
        {
            cout<<i<<" ";
        }
        f1(i,l2,r2+1)
        {
            cout<<i<<" ";
        }
        L;
    }
    else 
    {
        cout<<(max(0ll,max(r1,r2)-min(l1,l2)+1));L;
        f1(i,min(l2,l1),max(r2,r1)+1)
        {
            cout<<i<<" ";
        }
        L;
    
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