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
class lca {
public:
    vector<vector<ll>> ancestors;
    vector<ll> depth;
    ll log_n;
    ll n;

    lca(const vvl& graph, ll root, ll n) {
        this->n = n;
        log_n = 0;
        while ((1LL << log_n) <= n) log_n++;
        ancestors.assign(n + 1, vector<ll>(log_n, -1));
        depth.assign(n + 1, 0);
        fill_depth_and_ancestors(graph, root, 0, -1);
    }

    void fill_depth_and_ancestors(const vvl& graph, ll node, ll d, ll parent) {
        depth[node] = d;
        ancestors[node][0] = parent;

        for (ll i = 1; i < log_n; i++) {
            if (ancestors[node][i - 1] != -1) {
                ancestors[node][i] = ancestors[ancestors[node][i - 1]][i - 1];
            }
        }

        for (ll neighbor : graph[node]) {
            if (neighbor != parent) {
                fill_depth_and_ancestors(graph, neighbor, d + 1, node);
            }
        }
    }

    ll get_kth_ancestor(ll node, ll k) {
        for (ll i = 0; i < log_n && node != -1; i++) {
            if (k & (1LL << i)) {
                node = ancestors[node][i];
            }
        }
        return node;
    }

    ll lca_node(ll u, ll v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = get_kth_ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (ll i = log_n - 1; i >= 0; i--) {
            if (ancestors[u][i] != -1 && ancestors[u][i] != ancestors[v][i]) {
                u = ancestors[u][i];
                v = ancestors[v][i];
            }
        }
        return ancestors[u][0];
    }
};


void solve() {
    ll n;cin>>n;
    ll m;cin>>m;

    vvl graph(n + 1);
    f(i, n-1) {
        ll u, v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vpl paths(m);
    f(i, m) {
        ll u, v;cin>>u>>v;
        paths[i] = {u, v};  
    }

    vl val(n+1, 0);

    lca lca_tree(graph, 1, n);

    for (auto &p : paths) {
        ll u = p.first;
        ll v = p.second;
        val[u]++;
        val[v]++;
        ll lca = lca_tree.lca_node(u, v);
        
        val[lca]--;
        if (lca != 1) {
            val[lca_tree.get_kth_ancestor(lca, 1)]--;
        }
    }
 
    vl subtree_sum(n + 1, 0);
    function<void(ll, ll)> dfs = [&](ll node, ll parent) {
        subtree_sum[node] = val[node];
        for (ll neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node);
                subtree_sum[node] += subtree_sum[neighbor];
            }
        }
    };
    dfs(1, -1);

    f1(i, 1, n + 1) {
        cout << subtree_sum[i] << " ";
    }
    cout << "\n";


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
