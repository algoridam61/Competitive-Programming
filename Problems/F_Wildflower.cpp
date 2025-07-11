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
int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n;cin>>n;

    vvl graph(n+1);
    
    f(i,n-1)
    {
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vl depth(n+1, -1);
    queue<ll> q;

    q.push(1);
    depth[1] = 1;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (ll child : graph[node])
        {
            if (depth[child] == -1)
            {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }
    }

    vl leaves;
    f1(i, 2, n+1)
    {
        if (graph[i].size() == 1) leaves.push_back(depth[i]);
    }

    if (n == 1) 
    {
        cout<<2;L;return;
    }

    if (leaves.size() == 1)
    {
        ll ans = 1; 
        f(i, n)
        {
            ans = (ans * 2) % MOD;
        }
        cout<<ans;L;return;
    }

    if (leaves.size() > 2)
    {
        cout<<0;L;return;
    }

    ll bridge = 1;

    if (graph[1].size() == 2)
    {
        bridge = 1;
    }
    else 
    {
        f1(i, 2, n+1)
        {
            if (graph[i].size() == 3)
            {
                bridge = i;break;
            } 
        }
    }

    ll d1 = leaves[0];
    ll d2 = leaves[1];

    if (d1 == d2)
    {
        ll ans = 2;
        // debug
        // cout<<"d1: "<<d1<<" d2: "<<d2<<" bridge: "<<depth[bridge]<<endl;

        f(i, depth[bridge])
        {
            ans = (ans * 2) % MOD;
        }
        cout<<ans;L;return;
    }
    else 
    {
        if (d1 < d2) swap(d1, d2);
        ll delta = d1 - d2;
        ll ans = 1;
        f(i, delta-1)
        {
            ans = (ans * 2) % MOD;
        }
        ans = (ans * 3) % MOD;
        f(i, depth[bridge])
        {
            ans = (ans * 2) % MOD;
        }
        cout<<ans;L;return;
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
