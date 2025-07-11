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
    ll m;cin>>m;

    vvpl graph(n+1);
    vector<pair<pl,ll>> edges;
    f(i,m)
    {
        ll u,v,w;cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        edges.push_back({{u,v}, w});
    }

    // suppose we fix some edge to be minimum weight edge 
    // then, we find all the paths through that edge from 1 to n 
    // pick the minimum maximum weight edge in all those paths 
    // that will be the best answer for that edge 
    // iterate over all edges, and find the best answer 
    ll ans = LLONG_MAX;

    // we do dijkstra from 1 to a, b to n and find the minimum maximum weight edge 
    // so basically do dijkstra from 1 to all nodes and 
    // from n to all nodes 
    // but here, the cost = maximum over all edges in that path 

    vl dist1(n+1, LLONG_MAX);
    vl distn(n+1, LLONG_MAX);

    priority_queue<pl, vpl, greater<pl>> pq1;
    pq1.push({0, 1});
    dist1[1] = 0;
    while (!pq1.empty())
    {
        ll u = pq1.top().second;
        ll d = pq1.top().first;
        pq1.pop();

        if (d > dist1[u]) continue;

        for (auto &it : graph[u])
        {
            ll v = it.first;
            ll w = it.second;

            if (dist1[v] > max(d, w))
            {
                dist1[v] = max(d, w);
                pq1.push({dist1[v], v});
            }
        }
    }
    priority_queue<pl, vpl, greater<pl>> pq2;
    pq2.push({0, n});
    distn[n] = 0;
    while (!pq2.empty())
    {
        ll u = pq2.top().second;
        ll d = pq2.top().first;
        pq2.pop();

        if (d > distn[u]) continue;

        for (auto &it : graph[u])
        {
            ll v = it.first;
            ll w = it.second;

            if (distn[v] > max(d, w))
            {
                distn[v] = max(d, w);
                pq2.push({distn[v], v});
            }
        }
    }

    for (auto &edge : edges)
    {
        ll u = edge.first.first;
        ll v = edge.first.second;
        ll w = edge.second;
        ll d1 = dist1[u];
        ll d2 = distn[v];
        ll d3 = dist1[v];
        ll d4 = distn[u];
        ll max_edge = max({d1, d2, d3, d4, w});

        ans = min(ans, max_edge + w);
    }

    cout<<ans;L;return;
    
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
