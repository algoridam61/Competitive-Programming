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

    f(i,n)
    {
        if (a[i] <= k)
        {
            a[i] = 1;
        }
        else a[i] = -1;
    }


    vl pref(n,0);
    pref[0] = a[0];
    
    f1(i,1,n)
    {
        pref[i] = pref[i-1] + a[i];
    }

    vl tags;
    ll i1 = n+1;
    f(i,n)
    {
        if (pref[i] >= 0) {tags.push_back(pref[i]);i1 = min(i1,(ll)(i));}
    }

    if (size(tags) > 1)
    {
        f(i,size(tags)-1)
        {
            if (tags[i] <= tags[i+1]) yes
        }
    }
    

    vl prefb(n,0);
    prefb[n-1] = a[n-1];
    vl tags2;
    for (int i = n-2; i >= 0; i--)
    {
        prefb[i] = prefb[i+1] + a[i];
    }
    ll i2 = -1;
    for (int i = n-1; i >= 0; i--)
    {
        if (prefb[i] >= 0) {tags2.push_back(prefb[i]);i2 = max((ll)(i),i2);}
    }
    if (size(tags2) > 1)
    {
        for (int i = 0; i < size(tags2)-1; i++)
        {
            if (tags2[i] <= tags2[i+1]) yes
        }
    }

    if (i1 < i2) yes

    no

    

    
    

    
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
