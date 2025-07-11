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
#define sp cout<<" ";
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

void solve()
{
    ll n;cin>>n;

    ll s1,s2;cin>>s1>>s2;
    s1--;s2--;

    ll m1;cin>>m1;
    vvl graph1(n);
    vpl edges1;
    f(i,m1)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        edges1.push_back({x,y});
        graph1[x].push_back(y);
        graph1[y].push_back(x);
    }

    ll m2;cin>>m2;
    vvl graph2(n);
    vpl edges2;
    f(i,m2)
    {
        ll x,y;
        cin>>x>>y;
        x--;y--;
        edges2.push_back({x,y});
        graph2[x].push_back(y);
        graph2[y].push_back(x);
    }
    
    set<pl> goodnodes;

    f(i,m1)
    {
        pl curr = edges1[i];
        f(j,m2)
        {
            pl curr2 = edges2[j];
            if ((curr.first==curr2.first && curr.second==curr2.second)||(curr.first==curr2.second && curr.second==curr2.first))
            {
                goodnodes.insert({curr.first,curr.first});
                goodnodes.insert({curr.second,curr.second});
            }
        }
    }

    // apply dijkstra on the combined graph.

    ll ans = LLONG_MAX;

    vvl dist(n,vl(n,LLONG_MAX));
    dist[s1][s2] = 0;
    
    priority_queue<pair<ll,pl>,vector<pair<ll,pl>>,greater<pair<ll,pl>>> pq;
    pq.push({0,{s1,s2}});

    // whenever we encounter a good node, we will update the answer.

    while (!pq.empty())
    {
        pair<ll,pl> curr = pq.top();
        pq.pop();

        ll d = curr.first;
        pl node = curr.second;

        if (dist[node.first][node.second]<d) continue;

        // use binary search to find the good nodes.

        // if (find(goodnodes.begin(),goodnodes.end(),node)!=goodnodes.end())
        // {
        //     ans = min(ans,d);
        // }

        // go over the neighbors of the current node

        for (auto x:graph1[node.first])
        {
            for (auto y:graph2[node.second])
            {
                pl next = {x,y};
                ll w = abs(x-y);

                if (dist[next.first][next.second]>d+w)
                {
                    dist[next.first][next.second] = d+w;
                    pq.push({d+w,next});
                }
            }
        }
    }

    f(i,n)
    {
        f(j,n)
        {
            if (goodnodes.find({i,j})!=goodnodes.end())
            {
                ans = min(ans,dist[i][j]);
            }
        }
    }

    if (ans==LLONG_MAX) cout<<-1;
    else cout<<ans;
    // cout<<ans;L;return;
    L;return;

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
