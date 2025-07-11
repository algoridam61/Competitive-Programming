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
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // if pt1 and pt2 lie on different sides of line segment pt3-pt4
    // and pt3 and pt4 lie on different sides of line segment pt1-pt2
    auto side = [](ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
        return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    };

    ll d1 = side(x3, y3, x4, y4, x1, y1);
    ll d2 = side(x3, y3, x4, y4, x2, y2);
    ll d3 = side(x1, y1, x2, y2, x3, y3);
    ll d4 = side(x1, y1, x2, y2, x4, y4);
    // cout<< d1 << " " << d2 << " " << d3 << " " << d4 << "\n";
    if (d1 < 0 && d2 > 0 || d1 > 0 && d2 < 0) {
        if (d3 < 0 && d4 > 0 || d3 > 0 && d4 < 0) {
            cout << "YES\n";
            return;
        }
    }
    // cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<"\n";
    if (d1 == 0) {
        if (d2 == 0) {
            // both lines are collinear
            // check if they overlap
            if (min(x3, x4) <= max(x1, x2) &&
                min(y3, y4) <= max(y1, y2) &&
                min(x1, x2) <= max(x3, x4) &&
                min(y1, y2) <= max(y3, y4)) yes 
            else no
        } else {
            // check if pt1 lies on line segment pt3-pt4
            if (max(x3, x4) >= x1 && min(x3, x4) <= x1 &&
                max(y3, y4) >= y1 && min(y3, y4) <= y1) {
                yes
            } 
        }
    } else {
        if (d2 == 0) {
            if (max(x3, x4) >= x2 && min(x3, x4) <= x2 &&
                max(y3, y4) >= y2 && min(y3, y4) <= y2) {
                yes
            } else {
                no
            }
        }
    }

    if (d3 == 0) {
        if (d4 == 0) {
            // both lines are collinear
            // check if they overlap
            if (min(x1, x2) <= max(x3, x4) &&
                min(y1, y2) <= max(y3, y4) &&
                min(x3, x4) <= max(x1, x2) &&
                min(y3, y4) <= max(y1, y2)) yes 
            else no
        } else {
            // check if pt3 lies on line segment pt1-pt2
            if (max(x1, x2) >= x3 && min(x1, x2) <= x3 &&
                max(y1, y2) >= y3 && min(y1, y2) <= y3) {
                yes
            } else {
                no
            }
        }
    } else {
        if (d4 == 0) {
            if (max(x1, x2) >= x4 && min(x1, x2) <= x4 &&
                max(y1, y2) >= y4 && min(y1, y2) <= y4) {
                yes
            } else {
                no
            }
        } else {
            no
        }
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
    cin>>t;
 
    while(t--) {
        solve();
    }
}
