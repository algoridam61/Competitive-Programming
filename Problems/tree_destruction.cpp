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
#define read(a) f(i,n) cin>>a[i];

const ll MOD = 1000000007;
 
using namespace std;

bool checkpresent(vi sorted_vector, int target)
{
int n=size(sorted_vector);
int l=0;int h=n-1;
while(l<=h)
{
    int mid=(l+h)/2;
    if (sorted_vector[mid]==target)
    {return true;}
    else if (sorted_vector[mid]>target)
    {
        l=mid;
    }
    else h=mid;
}
return false;

}
 
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
void bfs(int start, const vvi &graph, vi &dist, const vi &indeg) {
    // Max-heap: prioritize nodes with maximum distance
    priority_queue<pi> q;
    vector<bool> visited(graph.size(), false); // Track visited nodes

    q.push({indeg[start], start});
    dist[start] = indeg[start];
    visited[start] = true;

    while (!q.empty()) {
        pi curr = q.top();
        q.pop();

        int curr_dist = curr.first;   // Maximum distance so far
        int curr_node = curr.second; // Current node

        for (int neigh : graph[curr_node]) {
            if (!visited[neigh]) { // Process only unvisited neighbors
                visited[neigh] = true;
                int new_dist = curr_dist -2 + indeg[neigh];
                dist[neigh] = new_dist;
                q.push({new_dist, neigh});
            }
        }
    }
}

void solve()
{
    int n;cin>>n;
    vvi graph(n);
    vi indeg(n,0);
    f(i,n-1)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        indeg[u]++;
        indeg[v]++;
    }

    vi dist1(n,0);
    bfs(0,graph,dist1,indeg);
    // cout<<"u";
    // cout<<dist1[0]<<" "<<dist1[1];L;
    int maxi = 0;
    int maxv = 0;
    f(i,n)
    {
        if (dist1[i]>maxv)
        {
            maxv = dist1[i];maxi = i;
        }
    }

    // vi maxis;

    // f(i,n)
    // {
    //     // cout<<dist1[i]<<" ";
    //     if (dist1[i]==maxv) maxis.push_back(i);
    // }
    // L;
    
    int ans = 0;
    
    vi dist2(n,0);
    bfs(maxi,graph,dist2,indeg);

    // int curr = 0;
    f(i,n)
    {
        ans = max(ans,dist2[i]);
    }
    
    f(i,n)
    {
        ans = max(ans,indeg[i]);
    }
    cout<<ans;L;
 
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