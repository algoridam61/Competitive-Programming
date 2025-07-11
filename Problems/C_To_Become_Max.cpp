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
bool check(vl &a, ll mid, ll k)
{
    if (mid == 0) return true;
    ll n = a.size();
    ll curr_max = LLONG_MIN;
    f(i, n)
    {
        curr_max = max(curr_max, a[i]);
    }
    ll min_cost = LLONG_MAX;
    f(i, n)
    {
        // we want to make a[i] = curr_max + mid
        ll target = curr_max + mid;
        ll cost = target - a[i];
        target--;
        bool flag = false;
        int j = i + 1;
        while (true)
        {
            if (j >= n) break;
            if (a[j] <= target) 
            {
                // if (mid == 3)
                // cout << "i: " << i << " j: " << j << " target: " << target << "\n";
                cost += target - a[j];
                if (a[j] == target) 
                {
                    flag = true;
                    break;
                }
                target--;

            }
            else {flag = true;break;}
            j++;
        }
        if (flag) 
        {
            min_cost = min(min_cost, cost);
        }
        // if (mid == 3 && flag)
        // {
        //     // cout << "i: " << i << " cost: " << cost << " target: " << target << "\n";
        // }
    }
    if (min_cost <= k) return true;
    return false;
}
void solve()
{
    ll n;cin>>n;
    ll k;cin>>k;
    
    vl a(n);read(a);

    ll left = 0;
    ll right = n - 1;

    ll ans = 0;
    ll curr_max = LLONG_MIN;
    f(i, n)
    {
        curr_max = max(curr_max, a[i]);
    }

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        bool poss = check(a, mid, k);

        // cout << "mid: " << mid << " poss: " << poss << "\n";

        if (poss)
        {
            ans = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    cout << ans + curr_max << "\n";
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
