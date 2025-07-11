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

void dfs(int node, int parent, vvi& graph, vi& heights)
{
    for (int neigh : graph[node])
    {
        if (neigh != parent)
        {
            heights[neigh] = 1 + heights[node];
            dfs(neigh, node, graph, heights);
        }
    }
}

int dfs2(int  node, int parent, vvi& graph, vi& maxheights, vi& heights)
{
    int ans = heights[node];
    for (int neigh : graph[node])
    {
        if (neigh != parent)
        {
            ans = max(ans,dfs2(neigh, node, graph, maxheights, heights));
        }
    }
    return maxheights[node] = ans;
    // return ans;
}

void solve() {
    int n;
    cin >> n;
    vvi graph(n);
    vpi edges(n-1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v; // Convert 1-based to 0-based
        edges[i].first = u;edges[i].second = v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vi heights(n,0);
    dfs(0,-1,graph,heights);
    vi maxheights(n,0);
    dfs2(0,-1,graph,maxheights,heights);
    // f(i,n-1)
    // {
    //     int u = edges[i].first; 
    //     int v = edges[i].second;
    //     if (u!=0&&v!=0)
    //     {
    //         maxheights[u] = max(maxheights[u],maxheights[v]);
    //         maxheights[v] = max(maxheights[u],maxheights[v]);
    //     }

    // }
    int maxh = maxheights[0];
    vi pre(maxh+1,0);
    // pre[i] stores number of nodes having height greater than equal to i
    f(i,n)
    {
        pre[heights[i]]++;
    }
    for (int i = maxh-1;i>=0;i--)
    {
        pre[i] = pre[i] + pre[i+1];
    }
    vi prem(maxh+1,0);
    // stores number of nodes having max heights less equal than i
    f(i,n)
    {
        prem[maxheights[i]]++;
    }
    f1(i,1,maxh+1)
    {
        prem[i] = prem[i] + prem[i-1];
    }
    int ans = INT_MAX;
    // f(i,maxh+1)
    // {
    //     cout<<"H: "<<i<<"Number: "<<prem[i];L;
    // }
    f(i,maxh+1)
    {
        if (i==0) ans = min(ans,pre[i+1]);
        else if (i==maxh) ans = min(ans,prem[i-1]);
        else ans = min(ans, pre[i+1]+prem[i-1]);
    }
    // f(i,maxh+1)
    // {
    //     if (i==0) {cout<<pre[i+1];L;}
    //     else if (i==maxh) {cout<<prem[i-1];L;}
    //     else {cout<<pre[i+1]+prem[i-1];L;}
    // }
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