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

template <class T> class BIT 
{
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, int val) { add(ind, val - arr[ind]); }

	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

ll power(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
ll modInverse(ll n, ll mod = MOD) {
    return power(n, mod - 2);
}

ll calculate_nCr_mod_p(int n_val, int r_val, ll mod = MOD) {
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
        res = (res * (n_val - i)) % mod;
        res = (res * modInverse(i + 1)) % mod;
    }
    return res;
}

struct DisjointSet {
    vector<ll> parent, size;
    ll num_components;

    DisjointSet(ll n) : parent(n + 1), size(n + 1, 1), num_components(n) {
        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void union_sets(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
            num_components--;
        }
    }
};
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
    ll n;cin>>n;
    
    vvl graph(n+1);
    vpl edges;
    f(i,n-1) {
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u,v});
    }

    // find the diameter of the tree
    if (n == 2) {
        cout<<0;L;
        return;
    }

    if (n == 3) {
        cout<<0;L;
        cout<<1;L;return;
    }

    // find the two opposite ends of the diameter
    // make one of the edge 0, other end to be 1
    // try to make 2 not a part of the diameter, rest all randomly

    vl dist(n + 1, -1);
    dist[1] = 0;
    queue<ll> q;
    q.push(1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    ll farthest_node = 1;
    ll max_dist = -1;
    f1(i,1,n+1) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_node = i;
        }
    }

    q.push(farthest_node);
    vl parent(n + 1, -1);

    dist.assign(n + 1, -1);

    dist[farthest_node] = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }


    ll other_end = 1;
    max_dist = -1;
    f1(i,1,n+1) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            other_end = i;
        }
    }
    // vl answers;
    vl parent_path(n+1,-1);
    ll current = other_end;
    while (current != -1) {
        parent_path[current] = parent[current];
        current = parent[current];
    }
    ll counter = 3;
    bool inserted_2 = false;
    // cout<<other_end<<" "<<farthest_node;L;
    for (auto& edge : edges) {
        ll u = edge.first;
        ll v = edge.second;

        if ((u == farthest_node && parent_path[v] == u) || (v == farthest_node && parent_path[u] == v)) {
            cout<<0;L; continue;
        } else if  ((u == other_end && parent_path[u] == v) || (v == other_end && parent_path[v] == u)) {
            cout<<1;L; continue;
        } 

        if (parent_path[u] != v && parent_path[v] != u && !inserted_2) {
            cout<<2;L;inserted_2 = true; continue;
        }
        if (counter >= n-1) {
            cout<<2;L;
            continue;
        }

        cout<<counter;L;
        counter++;

        
        
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;
    // cin>>t;
 
    while(t--) {
        solve();
    }
}
