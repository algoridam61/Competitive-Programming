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
    ll n;cin>>n;ll m;cin>>m;
    ll k;cin>>k;
    
    vl a(n);read(a);
    vl b(m);read(b);

    vpl factors;
    for (ll i = 1; i*i <= k; i++) {
        if (k % i == 0) {
            factors.push_back({i, k / i});
            if (i != k / i) {
                factors.push_back({k / i, i});
            }
        }
    }

    vl a_groups;
    vl b_groups;
    int i = 0;
    ll curr_len = 0;
    while (i < n) {
        if (a[i] == 0) {
            if (curr_len > 0) {
                a_groups.push_back(curr_len);
                curr_len = 0;
            }
        } else {
            curr_len++;
        }
        i++;
    }
    if (curr_len > 0) {
        a_groups.push_back(curr_len);
    }
    i = 0;
    curr_len = 0;
    while (i < m) {
        if (b[i] == 0) {
            if (curr_len > 0) {
                b_groups.push_back(curr_len);
                curr_len = 0;
            }
        }
        else {
            curr_len++;
        }
        i++;
    }

    if (curr_len > 0) {
        b_groups.push_back(curr_len);
    }

    sortall(a_groups);
    sortall(b_groups);
    // out(b);
    // out(a_groups);
    // out(b_groups);
    if (a_groups.size() == 0 || b_groups.size() == 0) {
        cout<<0<<"\n";
        return;
    }

    vl pref_a(a_groups.size(),0);
    vl pref_b(b_groups.size(),0);
    pref_a[0] = a_groups[0];
    pref_b[0] = b_groups[0];

    f1(i,1,a_groups.size()) {
        pref_a[i] = pref_a[i-1] + a_groups[i];
    }
    f1(i,1,b_groups.size()) {
        pref_b[i] = pref_b[i-1] + b_groups[i];
    }
    ll ans = 0;
    for (auto &factor : factors) {
        ll x = factor.first;
        ll y = factor.second;

        ll a_count = 0;
        ll b_count = 0;

        // find number of blocks greater than or equal to x. 
        ll a_idx = -1;
        int left = 0;
        int right = a_groups.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a_groups[mid] >= x) {
                a_idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (a_idx == -1) continue;
        a_count = pref_a[a_groups.size() - 1] - (a_idx > 0 ? pref_a[a_idx - 1] : 0) - (x-1)*(a_groups.size() - a_idx);

        // find number of blocks greater than or equal to y.
        int b_idx = -1;
        left = 0;
        right = b_groups.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (b_groups[mid] >= y) {
                b_idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (b_idx == -1) continue;
        b_count = pref_b[b_groups.size() - 1] - (b_idx > 0 ? pref_b[b_idx - 1] : 0) - (y-1)*(b_groups.size() - b_idx);
        // debug
        // cout<<x<<" "<<y<<" "<<a_count<<" "<<b_count<<"\n";
        ans = (ans + a_count * b_count);
    }
    cout<<ans<<"\n";
    return;
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
