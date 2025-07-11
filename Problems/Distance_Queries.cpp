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
    ll q;cin>>q;
    vvl graph(n+1);

    f(i, n-1)
    {
        ll a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vl level(n+1, 0);
    vl parents(n+1, 1);
    function<void(ll, ll)> dfs = [&](ll node, ll parent)
    {
        for (ll neighbor : graph[node]) 
        {
            if (neighbor != parent)
            {
                level[neighbor] = level[node] + 1;
                parents[neighbor] = node;
                dfs(neighbor, node);
            }
        }
    };

    dfs(1, -1);

    ll logn = 32;

    vvl ancestors(n+1, vl(logn, -1));

    f1(i, 1, n+1)
    {
        ancestors[i][0] = parents[i];
    }

    f1(j, 1, logn)
    {
        f1(i, 1, n+1)
        {
            if (ancestors[i][j-1] != -1)
            {
                ancestors[i][j] = ancestors[ancestors[i][j-1]][j-1];
            }
        }
    }

    auto kth_ancestor = [&](ll node, ll k) -> ll
    {
        for (int j = 0; j < logn; j++)
        {
            if (k & (1 << j))
            {
                node = ancestors[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    };

    auto lca = [&](ll u, ll v) -> ll
    {
        if (level[u] < level[v]) swap(u, v);
        ll diff = level[u] - level[v];
        
        u = kth_ancestor(u, diff);
        
        if (u == v) return u;
        
        for (int j = logn - 1; j >= 0; j--)
        {
            if (ancestors[u][j] != -1 && ancestors[u][j] != ancestors[v][j])
            {
                u = ancestors[u][j];
                v = ancestors[v][j];
            }
        }
        return parents[u];
    };

    while (q--)
    {
        ll u, v;cin>>u>>v;
        ll lca_node = lca(u, v);
        ll dist = level[u] + level[v] - 2 * level[lca_node];
        cout << dist << "\n";
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
    // cin>>t;
 
    while(t--)
    {
        solve();
    }
}
