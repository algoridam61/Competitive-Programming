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

    // for each node maintain 2 values dist and maxi_cost
    // below algo is not correct...
    // vvpl graph(n+1);



    // f(i,m)
    // {
    //     ll u,v,c;cin>>u>>v>>c;

    //     graph[u].push_back({v,c});
    // }

    // vl dist(n+1,1e18);
    // vl maxi(n+1,-10);

    // // for each node, we store a value of dist - maxi / 2 in the priority queue 

    // // vl val(n+1, LLONG_MAX);

    // dist[1] = 0;
    // maxi[1] = 0;


    // priority_queue<pl, vpl, greater<pl>> pq;

    // pq.push({0,1});

    // while (!pq.empty())
    // {
    //     pl curr = pq.top();
    //     pq.pop();

    //     ll curr_node = curr.second;
    //     ll curr_dist = dist[curr_node];
    //     ll curr_maxi = maxi[curr_node];

    //     for (auto [neigh,cost] : graph[curr_node])
    //     {
    //         ll next_node = neigh;
    //         ll next_dist = dist[next_node];
    //         ll next_maxi = maxi[next_node];

    //         // debug
    //         cout<<"curr_node: "<<curr_node<<" curr_dist: "<<curr_dist<<" curr_maxi: "<<curr_maxi<<" next_node: "<<next_node<<" next_dist: "<<next_dist<<" next_maxi: "<<next_maxi<<endl;

    //         if (curr_maxi > cost)
    //         {
    //             if (next_dist - (ll)(ceil(double(next_maxi) / 2.0)) >= curr_dist + cost - (ll)(ceil(double(curr_maxi) / 2.0)))
    //             {
    //                 dist[next_node] = curr_dist + cost;
    //                 maxi[next_node] = curr_maxi;
    //                 pq.push({dist[next_node] , next_node});
    //             }
    //         }
    //         else 
    //         {
    //             if (next_dist - (ll)(ceil(double(next_maxi) / 2.0)) >= curr_dist + cost - (ll)(ceil(double(cost) / 2.0)))
    //             {
    //                 dist[next_node] = curr_dist + cost;
    //                 maxi[next_node] = cost;
    //                 pq.push({dist[next_node] , next_node});
    //             }
    //         }

    //         // debug
    //         cout<<"After processing: next_node: "<<next_node<<" dist: "<<dist[next_node]<<" maxi: "<<maxi[next_node]<<" val: "<<dist[next_node] - maxi[next_node] / 2<<endl;
    //     }
    // }

    // cout<<dist[n] - (ll)(ceil(double(maxi[n]) / 2.0));L;return;


    vvpl graph(n+1);
    vvpl graphrev(n+1);
    vector<pair<ll,pl>> edges;
    f(i,m)
    {
        ll u,v,c;cin>>u>>v>>c;

        graph[u].push_back({v,c});
        graphrev[v].push_back({u,c});
        edges.push_back({u,{v,c}});
    }
    vl dist1(n+1,1e18);
    vl distn(n+1,1e18);
    dist1[1] = 0;
    distn[n] = 0;
    priority_queue<pl, vpl, greater<pl>> pq1;
    priority_queue<pl, vpl, greater<pl>> pqn;
    pq1.push({0,1});

    pqn.push({0,n});

    while (!pq1.empty())
    {
        pl curr = pq1.top();
        pq1.pop();

        ll curr_node = curr.second;
        ll curr_dist = curr.first;

        if (curr_dist > dist1[curr_node]) continue; // already found a better path

        for (auto [neigh,cost] : graph[curr_node])
        {
            ll next_node = neigh;
            ll next_dist = dist1[next_node];

            if (next_dist > curr_dist + cost)
            {
                dist1[next_node] = curr_dist + cost;
                pq1.push({dist1[next_node], next_node});
            }
        }
    }

    while (!pqn.empty())
    {
        pl curr = pqn.top();
        pqn.pop();

        ll curr_node = curr.second;
        ll curr_dist = curr.first;

        if (curr_dist > distn[curr_node]) continue; // this is important to avoid processing a node again with a higher distance

        for (auto [neigh,cost] : graphrev[curr_node])
        {
            ll next_node = neigh;
            ll next_dist = distn[next_node];

            if (next_dist > curr_dist + cost)
            {
                distn[next_node] = curr_dist + cost;
                pqn.push({distn[next_node], next_node});
            }
        }
    }

    ll ans = 1e18;

    for (auto e : edges)
    {
        // debug
        ll u = e.first;
        ll v = e.second.first;
        ll cost = e.second.second;
        // cout<<"u: "<<u<<" v: "<<v<<" dist1[u]: "<<dist1[u]<<" distn[v]: "<<distn[v]<<" cost: "<<graph[u][v].second<<endl;
        ans = min(ans, dist1[u] + distn[v] + cost / 2);
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
    // cin>>t;
 
    while(t--)
    {
        solve();
    }
}
