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
void solve()
{
    ll n;cin>>n;
    ll m;cin>>m;
    
    vector<string> input(n);

    f(i,n)
    {
        cin>>input[i];
    }

    ll start_x;
    ll start_y;

    ll end_x;
    ll end_y;

    f(i,n)
    {
        f(j,m)
        {
            if (input[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            else if (input[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<pl> q;

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    dist[start_x][start_y] = 0;
    map<pl,pl> parents;
    parents[{start_x, start_y}] = {-1, -1}; 

    while (!q.empty())
    {
        pl curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (abs(dx) + abs(dy) == 1) 
                {
                    int new_x = x + dx;
                    int new_y = y + dy;

                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && 
                        input[new_x][new_y] != '#' && !visited[new_x][new_y])
                    {
                        visited[new_x][new_y] = true;
                        dist[new_x][new_y] = dist[x][y] + 1;
                        parents[{new_x, new_y}] = {x, y};
                        q.push({new_x, new_y});
                    }
                }
            }
        }
    }

    if (dist[end_x][end_y] == INT_MAX)
    {
        no
    }
    else 
    {
        cout<<"YES";L;
        cout<<dist[end_x][end_y];L;
        vpl path;
        ll currx = end_x;
        ll curry = end_y;

        while (currx != -1 && curry != -1)
        {
            path.push_back({currx, curry});
            pl parent = parents[{currx, curry}];
            currx = parent.first;
            curry = parent.second;
        }

        for (int i = path.size() - 1;i >= 1;i--)
        {
            ll currx = path[i].first;
            ll curry = path[i].second;

            ll nextx = path[i-1].first;
            ll nexty = path[i-1].second;

            if (currx > nextx) cout<<"U";
            else if (currx < nextx) cout<<"D";
            else if (curry > nexty) cout<<"L";
            else cout<<"R";
        }
        L;
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
