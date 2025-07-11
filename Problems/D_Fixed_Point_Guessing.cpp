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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
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

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll calculate_nCr_mod_p(int n_val, int r_val) {
    if (r_val < 0 || r_val > n_val) {
        return 0;
    }
    if (r_val == 0 || r_val == n_val) {
        return 1;
    }
    if (r_val > n_val / 2) {
        r_val = n_val - r_val;
    }
    ll res = 1;
    for (int i = 0; i < r_val; ++i) {
        res = (res * (n_val - i)) % MOD;
        res = (res * modInverse(i + 1)) % MOD;
    }
    return res;
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
    
    // there is one fixed point
    // we need to find that point 

    // naive method 
    // just ask l = r for i = 1 to n 
    // wherever we get i = answer, that must be the fixed point. 
    // also 2^15 > 3e4, so we need to do binary search for sure 

    // so, first we ask mid, end 

    ll left = 1;
    ll right = n;
    ll mid;

    while (left <= right)
    {
        if (left == right)
        {
            cout<<"! "<<left<<endl;
            return;
        }
        mid = (left + right) / 2;

        cout<<"? "<<left<<" "<<mid<<endl;
        vl response(mid - left + 1);
        ll outsiders = 0;
        f(i, mid - left + 1)
        {
            cin>>response[i];
            if (response[i] < left || response[i] > mid) outsiders++;
        }
        if (outsiders % 2 == 0)
        {
            if ((mid - left + 1)%2 == 0)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }
        else 
        {
            if ((mid - left + 1)%2 == 0)
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
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
