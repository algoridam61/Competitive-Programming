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
void solve() {
    ll n, m;
    cin >> n >> m;

    vvpl graph(n + 1);
    f(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vl dist(n + 1, LLONG_MAX);
    dist[1] = 0;  // MUST initialize this

    vl min_paths(n + 1, 0);
    min_paths[1] = 1;

    vl max_edges_path(n + 1, 0);
    vl min_edges_path(n + 1, 0);  // Initialize to 0, not LLONG_MAX
    
    // No need for visited array - let Dijkstra's natural pruning work
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;  // This replaces the visited array

        for (auto& edge : graph[node]) {
            ll next_node = edge.first;
            ll weight = edge.second;
            ll new_dist = d + weight;

            if (dist[next_node] > new_dist) {
                dist[next_node] = new_dist;
                min_paths[next_node] = min_paths[node];
                min_edges_path[next_node] = min_edges_path[node] + 1;
                max_edges_path[next_node] = max_edges_path[node] + 1;
                pq.push({new_dist, next_node});
            } else if (dist[next_node] == new_dist) {
                min_paths[next_node] = (min_paths[next_node] + min_paths[node]) % MOD;
                min_edges_path[next_node] = min(min_edges_path[next_node], min_edges_path[node] + 1);
                max_edges_path[next_node] = max(max_edges_path[next_node], max_edges_path[node] + 1);
                // No push needed here
            }
        }
    }

    cout << dist[n] << " " << min_paths[n] << " " << min_edges_path[n] << " " << max_edges_path[n] << "\n";
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
