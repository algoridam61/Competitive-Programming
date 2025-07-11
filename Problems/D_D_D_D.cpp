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

void solve()
{
    ll n,m,l;cin>>n>>m>>l;

    vl a(l);read(a);
    
    vvl graph(n+1);
    f(i,m)
    {
        ll x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vl distances_odd(n+1); 
    vl distances_even(n+1);

    // distances_odd store the shortest walk from 1 to i of odd lenght
    // distances_even store the shortest walk from 1 to i of even lenght


    for (ll i = 0; i <= n; ++i) {
        distances_odd[i] = LLONG_MAX;
        distances_even[i] = LLONG_MAX;
    }

    queue<pair<ll, ll>> q; // Stores {node, current_path_length_from_source_1}

    // Node 1 is the source. The path length to itself is 0 (even).
    if (n >= 1) { // Check if node 1 is a valid node
        distances_even[1] = 0;
        q.push({1, 0}); // Push {node, distance}
    }

    while (!q.empty()) {
        pair<ll, ll> current = q.front();
        q.pop();
        ll u = current.first;
        ll d_u = current.second; 

        if (d_u % 2 == 0 && d_u > distances_even[u]) {
            continue;
        }
        if (d_u % 2 != 0 && d_u > distances_odd[u]) {
            continue;
        }

        for (ll v : graph[u]) {
            ll new_dist_to_v = d_u + 1;

            if (new_dist_to_v % 2 != 0) { 
                if (new_dist_to_v < distances_odd[v]) {
                    distances_odd[v] = new_dist_to_v;
                    q.push({v, new_dist_to_v});
                }
            } else { 
                if (new_dist_to_v < distances_even[v]) {
                    distances_even[v] = new_dist_to_v;
                    q.push({v, new_dist_to_v});
                }
            }
        }
    }    
    
    

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<distances[i][0]<<" ";
    //     if (distances[i].size() > 1)
    //     {
    //         cout<<distances[i][1]<<" ";
    //     }
    //     L;
    // }
    
    // L;

    ll sum = 0;
    f(i,l)
    {
        sum += a[i];
    }
    ll largest_odd = LLONG_MIN;
    ll largest_even = LLONG_MIN;

    if (sum%2 == 0)
    {
        largest_even = sum;
    }
    else
    {
        largest_odd = sum;
    }

    sortall(a);
    if (largest_even == LLONG_MIN)
    {
        f(i,l)
        {
            if (a[i] % 2 == 1)
            {
                largest_even = sum - a[i];
                break;
            }
        }
    }
    else 
    {
        f(i,l)
        {
            if (a[i] % 2 == 1)
            {
                largest_odd = sum - a[i];
                break;
            }
        }
    }

    // cout<<largest_even<<" "<<largest_odd<<endl;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1) cout<<1;
        else 
        {
            // sortall(distances[i]);
            // ll shortest_odd = LLONG_MAX;
            // ll shortest_even = LLONG_MAX;
            // f(j,distances[i].size())
            // {
            //     if (distances[i][j] % 2 == 0)
            //     {
            //         shortest_even = distances[i][j];
            //         break;
            //     }
            // }
            // f(j,distances[i].size())
            // {
            //     if (distances[i][j] % 2 == 1)
            //     {
            //         shortest_odd = distances[i][j];
            //         break;
            //     }
            // }

            if (largest_even >= distances_even[i] || largest_odd >= distances_odd[i])
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }

        }
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
    cin>>t;
 
    while(t--)
    {
        solve();
    }
}
