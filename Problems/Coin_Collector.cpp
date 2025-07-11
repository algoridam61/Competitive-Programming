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
	/* SCC from BenQ */
#define pb push_back
#define all(x) x.begin(), x.end()
#define trav(x, a) for (auto &x : a)
#define rsz resize

struct SCC {
	int N;
	vvi graph, rgraph;
	vi todo, comps, comp;
	vector<bool> vis;
	void init(int _N) {
		N = _N;
		graph.rsz(N), rgraph.rsz(N), comp = vi(N, -1), vis.rsz(N);
	}
    
	void add_edge(int x, int y) { graph[x].pb(y), rgraph[y].pb(x); }

	void dfs(int x) {
		vis[x] = 1;
		for (auto neigh : graph[x]) {
            if (!vis[neigh]) dfs(neigh);
        }
		todo.pb(x);
	}

	void dfs2(int x, int v) {
		comp[x] = v;
        for (auto neigh : rgraph[x]) {
            if (comp[neigh] == -1) dfs2(neigh, v);
        }
	}

	void gen(int _N) {
		f(i, _N) if (!vis[i]) dfs(i);
		reverse(all(todo));
		trav(x, todo) if (comp[x] == -1) {
			dfs2(x, x);
			comps.pb(x);
		}
	}
};

vl dp(200005,-1);

ll solve_dp(int i, vvl& comp_graph, vl& value_comp) {
    if (dp[i] != -1) return dp[i]; 

    ll sum = value_comp[i];
    
    for (auto neigh : comp_graph[i]) {
        sum = max(sum, value_comp[i] + solve_dp(neigh, comp_graph, value_comp));
        // sum %= MOD;
    }

    return dp[i] = sum;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi coins(n); 
    f(i, n) {
        cin >> coins[i];
    }

    SCC scc;
    scc.init(n);
    f(i, m) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        scc.add_edge(u,v);
    }

    scc.gen(n);

    // cout<<scc.comps.size();L;
    // out(scc.comp);

    vvl scc_graph(n);
    vl value_comp(n,0);

    f(i,n) {
        value_comp[scc.comp[i]] += coins[i];
        // value_comp[scc.comp[i]] %= MOD;
    }

    f(i,n) {
        for (auto neigh : scc.graph[i]) {
            if (scc.comp[i] == scc.comp[neigh]) continue;
            scc_graph[scc.comp[i]].push_back(scc.comp[neigh]);
        }
    }

    // out(value_comp);

    ll ans = 0;

    

    f(i,n) {
        ans = max(ans, solve_dp(i,scc_graph,value_comp));
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t=1;
    // cin>>t;
 
    while(t--) {
        solve();
    }
}
