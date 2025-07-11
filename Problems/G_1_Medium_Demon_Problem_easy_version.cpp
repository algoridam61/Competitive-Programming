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

void dfs(int node, int parent, const vector<vector<int>>& graph, vector<int>& visited, set<int>& cycleNodes) {
    visited[node] = 1; // Mark node as visiting

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue; // Ignore the edge to the parent

        if (visited[neighbor] == 0) {
            // If neighbor is unvisited, continue DFS
            dfs(neighbor, node, graph, visited, cycleNodes);
        } else if (visited[neighbor] == 1) {
            // Back edge found, mark nodes as part of a cycle
            cycleNodes.insert(node);
            cycleNodes.insert(neighbor);
        }
    }

    visited[node] = 2; // Mark node as fully processed
}

set<int> findCycleNodes(const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of nodes
    vector<int> visited(n, 0); // 0 = unvisited, 1 = visiting, 2 = fully visited
    set<int> cycleNodes;

    // Run DFS from every unvisited node
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, -1, graph, visited, cycleNodes);
        }
    }

    return cycleNodes;
}

void solve()
{
    int n;cin>>n;
    vi r(n);read(r);

    int ans = 0;
    vvi graph(n);

    f(i,n)
    {
        graph[i].push_back(r[i]-1);
    }

    vi indeg(n,0);
    vi zeroindegs;

    f(i,n)
    {
        indeg[r[i]-1]++;
    }

    f(i,n)
    {
        if (indeg[i]==0) zeroindegs.push_back(i);
    }

    while (!zeroindegs.empty())
    {
        vi newindegs;
        for (int i:zeroindegs)
        {
            indeg[r[i]-1]--;
            if (indeg[r[i]-1]==0) newindegs.push_back(r[i]-1);
        }
        ans++;
        zeroindegs = newindegs;
    }
    cout<<ans+2;L;

    
 
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