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
vl node_color(100001, -1);
vvl graph(100001);
int colored = 0;
vl visited(100001, 0);
void dfs(pl node)
{

    ll u = node.first;
    ll color = node.second;
    if (visited[u])
        return; // If already visited, return
    visited[u] = 1; // Mark the node as visited
    // colored++;
    for (auto v : graph[u])
    {
        if (node_color[v] == -1)
        {
            node_color[v] = 1 - color; // Alternate color
            // colored++;
            dfs({v, node_color[v]});
        }
        else if (node_color[v] == color)
        {
            cout << "IMPOSSIBLE"; L;
            exit(0);
        }
    }
}
void solve()
{
    ll n;cin>>n;
    ll m;cin>>m;

    f(i,m)
    {
        ll u,v;cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // node_color[1] = 0; // Start coloring from node 1 with color 0
    f1(i, 1, n + 1)
    {
        if (node_color[i] == -1) // If the node is not colored
        {
            node_color[i] = 0; // Color it with color 0
            dfs({i, node_color[i]}); // Start DFS from this node
        }
    }

    f1(i,1,n+1)
    {
        cout<<node_color[i] + 1<<" "; // Output colors as 1 or 2
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
