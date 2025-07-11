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
    
    vvl graph(n+1);
    f(i,n-1)
    {
        ll a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // apply bfs from 1 
    vl dist(n+1, 0);
    queue<ll> q;
    q.push(1);
    vector<bool> visited(n+1, false);
    visited[1] = true;
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        for(ll neighbor : graph[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // out(dist);

    vl node_count_below(n+1, 0);

    function<void(ll, ll)> dfs = [&](ll node, ll parent)
    {
        for (ll neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                dfs(neighbor, node);
                node_count_below[node] += node_count_below[neighbor] + 1;
            }
        }
    };

    dfs(1, -1);

    // out(node_count_below);

    vl ans(n+1, 0);
    
    ll sum = 0;

    f1(i, 2, n+1)
    {
        sum += dist[i];
    }

    ans[1] = sum;

    function<void(ll, ll)> dfs2 = [&](ll node, ll parent)
    {
        for (ll neighbor : graph[node])
        {
            if (neighbor != parent) 
            {
                ans[neighbor] = ans[node] + n - node_count_below[neighbor] - 2 - node_count_below[neighbor];
                dfs2(neighbor, node);
            }
        }
    };

    dfs2(1, -1);

    f1(i, 1, n+1)
    {
        cout<<ans[i]<<" ";
    }
    L;




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
